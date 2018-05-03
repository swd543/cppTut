#include <bits/stdc++.h>

using namespace std;

class Base{
    private:
        int hydrogen, oxygen;
    public:
        int getHydrogen(){
            return hydrogen;
        }

        
        int getOxygen(){
            return oxygen;
        }
        Base(int hydrogen, int oxygen){
            this->hydrogen=hydrogen;
            this->oxygen=oxygen;
        }
        void display(){
            cout<<"Base [ hydrogen : "<<this->hydrogen<<", oxygen : "<<this->oxygen<<" ] "<<endl;
        }
};

class Derived:Base{
    public:
    Derived();
};

int main(){
    Base b{1,3};
    b.display();
    Derived d{};
    return 0;
}