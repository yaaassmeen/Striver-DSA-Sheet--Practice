//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        int left = 0, right = 0;
        long long sum = A[0];
        int maxLen = 0;
        while(right < N){
            while(left <= right && sum > k){
                sum -= A[left];
                left++;
            }
            if(sum == k){
                maxLen = max(maxLen, right-left+1);
            }
            right++;
            if(right<N) sum+=A[right];
        }
        return maxLen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
