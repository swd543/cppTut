//============================================================================
// Name        : CppBasicsTut2.cpp
// Author      : buga
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdint-uintn.h>
#include <iostream>
#include <string>

using namespace std;

/*
 * Just a random structure with some attributes to check how call by value and reference works.
 */
struct PotatoObject{
public:
	int a;
	uint16_t b;
	uint32_t c;
	string s;

public:
	/*
	 * Default constructor, all parameterized
	 */
	PotatoObject(int a, uint16_t b, uint32_t c, string s){
		this->a=a;
		this->b=b;
		this->c=c;
		this->s=s;
	};

	/*
	 * Pub display function to show initialization steps
	 */
	void display(){
		cout<<"PotatoObject@"<<this<<" {a="<<a<<" b="<<b<<" c="<<c<<" s="<<s<<"} memsize="<<sizeof(PotatoObject)<<"bytes \n";
	}

	/*
	 * These are called delegating constructors, with varying degrees of parameterization
	 */
	PotatoObject(int a, uint16_t b, uint32_t c):PotatoObject(a, b, c, "Potato!"){	cout<<"init4 : "; display();	};
	PotatoObject(int a, uint16_t b):PotatoObject(a, b, 1024){	cout<<"init3 : "; display();	};
	PotatoObject(int a):PotatoObject(a, 255){	cout<<"init2 : ";  display();	};
	PotatoObject():PotatoObject(128){	cout<<"init1 : ";  display();	};
	PotatoObject(int a, string s):PotatoObject(a, 255, 544, s){	cout<<"init5 : ";  display();	};

	/*
	 * Destructor for potato
	 */
	~PotatoObject(){
		cout<<"Destroyed potato! ";
		display();
	}
};


/*
 * Pass by value (a copy of the object is passed to the function)
 */
void display(int a){
	cout<<"************ Inside display function (CBV) ***************\nnum : "<<a<<"\t&num : "<<&a<<"\t*num : "<<"ERROR!"<<endl<<"**********************************************************"<<endl;
}

/*
 * Pass by reference (actual object is passed via reference (ptr))
 */
void display(int *a){
	cout<<"************ Inside display function (CBR) ***************\nnum : "<<a<<"\t&num : "<<&a<<"\t*num : "<<*a<<endl<<"**********************************************************"<<endl;
}

/*
 * Pass by value (a copy of the object is passed to the function)
 * Note that the ouput addresses in this method will be different from the original object.
 */
void display(PotatoObject a){
	cout<<"************ Inside display function (CBV) ***************\nobject.a : "<<a.a<<"\t&object.a : "<<&a.a<<"\nobject.b : "<<a.b<<"\t&object.b : "<<&a.b<<"\nobject.c : "<<a.c<<"\t&object.c : "<<&a.c<<"\nobject.s : "<<a.s<<"\t&object.s : "<<&a.s<<"\n&object : "<<&a<<"\n**********************************************************"<<endl;
}

/*
 * Pass by reference (the actual object is passed to the function via pointer)
 * Note that the ouput addresses in this method will be same as the original object.
 */
void display(PotatoObject *a){
	cout<<"************ Inside display function (CBR) ***************\nobject->a : "<<a->a<<"\t&object->a : "<<&a->a<<"\nobject->b : "<<a->b<<"\t&object->b : "<<&a->b<<"\nobject->c : "<<a->c<<"\t&object->c : "<<&a->c<<"\nobject->s : "<<a->s<<"\t&object->s : "<<&a->s<<"\n&object : "<<&a<<"\n**********************************************************"<<endl;
}

/*
 * Driver function
 */
void pointerToPrimitiveType(){

	cout<<"Inside primitive type pointer function..."<<endl;
	int x=10;
	cout<<"Variable x initialized..."<<endl;
	cout<<"Actual values ----> x : "<<x<<"\t&x : "<<&x<<endl;
	display(x);
	display(&x);

	cout<<"Inititalizing y as a pointer to x"<<endl;
	int *y=&x;
	cout<<"Actual values ----> y : "<<y<<"\t&y : "<<&y<<"\t*y : "<<*y<<endl;
	display(y);
	display(*y);
}

void pointerToUserType(){
	cout<<"Inside user type pointer function..."<<endl;

	cout<<"Initializing object..."<<endl;
	PotatoObject p1(10,"Yam");
	cout<<"Actual object ----> ";
	cout<<"PotatoObject@"<<&p1<<" {a="<<p1.a<<" &a="<<&p1.a<<" b="<<p1.b<<" &b="<<&p1.b<<" c="<<p1.c<<" &c="<<&p1.c<<" s="<<p1.s<<" &s="<<&p1.s<<"} memsize="<<sizeof(PotatoObject)<<"bytes \n";

	display(p1);
	display(&p1);
}

/*
 * Main function
 */
int main() {
	pointerToPrimitiveType();
	pointerToUserType();
	return 0;
}
