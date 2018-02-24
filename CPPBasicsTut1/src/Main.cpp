//============================================================================
// Name        : Threading.cpp
// Author      : buga
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

using namespace std;

/*
 * Create worker threads
 */
void createWorkerThreads(int howMany){
	vector<thread> workers;
	for(int i=0;i<howMany;i++)
		workers.push_back(thread([i](){
		while(true){
			std::cout << "hello from worker "<<i<< std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	}));

	this_thread::sleep_for(chrono::milliseconds(5));

	for_each(workers.begin(), workers.end(), [](thread &t){
		//t.detach();
		t.join();
	});
}

/*
 * What happens when thread finishes before main joins
 */
void quickThread(){
	cout<<"Thread finished!"<<endl;
}

/*
 * The calling thread (quickThread()) will wait forever to join
 */
void slowThread(){
	cout<<"Starting slow thread...";
	thread t(quickThread);
	for(int i=0;i<10000000000;i++)
		;
	t.join();
}

/*
 * Study of classes in C++
 */
class Buga{
public:

	Buga(int x,string s){
		name=s;
		a=x;
	}

	Buga(int x):Buga(x,"Helo world!"){	};

	Buga():Buga(10){	};

	virtual ~Buga(){
		cout<<"Destroying Buga!\n";
	}

private:
	int a;
	string name;
};

/*
 * Lets create an empty class in C++, cuz why not?
 */
class EmptyClass{	};

/*
 * Study of structure in C++
 */
struct BugaStruct{
public:
	BugaStruct(int x,string s){
		name=s;
		a=x;
	}

	BugaStruct(int x):BugaStruct(x,"Helo world!"){	};

	BugaStruct():BugaStruct(10){	};

	virtual ~BugaStruct(){
		cout<<"Destroying BugaStruct!\n";
	}

private:
	int a;
	string name;
};

/*
 * Structs are very similar to classes :/
 */
struct EmptyStruct{	};

/*
 * Let's print the size of stuff.
 */
void printSize(){
	cout<<"char : "<<sizeof(char)<<endl;
	cout<<"int : "<<sizeof(int)<<endl;
	cout<<"float : "<<sizeof(float)<<endl;
	cout<<"double : "<<sizeof(double)<<endl;
	cout<<"uint16_t : "<<sizeof(uint16_t)<<endl;
	cout<<"uint32_t : "<<sizeof(uint32_t)<<endl;
	cout<<"uint64_t : "<<sizeof(uint64_t)<<endl;
	cout<<"string : "<<sizeof(string)<<endl;
	cout<<"thread : "<<sizeof(thread)<<endl;
	cout<<"Buga : "<<sizeof(Buga)<<endl;
	cout<<"EmptyClass : "<<sizeof(EmptyClass)<<endl;
	cout<<"BugaStruct : "<<sizeof(BugaStruct)<<endl;
	cout<<"EmptyStruct : "<<sizeof(EmptyStruct)<<endl;
}

/*
 * Lets use pointers.
 */
void pointers(){
	int x=1;
	cout<<"int : "<<x<<" "<<sizeof(x)<<endl<<"Pointer to int : "<<sizeof(&x)<<endl;

	BugaStruct s;
	cout<<"BugaStruct : "<<" "<<sizeof(s)<<endl<<"Pointer to BugaStruct : "<<sizeof(&s)<<endl;

	Buga r;
	cout<<"Buga : "<<" "<<sizeof(r)<<endl<<"Pointer to Buga : "<<sizeof(&r)<<endl;
}

/*
 * Just another name for a type.
 */
void typeDef(){
	typedef int feet;
	feet f=10;
	cout<<"The length is "<<f<<" feet!\n";
}

/*
 * Let's see what enumeration does.
 */
void enumeration(){
	enum color{red,green,blue};
	color c=red;
	cout<<"Enumeration red : "<<c<<endl;
	c=blue;
	cout<<"Enumeration blue : "<<c<<endl;

	enum guitar{gibson,fender,cort,lesPaul=100};
	cout<<"Enumeration lesPaul : "<<lesPaul<<endl;
}

/*
 * Driver code. Comment/uncomment as necessary :)
 */
int main(int argc, char **argv)
{
	printSize();
	pointers();
	typeDef();
	enumeration();
	//callThreadObject();
	//createWorkerThreads(10);
	//slowThread();
	return 0;
}
