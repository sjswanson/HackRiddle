#include <iostream>
#include <string>

class Plane {
	const string name;
	int fuel;
	int turnsSurvived;
	bool alive;
	public:
		Plane();
		void nextTurn();
		bool getStatus() {return alive;};
		string getName() {return name;};
		int getTurns() {return turnsSurvived;};
		void die() {alive=dead;};
		void setFuel(int newFuel) {fuel=newFuel;};
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
	fuel--;
}