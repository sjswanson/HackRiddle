#include <iostream>
#include <string>

using namespace std;

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
		bool getAlive() {return alive;};
}

public Plane() {
	cout<<"Enter your name: ";
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

int main() {
	cout<<"Welcome to Embry Riddle Aeronautical Boot Camp for Trying to Fly a Plane"<<endl;
	Plane play=new Plane();
	while (play.getAlive()) {
		play.nextTurn();
		//determine event things and change fuel and stuff
	}
	cout<<"Congrats you died"<<endl;
}