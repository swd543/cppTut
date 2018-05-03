#include <bits/stdc++.h>

using namespace std;
#define len(a) sizeof(a)/sizeof(int)

void display(vector<int> a){
    for(const int v:a){
        cout<<v<<" ";
    }
    cout<<endl;
}

void display(vector<int> *a){
    display(*a);
}

void display(string prefix, vector<int> a){
    cout<<prefix<<" --> ";
    display(a);
}

void display(string prefix, vector<int> *a){
    cout<<prefix<<" --> ";
    display(a);
}

int getMedian(int a[], int aLength){
    return (aLength%2!=0)?a[aLength/2]:(a[-1+aLength/2]+a[aLength/2])/2;
}

int getMedianEfficiently(int left[], int leftLength, int right[], int rightLength){
    int lm=getMedian(left,leftLength), rm=getMedian(right,rightLength);
    if(lm==rm){
        return lm;
    } else if(lm>rm){

    }
}

int getMedian(int left[], int leftLength, int right[], int rightLength){
    int l=0,r=0;
    int mid=((leftLength+rightLength)/2);
    cout<<"Somewhere along the "<<mid<<endl;
    vector<int> x;
    for(int k=0;l<leftLength && r<rightLength && k<=mid;k++){
        cout<<".l"<<l<<" r"<<r;

        if(k==mid-1 || k==mid){
            if(left[l]<right[r]){
                x.push_back(left[l++]);
            } else {
                x.push_back(right[r++]);
            }
        } else{
            if(left[l]<right[r]){
                l++;    // discard the lowest n numbers
            } else {
                r++;    // discard the lowest n numbers
            }
        }
    }
    display(x);
    return (x[0]+x[1])/2;
}

int main(){
    int a[] = {1, 12, 15, 17, 26};
    int b[] = {2, 13, 17, 30, 45};

    cout<<"Median is : "<<getMedian(a,len(a),b,len(b))<<endl;
    cout<<getMedian(a,len(a))<<endl;
    return 0;
}