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
	if (level==2) {
		fuel-=2;
	}
	else {
		fuel--;
	}
	cout << "Fuel remaining: " << fuel << endl;
	if(fuel <= 0){alive = false;}
}

class Event {
	int death;
	string description;
	int fuelEffect;
	int fuelLikely;
	Plane * lePlane;
	public:
		Event(int, string, int, int, Plane*);
		void causeEffect();
};

Event::Event(int deathRate,string describe,int fuelChange,int doesFuelChange, Plane * newPlane) {
	death=deathRate;
	description=describe;
	fuelEffect=fuelChange;
	fuelLikely=doesFuelChange;
	lePlane= newPlane;

}

void Event::causeEffect() {

	cout << description << endl;
	string decision;
	cin >> decision;
	if (decision!="a"&&decision!="A"&&decision!="b"&&decision!="B") {
		cout << "Not a valid choice!!!!" << endl;
		lePlane->die();
		//lePlane->setFuel(-1);
		return;
		//cin>>decision;
	}
	if(decision == "a" || decision == "A")
	{cout << "Good Choice!" << endl;}
	else if (decision == "b" || decision == "B")
	 {cout << "Bad Choice" << endl;}
	if (rand()%100<death) {
		lePlane->die();
	}
	else {
		if (rand()%100<fuelLikely) {
			lePlane->setFuel(lePlane->getFuel()+fuelEffect);
		}
	}

}

Event* generateEvent(Plane* play){

	  int dead =0;
		int fc = 0;
		int dfc = 0;
		string desc ="";
		int randnum = rand()%100;
	if (randnum<1) {
		desc="Your plane has spontaneously disassembled itself";
		fc=0;
		dfc=100;
		dead=100;
	}
	else if (randnum< 5){
		desc = "Your engine has failed";
		dead = 40;
		fc = -5;
		dfc = 20;
	}
	else if(randnum<10){
		desc = "A hostile plane has attacked you";
		dead = 30;
		fc = 0;
		dfc = 0;
	}
	else if(randnum<20){
		desc = "Hey, look, a bird outside the cockpit";
		dead = 0;
		fc = 4;
		dfc = 40;
	}
	else if(randnum<40){
		desc = "Asthma attack";
		dead = 15;
		fc = 0;
		dfc = 0;
	}
	else if (randnum<60) {
		desc="Crying baby";
		dead=2;
		fc=-1;
		dfc=10;
	}
	else if(randnum<100){
		desc = "All clear";
		dead = 0;
	  fc = 1;
		dfc = 15;
	}

	Event* meh=new Event(dead,desc, fc, dfc, play);
	return meh;
};
/*
Event* generateEarth(Plane play) {

}

Event* generateSpace(Plane play) {

}
*/
int main() {
	cout<<"Welcome to Embry Riddle Aeronautical Boot Camp for Trying to Fly a Plane"<<endl;
	cout<<"Enter your name: ";
	srand(time(NULL));
	string playerInput;
	cin>>playerInput;
	Plane* play=new Plane();
	play->setFuel(20);
	play->setAlive(true);
	play->setLevel(1);
	while (play->getAlive()) {
		/*
		if (play->getLevel()==1) {
			Event* meh=generateEarth(*play);
		}
		else {
			Event* meh=generateSpace(*play);
		}
		*/
		Event* meh= generateEvent(play);
		meh->causeEffect();
		play->nextTurn();
		if (play->getTurns()>=15) {//space travel
			play->setLevel(2);
		}
	}
	cout<<"RIP your flying abilities"<<endl;
	cout<<"You survived "<<play->getTurns()<<" turns"<<endl;
}
