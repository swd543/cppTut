#include <bits/stdc++.h>
using namespace std;

/*

procedure mergesort( var a as array )
   if ( n == 1 ) return a

   var l1 as array = a[0] ... a[n/2]
   var l2 as array = a[n/2+1] ... a[n]

   l1 = mergesort( l1 )
   l2 = mergesort( l2 )

   return merge( l1, l2 )
end procedure

procedure merge( var a as array, var b as array )

   var c as array
   while ( a and b have elements )
      if ( a[0] > b[0] )
         add b[0] to the end of c
         remove b[0] from b
      else
         add a[0] to the end of c
         remove a[0] from a
      end if
   end while
   
   while ( a has elements )
      add a[0] to the end of c
      remove a[0] from a
   end while
   
   while ( b has elements )
      add b[0] to the end of c
      remove b[0] from b
   end while
   
   return c
	
end procedure

*/
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

vector<int> merge(vector<int> left, vector<int> right){
    
    // Step 1: Copy the subarrays

    // Step 2: Until we reach the end of either left subarray or right subarray,
    // pick the larger among the elements from L and M and place them in the correct position at A[p..q]
    int l=0,r=0,k=0;
    vector<int> a;

    for(;l<left.size() && r<right.size();k++){
        if(left[l]<right[r]){
            a.push_back(left[l++]);
        }else{
            a.push_back(right[r++]);
        }
    }

    // Step 3: When we run out of elements in either L or M, pick up the remaining elements and put in
    // A[p..q]
    for(;l<left.size();l++){
        a.push_back(left[l]);
    }
    for(;r<right.size();r++){
        a.push_back(right[r]);
    }
    return a;
}

vector<int> mergesort(vector<int> a){
    if(a.size()<=1){
        return a;
    }
    display(a);
    int mid=a.size()/2;
    vector<int> left(a.begin(), a.begin()+mid);
    vector<int> right(a.begin()+mid, a.end());
    left=mergesort(left);
    right=mergesort(right);
    return merge(left, right);
}

int main(){
    cout<<"This is a merge sort code"<<endl;
    vector<int> a={9,8,7,6,5,4,3,2,1,0};
    display("Initial array",&a);
    display("Sorted array",mergesort(a));
    return 0;
}