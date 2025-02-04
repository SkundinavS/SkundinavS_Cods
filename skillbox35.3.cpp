#include <filesystem>
#include <iostream>
#include <vector>
using namespace std;
using namespace filesystem;

auto findFile = [](path way, string ex) {
	if (way.extension() == ex) {
		cout << way.stem() << endl;
	}
};

int main()
{
	cout << "Input extension" << endl;
	string ex;
	cin >> ex;
	ex = "." + ex;
	cout << endl;
	for (auto& p : recursive_directory_iterator("C:\\dir")) {
		findFile(p, ex);
	}
}