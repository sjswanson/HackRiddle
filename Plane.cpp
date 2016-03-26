#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Plane {
	string name;
	int fuel;
	int turnsSurvived;
	bool alive;
	int level;
	public:
		Plane(string playerName) {name=playerName;alive=true;turnsSurvived=0;level=0;};
		void nextTurn();
		bool getStatus() {return alive;};
		string getName() {return name;};
		int getTurns() {return turnsSurvived;};
		void die() {alive=false;};
		void setFuel(int newFuel) {fuel=newFuel;};
		int getFuel() {return fuel;};
		int getLevel() {return level;};
		bool getAlive() {return alive;};
		void setLevel(int newLevel) {level=newLevel;};
};

void Plane::nextTurn() {
	turnsSurvived++;
	if (fuel==2) {
		fuel-=2;
	}
	else {
		fuel--;
	}
}

class Event {
	int likelyIndex;
	int death;
	string description;
	int fuelEffect;
	int fuelLikely;
	Plane plane;
	public:
		Event(int likely,int survival,string describe,int fuelChange,int doesFuelChange);
		void causeEffect();
		void setPlane(Plane newPlane) {plane=newPlane;};
};

Event::Event(int likely,int survival,string describe,int fuelChange,int doesFuelChange) {
	likelyIndex=likely;
	death=survival;
	description=describe;
	fuelEffect=fuelChange;
	fuelLikely=doesFuelChange;
}

void Event::causeEffect() {
	srand(time(NULL));
	if (rand()%100<death) {
		plane.die();
	}
	else {
		if (rand()%100<fuelLikely) {
			plane.setFuel(plane.getFuel()+fuelEffect);
		}
	}
	
}

int main() {
	cout<<"Welcome to Embry Riddle Aeronautical Boot Camp for Trying to Fly a Plane"<<endl;
	cout<<"Enter your name: ";
	string playerInput;
	cin>>playerInput;
	Plane play=new Plane(playerInput);
	Event meh=new Event(100,50,"Meh",-10,80);
	meh.setPlane(play);
	while (play.getAlive()) {
		play.nextTurn();
		meh.causeEffect();
	}
	cout<<"RIP your flying abilities"<<endl;
}