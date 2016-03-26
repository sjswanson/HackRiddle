
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Plane {
	string name;
	int fuel;
	int hp;
	int turnsSurvived;
	bool alive;
	int level;
	public:
		Plane() {level=1; turnsSurvived = 0;};
		int getHP() {return hp;};
		void setHP(int health) {hp = health;};
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
	cout << "Health remaining: " << hp <<endl;
	if(fuel <= 0){alive = false;}
	if(hp <= 0){alive = false;}
}

class Event {
	int death;
	string description;
	int fuelEffect;
	int healthEffect;
	Plane * lePlane;
	public:
		Event(int, string, int, int, Plane*);
		void causeEffect();
};

Event::Event(int deathRate,string describe,int fuelChange,int healthChange, Plane * newPlane) {
	death=deathRate;
	description=describe;
	fuelEffect=fuelChange;
	healthEffect=healthChange;
	lePlane= newPlane;

}

void Event::causeEffect() {

	if (rand()%100<death) {
		lePlane->die();
	}
	else
	{
		lePlane->setFuel(lePlane->getFuel()+fuelEffect);
		lePlane->setHP(lePlane->getHP()+healthEffect);
	}
}


Event* generateEarth(Plane* play) {

int dead =0;
int fc1 = 0;
int hc1 = 0;
int fc2 = 0;
int hc2 = 0;
string desc ="";
string choice1="";
string choice2="";
int randnum = rand()%170;

if (randnum< 12){
desc = "You see an Eagle. Do you (A) Hit it or (B) Ignore it? ";
dead = 0;
choice1 = "Your devious act against America's freedom cost you 10 HP. But you inexplicably gain 2 fuel";
fc1 = 2;
hc1 = -10;
choice2 = "You leave the Eagle alone. Nothing happens, but you feel better about yourself.";
fc2 = 0;
hc2 = 0;
}
else if (randnum< 24){
desc = "You encounter turbulence. Do you (A) Stabilize or (B) Deal with it? ";
dead = 0;
choice1 = "The people who needed to pee feel relieved, but stabilizing cost you 1 fuel";
fc1 = -1;
hc1 = 0;
choice2 = "You deal with it, causing everyone with full bladders to hate you. You lose 15 HP";
fc2 = 0;
hc2 = 0;
}
else if (randnum< 36){
desc = "A fire starts aboard the plane. Do you (A) Extinguish it or (B) Let it engulf the plane? ";
dead = 0;
choice1 = "You sensibly put out the fire, losing 1 fuel and 10 HP in the process";
fc1 = -1;
hc1 = -10;
choice2 = "You hope the speed of the plane puts out the fire. It does, but you lost 20 HP";
fc2 = 0;
hc2 = -20;
}
else if (randnum< 48){
desc = "You accidentally end up off course. Do you (A) Go back or (B) Stay off course? ";
dead = 0;
choice1 = "There's no place like home. Rerouting cost you 2 fuel";
fc1 = -2;
hc1 = 0;
choice2 = "Going off course fills you with determination. You gain 10 HP.";
fc2 = 0;
hc2 = 10;
}
else if (randnum< 60){
desc = "You become sleepy. Do you (A) Drink a large pot of coffee or (B) Do nothing?";
dead = 0;
choice1 = "You down the whole pot and gain 10HP. But you used fuel instead of water to brew it, so you lost 1 fuel";
fc1 = -1;
hc1 = 10;
choice2 = "Sleep is for the weak. But also the dead. You crash the plane and lose all your HP.";
fc2 = 0;
hc2 = -100;
}
else if (randnum< 68){
desc = "There are mofuggin snakes on the mofuggin plane. Are you (A) Tired of them or (B) Going to panic?";
dead = 0;
choice1 = "You jam the snakes into the fuel tank (somehow) and gain 2 fuel";
fc1 = 3;
hc1 = 0;
choice2 = "You panic, but luckily, Samuel L. Jackson saves you all. Your cowardice costs you 1 fuel, 15HP, and 2 dignity";
fc2 = -1;
hc2 = -15;
}
else if (randnum< 76){
desc = "You are being shot at. Do you (A) Flee or (B) Fight back?";
dead = 0;
choice1 = "Your passenger jet somehow sprouts guns and you shoot down your opponents, losing 2 fuel in the process";
fc1 = -2;
hc1 = 0;
choice2 = "You fly away because ERAU != Air Force. You lose 15HP in the process";
fc2 = 0;
hc2 = -15;
}
else if (randnum< 84){
desc = "The weather suddenly becomes nasty. Do you (A) Stay Away or (B) Go through?";
dead = 0;
choice1 = "You make the sensible decision and fly around the bad weather, but lose 2 fuel in the process";
fc1 = -2;
hc1 = 0;
choice2 = "Against your better judgement, you fly through the stormy weather. Surviving, but losing 20HP";
fc2 = 0;
hc2 = -20;
}
else if (randnum< 91){
desc = "You OD'd on meth prior to takeoff and are having meth hallucinations. Do you (A) Sober up or (B) Inject more? ";
dead = 0;
choice1 = "You remind yourself of those crazies on Breaking Bad and sober up, gaining 10HP.";
fc1 = 0;
hc1 = 10;
choice2 = "You lose all your health and set a bad example to kids everywhere.";
fc2 = 0;
hc2 = -100;
}
else if (randnum< 94){
desc = "You see Superman flying outside. Do you ask for (A) More fuel or (B) More health?";
dead = 0;
choice1 = "Superman converts some of his essence into fuel for your ship. You gain 3 fuel";
fc1 = 3;
hc1 = 0;
choice2 = "Superman hugs you and tells you that you're the real superhero. You blush and gain 25HP";
fc2 = 0;
hc2 = 25;
}
else if (randnum< 96){
desc = "You are attacked by zombies. Do you (A) Fight back or (B) Be converted? ";
dead = 0;
choice1 = "You channel your inner Rick Grimes and fight the zombies, but you lose 20HP in the process";
fc1 = 0;
hc1 = -20;
choice2 = "You give into your inevitable demise. But now that you're undead, you no longer have to pay for health insurance and gain 10HP";
fc2 = 0;
hc2 = 10;
}
else if (randnum< 97) {
desc="Your plane has spontaneously disassembled itself. Would you like to (A) Die or (B) Die?";
fc1=0;
choice1 = "You died, but at least you did your best :)";
hc1=-100;
dead=100;
choice2 = "You died, n00b";
fc2 = 0;
hc2 = 0;
}
else if (randnum < 110)
{
desc = "Trivia! Airflow through a ramjet engine is supersonic. (A) True or (B) False?";
fc2=5;
hc2=5;
dead=0;
fc1=0;
hc1=0;
choice1 = "Fail! It was false!";
choice2 = "Correct! You gain 5 HP and 5 fuel!";
}
else if (randnum < 120)
{
desc = "Trivia! The chevron serves to make an engine less noisy (A) True or (B) False?";
fc2=0;
hc2=0;
dead=0;
fc1=1;
hc1=1;
choice2 = "Fail! It was true!";
choice1 = "Correct! You gain 5 HP and 5 fuel!";
}
else if (randnum < 130)
{
desc = "Trivia! Airflow through a scramjet is at subsonic speeds. (A) True or (B) False?";
fc1=0;
hc1=0;
dead=0;
fc2=1;
hc2=1;
choice1 = "Fail! It was false!";
choice2 = "Correct! You gain 5 HP and 5 fuel!";
}
else if (randnum < 140)
{
desc = "Trivia! Bernoulli's principle is the reason for flight. (A) True or (B) False?";
fc2=0;
hc2=0;
dead=0;
fc1=1;
hc1=1;
choice2 = "Fail! It was true!";
choice1 = "Correct! You gain 5 HP and 5 fuel!";
}
else if (randnum < 150)
{
desc = "Trivia! Howard Hughes was the first person to break the sound barrier. (A) True or (B) False?";
fc2=5;
hc2=5;
dead=0;
fc1=0;
hc1=0;
choice2 = "Fail! It was false!";
choice1 = "Correct! You gain 5 HP and 5 fuel!";
}
else {
	desc = "All clear. Hit A to continue.";
	dead = 0;
	fc1 = 0;
	hc1 = 0;
	fc2 = 0;
	hc2 = 0;
}
cout << desc << endl;
string decision;
cin >> decision;
if (decision!="a"&&decision!="A"&&decision!="b"&&decision!="B") {
	cout << "Not a valid choice!!!!" << endl;
}
Event* meh;
if(decision == "a" || decision == "A")
{ cout << choice1 <<endl;
	meh=new Event(dead,desc, fc1, hc1, play);}
else if (decision == "b" || decision == "B")
 { cout << choice2 <<endl;
	 meh=new Event(dead,desc, fc2, hc2, play);}
return meh;
}

Event* generateSpace(Plane* play) {

int dead =0;
int fc1 = 0;
int hc1 = 0;
int fc2 = 0;
int hc2 = 0;
string desc ="";
string choice1 ="";
string choice2 ="";
int randnum = rand()%160;
if (randnum< 11){
desc = "Some debris is flying your way. Do you (A) Avoid it or (B) Run into it? ";
dead = 0;
choice1 = "You dodge the debris like any normal person would. Nothing happens, but at least you're not dead.";
fc1 = 0;
hc1 = 0;
choice2 = "You run head first into the debris and die. What'd you think would happen?";
fc2 = 0;
hc2 = -100;
}
else if (randnum< 22){
desc = "You run into a spare part floating around. Do you (A) Install it or (B) Ignore it? ";
dead = 0;
choice1 = "Your elite engineering skills boosts your ship's power. You gain 2 fuel";
fc1 = 2;
hc1 = 0;
choice2 = "You ignore the part, but what if it was useful...? (it wasn't)";
fc2 = 0;
hc2 = 0;
}
else if (randnum< 33){
desc = "You run into a Tie-Fighter. Do you (A) Fight it or (B) Run away? ";
dead = 0;
choice1 = "You engage with the Empire, but then you realize the pilot is actually a cool guy. You gain 10HP and a new friendship";
fc1 = 0;
hc1 = 10;
choice2 = "You fly away, like the rebel scum you are and lose 1 fuel";
fc2 = -1;
hc2 = 0;
}
else if (randnum< 44){
desc = "You're having trouble adjusting to the gravity. Do you (A) Stop and adjust or (B) Keep going? ";
dead = 0;
choice1 = "You stop the ship to allow your body to readjust, but lose 2 fuel in the process";
fc1 = -2;
hc1 = 0;
choice2 = "Who needs functioning organs. Your body does. You lose 15HP";
fc2 = 0;
hc2 = -15;
}
else if (randnum< 55){
desc = "You see a space fueling station. Do you (A) Stop and refuel or (B) Keep going? ";
dead = 0;
choice1 = "The fueling station was a trap set up by the space thugs. They jump you and you die.";
fc1 = 0;
hc1 = -100;
choice2 = "You keep going. Feeling good about your decision, you gain 10HP";
fc2 = 0;
hc2 = 10;
}
else if (randnum< 65){
desc = "You run into a martian. Do you (A) Attack it or (B) Talk to it? ";
dead = 0;
choice1 = "You fight off the martian, jeopardizing our future relationship with extraterrestrials and lose 10HP";
fc1 = 0;
hc1 = -10;
choice2 = "It was friendly. He sends you off with 3 fuel and 20HP. He also invites you to brunch, but you politely decline.";
fc2 = 3;
hc2 = 20;
}
else if (randnum< 75){
desc = "That's no moon, that's a space station. Do you (A) Blow it up or (B) Catch up with Darth Vader? ";
dead = 0;
choice1 = "You use the Force and blow up the Death Star. Feeling good about yourself, you gain 15HP";
fc1 = 0;
hc1 = 15;
choice2 = "You compromise with the Empire and let them know to check out Dagobah. You survive, but feel bad about yourself";
fc2 = 0;
hc2 = 0;
}
else if (randnum< 85){
desc = "There is an oxygen supply failure. Do you (A) Fix it or (B) Do nothing? ";
dead = 0;
choice1 = "You alchemically produce oxygen with your wizard skills and gain 10HP";
fc1 = 0;
hc1 = 10;
choice2 = "You expect to spontaneously evolve the ability to breathe without oxygen. Nothing happens and you die";
fc2 = 0;
hc2 = -100;
}
else if (randnum< 90){
desc = "You see a shooting star. Do you (A) Make a wish or (B) Disregard Disney's Pinocchio? ";
dead = 0;
choice1 = "You wish for more health and fuel instead of free college tuition and gain 15HP and 3 fuel";
fc1 = 3;
hc1 = 15;
choice2 = "You admire the shooting star for what it is, and nothing else";
fc2 = 0;
hc2 = 0;
}
else if (randnum< 95){
desc = "You get sucked into a black hole. Do you (A) Die or (B) Die? ";
dead = 100;
choice1 = "I'm sorry :(";
fc1 = 0;
hc1 = 10;
choice2 = "I'm sorry :(";
fc2 = 0;
hc2 = 0;
}
else if (randnum< 100) {
	desc = "You run into space pirates. Do you (A) Fight them or (B) Trade with them? ";
	dead = 0;
	choice1 = "You fight them off, and lose 15HP because you got infected with space scurvy";
	fc1 = 0;
	hc1 = -15;
	choice2 = "You trade the grillz in your teeth for 3 fuel";
	fc2 = 3;
	hc2 = 0;
}
else if (randnum< 110) {
desc="Trivia! A geostationary orbit can be geosynchrous, but not all geosynchrous orbits are geostationary (A) True or (B) False? ";
fc1=0;
choice1 = "Correct! You gain 5 HP and 5 fuel";
hc1=5;
dead=5;
choice2 = "Fail! It was true";
fc2 = 0;
hc2 = 0;
}
else if (randnum< 120) {
desc="Trivia! Until the early 1920s, a clock did not exist that was more accurate than that of the Earth's daily rotation about its axis. (A) True or (B) False? ";
fc1=5;
choice1 = "Correct! You gain 5 HP and 5 fuel";
hc1=5;
dead=0;
choice2 = "Fail! It was true";
fc2 = 0;
hc2 = 0;
}
else if (randnum< 130) {
desc="Trivia! An orbit can be both in a sun-synchrous orbit and in a repeat orbit at the same time? (A) True or (B) False? ";
fc1=5;
choice1 = "Correct! You gain 5 HP and 5 fuel";
hc1=5;
dead=0;
choice2 = "Fail! It was true";
fc2 = 0;
hc2 = 0;
}
else if (randnum < 140) {
	desc="Trivia! A repeat orbit is often defined in terms of the number of orbits within the repeat time frame. Is it possible to have a low Earth orbit repeat track of 200/8, i.e. 200 orbits every 8 days. (A) True or (B) False?";
	fc2=5;
	choice2 = "Correct! You gain 5 HP and 5 fuel";
	hc2=5;
	dead=0;
	choice1 = "Fail! It was false";
	fc1 = 0;
	hc1 = 0;
}
else if (randnum < 150) {
	desc="Trivia! The geoid is a methematically perfect ellipsoid that is sized to coincide with the mean sea level. (A) True or (B) False? ";
	fc2=5;
	choice2 = "Correct! You gain 5 HP and 5 fuel";
	hc2=5;
	dead=0;
	choice1 = "Fail! It was false!";
	fc1 = 0;
	hc1 = 0;
}
else {
	desc = "All clear. Hit A to continue.";
	dead = 0;
	fc1 = 0;
	hc1 = 0;
	fc2 = 0;
	hc2 = 0;
}

cout << desc << endl;
string decision;
cin >> decision;
if (decision!="a"&&decision!="A"&&decision!="b"&&decision!="B") {
	cout << "Not a valid choice!!!!" << endl;
}
Event* meh;
if(decision == "a" || decision == "A")
{	cout<< choice1 <<endl;
	meh=new Event(dead,desc, fc1, hc1, play);}
else if (decision == "b" || decision == "B")
 { cout<< choice2 <<endl;
	 meh=new Event(dead,desc, fc2, hc2, play);}
return meh;
}

int main() {
	cout<<"Welcome to Embry Riddle Aeronautical Boot Camp for Trying to Fly a Plane"<<endl;
	cout<<"Enter your name: ";
	bool saidIt = false;
	srand(time(NULL));
	string playerInput;
	cin>>playerInput;
	Plane* play=new Plane();
	play->setFuel(20);
	play->setHP(100);
	play->setAlive(true);
	play->setLevel(1);
	while (play->getAlive()) {
		Event * meh;
		if(play->getLevel() == 1)
		{meh= generateEarth(play);}
		else {meh = generateSpace(play);}
		meh->causeEffect();
		play->nextTurn();
		if (play->getTurns()>=10) {//space travel
			play->setLevel(2);
			if(!saidIt){
				cout<<"Your stupendous flying has caused you to launch into space. Welcome to the next frontier" <<endl;
				saidIt = true;
			}
		}
	}
	if(play->getFuel() <= 0){
		cout<<"You ran out of fuel, and died" <<endl;
	}
	if(play->getHP() <= 0){
		cout<<"You ran out of HP, and died" <<endl;
	}
	cout<< playerInput << ", you need to work on your flying abilities"<<endl;
	cout<<"You survived "<<play->getTurns()<<" turns"<<endl;
}
