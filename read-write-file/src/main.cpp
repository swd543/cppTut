#include <iostream>
#include <fstream>
#include <list>
#include "player.hpp"
using namespace std;

#define dumpfile "dump.bin"

template <class c>void write(c* object);
template <class c>void read(c* object);

int main(int argc, char *argv[]) {
	cout<<"Hello world!"<<endl;

	{
		player one{
			"Buga",
			"Nord",
			5
		};
		one.display();
		cout<<"Write file test..."<<endl;
		write(&one);
		cout<<"Wrote "<<dumpfile<<" successfully."<<endl;
	}
	
	{
		player two;
		cout<<"Read file test..."<<endl;
		read(&two);
		cout<<"Read "<<dumpfile<<" successfully."<<endl;
		two.display();
	}
}

template <class c>void write(c* object){
	ofstream ofstream;
	ofstream.open(dumpfile,ios::binary);
	ofstream.write((char*)object, sizeof(c));
	ofstream.close();
}

template <class c>void read(c* object){
	ifstream ifstream;
	ifstream.open(dumpfile,ios::binary);
	ifstream.read((char*)object, sizeof(c));
	ifstream.close();
}