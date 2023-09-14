#include <iostream>
#include <vector>
using namespace std;

struct banya
{
	int squere = 0;
	int pech = 0;
};

struct level {
	int living_room = 0;
	int kitchen = 0;
	int children_room = 0;
	int bedroom = 0;
	int bath = 0;
	int height = 0;
};

struct house
{
	int pech = 0;
	int square = 0;
	vector<level> levels;
};

struct land
{
	house house1;
	banya banya1;
	int sarai = 0;
	int garage = 0;
};

int main()
{
	vector<land> snt(20);
	cout << "How much plots in village" << endl;
	int plots = 0;
	cin >> plots;
	for (int i = 0; i < plots; i++) {
		cout << "Input house square:";
		int house_square = 0;
		cin >> house_square;
		snt[i].house1.square = house_square;
		cout << "Input banya, saray and garage squares" << endl;
		int banya, saray, garage;
		cin >> banya >> saray >> garage;
		snt[i].banya1.squere = banya;
		snt[i].garage = garage;
		snt[i].sarai = saray;
		int pech = 0;
		if (snt[i].banya1.squere != 0) {
			cout << "If pech in banya" << endl;
			cin >> pech;
		}
		snt[i].banya1.pech = pech;
		cout << "How much levels in this house?" << endl;
		int levels;
		cin >> levels;
		for (int j = 0; j < levels; j++) {
			snt[i].house1.levels.emplace_back();
		}
		if (levels < 4) {
			for (int g = 0; g < levels; g++) {
				int liv, kit, chil, bath, bed, height;
				int c = 0;
				cout << "Input level height" << endl;
				cin >> height;
				snt[i].house1.levels[g].height = height;
				cout << "Kitchen" << endl;
				cin >> kit;
				snt[i].house1.levels[g].kitchen = kit;
				if (kit != 0) {
					c++;
				}
				cout << "Living room?" << endl;
				cin >> liv;
				snt[i].house1.levels[g].living_room = liv;
				if (liv != 0) {
					c++;
				}
				cout << "Children room?" << endl;
				cin >> chil;
				snt[i].house1.levels[g].children_room = chil;
				if (chil != 0) {
					c++;
				}
				cout << "Bathroom?" << endl;
				cin >> bath;
				snt[i].house1.levels[g].bath = bath;
				if (bath != 0) {
					c++;
				}
				if (c < 4) {
					cout << "Bedroom?" << endl;
					cin >> bed;
					snt[i].house1.levels[g].bedroom = bed;
				}
			}
		}
		else {
			cout << "Wrong number of levels" << endl;
		}
	}
	for (int i = 0; i < plots; i++) {
		cout << "Plot #" << i + 1 << ":" << endl;
		cout << "House square:" << snt[i].house1.square << endl;
		cout << "Banya square:" << snt[i].banya1.squere << " Pech square:" << snt[i].banya1.pech << endl;
		cout << "Saray square:" << snt[i].sarai << " Garage square:" << snt[i].garage << endl;
		for (int g = 0; g < snt[i].house1.levels.size(); g++) {
			cout << "Level №" << g + 1 << ":" << endl;
			cout << "Living room square:" << snt[i].house1.levels[g].living_room << endl;
			cout << "Kitchen square:" << snt[i].house1.levels[g].kitchen << endl;
			cout << "Bath square:" << snt[i].house1.levels[g].bath << endl;
			cout << "Children room square:" << snt[i].house1.levels[g].children_room << endl;
			cout << "Bedroom square:" << snt[i].house1.levels[g].bedroom << endl;
			cout << "Height:" << snt[i].house1.levels[g].height << endl;
		}
	}
}
