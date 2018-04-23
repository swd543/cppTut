#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/sum-of-bit-differences-among-all-pairs/
 
int sumBitDifferences(int arr[], int n)
{
    int ans = 0;  // Initialize result
 
    // traverse over all bits
    for (int i = 0; i < 2; i++)
    {
        // count number of elements with i'th bit set
        int count = 0;
        for (int j = 0; j < n; j++)
            if ( (arr[j] & (1 << i)) )
                count++;
        // Add "count * (n - count) * 2" to the answer
        ans += (count * (n - count) * 2);
    }
 
    return ans;
}
 
// Driver prorgram
int main()
{
    int arr[] = {1, 0};
    int n = sizeof arr / sizeof arr[0];
    cout << sumBitDifferences(arr, n) << endl;
    return 0;
}