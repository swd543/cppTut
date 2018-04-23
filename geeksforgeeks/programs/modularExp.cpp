#include <bits/stdc++.h>
using namespace std;
int modularExponentiate(uint64_t x, uint64_t y, uint64_t m){
    cout<<x<<endl;
    if(y==0)
        return 1;

    if(y%2==0){
        uint64_t t=modularExponentiate(x,y/2,m);
        return ((t%m)*(t%m))%m;
    }
    else{
        return ((x%m)*(modularExponentiate(x,y-1,m)%m))%m;
    }
}

int main(){
    std::cout<<modularExponentiate(2,10,13)<<std::endl;
    return 0;
}