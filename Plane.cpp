#include <iostream>
#include <string>

class Plane {
	const string name;
	int fuel;
	int turnsSurvived;
	bool alive;
	int level;
	public:
		Plane();
		void nextTurn();
		bool getStatus() {return alive;};
		string getName() {return name;};
		int getTurns() {return turnsSurvived;};
		void die() {alive=false;};
		void setFuel(int newFuel) {fuel=newFuel;};
		int getLevel() {return level;};
}

public Plane() {
	cout<<"Enter a name for your plane: ";
	string playerInput;
	cin>>playerInput;
	name=playerInput;
	alive=true; 
	turnsSurvived=0;
	level=0;
}

public void Plane::nextTurn() {
	turnsSurvived++;
	if (fuel==2) {
		fuel-=2;
	}
	else {
		fuel--;
	}
}