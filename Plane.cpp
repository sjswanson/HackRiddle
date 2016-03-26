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
		Plane() {};
		void setName(string playerName) {name = playerName;};
		void setAlive(bool doa){alive = doa;};
		void nextTurn();
		string getName() {return name;};
		void setTurns() {turnsSurvived = 0;};
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
	Plane lePlane;
	public:
		Event(int, int, string, int, int, Plane);
		void causeEffect();
};

Event::Event(int likely,int survival,string describe,int fuelChange,int doesFuelChange, Plane newPlane) {
	likelyIndex=likely;
	death=survival;
	description=describe;
	fuelEffect=fuelChange;
	fuelLikely=doesFuelChange;
	lePlane=newPlane;
	
}

void Event::causeEffect() {
	srand(time(NULL));
	if (rand()%100<death) {
		lePlane.die();
	}
	else {
		if (rand()%100<fuelLikely) {
			lePlane.setFuel(lePlane.getFuel()+fuelEffect);
		}
	}
	
}

int main() {
	cout<<"Welcome to Embry Riddle Aeronautical Boot Camp for Trying to Fly a Plane"<<endl;
	cout<<"Enter your name: ";
	string playerInput;
	cin>>playerInput;
	Plane *play=new Plane();
	Event *meh=new Event(100,50,"Meh",-10,80, *play);
	while (play->getAlive()) {
		play->nextTurn();
		meh->causeEffect();
	}
	cout<<"RIP your flying abilities"<<endl;
}