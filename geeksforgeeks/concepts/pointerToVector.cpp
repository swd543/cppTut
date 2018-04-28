#include<bits/stdc++.h>

using namespace std;

void display(vector<int> *v){
    cout<<(*v).size()<<endl;
}

void display(int is...){
    cout<<is<<endl;
}

int main(){
    cout<<"Hellow world!"<<endl;
    vector<int> v={10,20,40,5,6,7,8},w={1,0,9};
    display(10,20);
}
