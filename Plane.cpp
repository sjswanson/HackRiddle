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
	int death;
	string description;
	int fuelEffect;
	int fuelLikely;
	Plane lePlane;
	public:
		Event(int, string, int, int, Plane);
		void causeEffect();
};

Event::Event(int deathRate,string describe,int fuelChange,int doesFuelChange, Plane newPlane) {
	death=deathRate;
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

void generateEvent(){
	srand(time(NULL));
	if (rand()%100<5){
		string desc = "Your engine has failed";
		int dead = 40;
		int fc = -5;
		int dfc = 20;
	}
	else if(rand()%100<10){
		string desc = "A hostile plane has attacked you";
		int dead = 30;
		int fc = 0;
		int dfc = 0;
	}
	else if(rand()%100<40){
		string desc = "Hey, look, a bird outside the cockpit";
		int dead = 0;
		int fc = 4;
		int dfc = 40;
	}
	else if(rand()%100<70){
		string desc = "Asthma attack";
		int dead = 15;
		int fc = -2;
		int dfc = 50;
	}
	else if(rand()%100<100){
		string desc = "All clear";
		int dead = 0;
		int fc = 1;
		int dfc = 15;
	}
}

int main() {
	cout<<"Welcome to Embry Riddle Aeronautical Boot Camp for Trying to Fly a Plane"<<endl;
	cout<<"Enter your name: ";
	string playerInput;
	cin>>playerInput;
	Plane *play=new Plane();
	Event *meh=new Event(50,"Meh",-10,80, *play);
	while (play->getAlive()) {
		play->nextTurn();
		meh->causeEffect();
	}
	cout<<"RIP your flying abilities"<<endl;
}
