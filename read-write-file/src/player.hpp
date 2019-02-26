#include<iostream>

using namespace std;

class player
{
private:
	string name,race;
	int power;
public:
	player(string name, string race, int power);
	player();
	~player();
	void display(){
		cout<<"class\t : player\nname\t : "<<name<<"\nrace\t : "<<race<<"\npower\t : "<<power<<endl;
	}
};

player::player(string name, string race, int power){
	cout<<"Instantiating "<<name<<endl;
	this->name=name;
	this->race=race;
	this->power=power;
}

player::player(/* args */){
	cout<<"Instantiating null player"<<endl;
}

player::~player(){
	cout<<"Destroying "<<name<<endl;
}
