//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long k)
    {
        // Your code here
        int i =-1, j = -1;
        int start = 0, end = -1;
        long long sum = 0;
        while (start < n) {
            while ((end + 1 < n) && (sum + arr[end + 1] <= k))
                sum += arr[++end];

            if (sum == k) {
                i = start;
                j = end;
                if(i != -1 && j != -1){
                    return {i+1,j+1};
                }
                else{
                    return {-1};
                }
            }
            sum -= arr[start];
            start++;
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
