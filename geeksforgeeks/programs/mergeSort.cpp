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

void display(string prefix, vector<int> *a){
    cout<<prefix<<" --> ";
    //display(*a);
}
/*
void display(vector<int> a...){
    for(int i=0;i<sizeof(a)/sizeof(vector<int>);i++){
        for(const int v:a[i]){
            cout<<v<<" ";
        }
        cout<<" / ";
    }
    cout<<endl;
}
*/
void simple_printf(const char* fmt...)
{
    va_list args;
    va_start(args, fmt);
 
    while (*fmt != '\0') {
        if (*fmt == 'd') {
            int i = va_arg(args, int);
            std::cout << i << '\n';
        } else if (*fmt == 'c') {
            // note automatic conversion to integral type
            int c = va_arg(args, int);
            std::cout << static_cast<char>(c) << '\n';
        } else if (*fmt == 'f') {
            double d = va_arg(args, double);
            std::cout << d << '\n';
        }
        ++fmt;
    }
 
    va_end(args);
}
void merge(vector<int> *left, vector<int> *right){
    
    // Step 1: Copy the subarrays


    // Step 2: Until we reach the end of either left subarray or right subarray,
    // pick the larger among the elements from L and M and place them in the correct position at A[p..q]

    // Step 3: When we run out of elements in either L or M, pick up the remaining elements and put in
    // A[p..q]
}

void mergesort(vector<int> *a){
    if((*a).size()<=1){
        return;
    }
    int mid=(*a).size()/2;
    vector<int> left((*a).begin(), (*a).begin()+mid);
    vector<int> right((*a).begin()+mid, (*a).end());
    mergesort(&left);
    mergesort(&right);
    merge(&left, &right);
}


int main(){
    cout<<"This is a merge sort code"<<endl;
    vector<int> a={10, 14, 19, 26, 0, 27, 31, 33, 35, 42, 44 };
    vector<int> b={10, 14, 19, 26, 0, 27, 31, 33, 35, 42, 44 };

    simple_printf("dcff", 3, 'a', 1.999, 42.5, 100000000000000999); 
    //display("Initial array",&a);
    //mergesort(&a);
    //display(a, b);
    return 0;
}