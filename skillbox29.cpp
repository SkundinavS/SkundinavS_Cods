#include <iostream>
#include <vector>]
using namespace std;

class Dog {
	string name;
	vector<Talent*> tals;
	bool isswim, isdance, iscount;
public:
	Dog();
	Dog(string _name) {
		name = _name;
	}
	void AddTalant() {
		while(true) {
			string com;
			cout << "What talent do you want to add" << endl;
			cin >> com;
			if (com == "dance" && isdance) {
				Talent* dan = new Dancing;
				tals.push_back(dan);
			}
			else {
				cout << "This dog already can dance" << endl;
			}
			if (com == "swim" && isswim) {
				Talent* dan = new Swiming;
				tals.push_back(dan);
			}
			else {
				cout << "This dog already can swim" << endl;
			}
			if (com == "count" && iscount) {
				Talent* dan = new Counting;
				tals.push_back(dan);
			}
			else {
				cout << "This dog already can count" << endl;
			}if (com == "stop") {
				break;
			}
		}
	}
	void Show_Talent() {
		for (int i = 0; i < tals.size(); i++) {
			tals[i]->ShowTalent();
		}
	}
};

class Talent {
public:
	Talent();
	virtual void ShowTalent() {
		cout << "Unknown Talent" << endl;
	}
};

class Swiming :public Talent {
public:
	Swiming();
	virtual void ShowTalent() {
		cout << "It can swim" << endl;
	}
};

class Counting :public Talent {
public:
	Counting();
	virtual void ShowTalent() {
		cout << "It can count" << endl;
	}
};

class Dancing :public Talent {
public:
	Dancing();
	virtual void ShowTalent() {
		cout << "It can dancing" << endl;
	}
};

int main() {
	Dog d;
	d.AddTalant();
	d.Show_Talent();
}