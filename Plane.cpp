#include <iostream>
#include <string>

class Plane {
	const string name;
	int fuel;
	int turnsSurvived;
	bool alive;
	bool inSpace;
	public:
		Plane();
		void nextTurn();
		bool getStatus() {return alive;};
		string getName() {return name;};
		int getTurns() {return turnsSurvived;};
		void die() {alive=dead;};
		void setFuel(int newFuel) {fuel=newFuel;};
		bool getInSpace() {return inSpace;};
}

public Plane() {
	cout<<"Enter a name for your plane: ";
	string playerInput;
	cin>>playerInput;
	name=playerInput;
	alive=true; 
	turnsSurvived=0;
}

public void Plane::nextTurn() {
	turnsSurvived++;
	if (getInSpace) {
		fuel-=2;
	}
	else {
		fuel--;
	}
}