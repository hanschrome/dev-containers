#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <unistd.h>
namespace fs = std::filesystem;
using namespace std;

int main()
{
	string path = "containers";
	vector<string> containers;

	for (const auto & entry : fs::directory_iterator(path)) {
		cout << entry.path() << endl;
		containers.push_back(entry.path());
	}

	vector<string> errors;
	cout << "Building..." << endl;
	for (int i = 0; i < containers.size(); i++) {
		string absolute = fs::absolute(containers[i]);
		string imageName = containers[i].substr(containers[i].find("/")+1);

		cout << imageName + "::" + absolute << endl;

		string commandBuildImages = "cd '" + absolute + "' && docker build . -t " + imageName;
		system(commandBuildImages.c_str());

		string commandBuildContainers = absolute + "/build.sh";
		if (( access( commandBuildContainers.c_str(), F_OK ) != -1 )) {
			system(commandBuildContainers.c_str());
		} else {
			errors.push_back("--\n\tWARNING: No build script for " + imageName + "\n--\n");
		}
	}

	for (int i = 0; i < errors.size(); i++) {
		cout << errors[i];
	}
}
