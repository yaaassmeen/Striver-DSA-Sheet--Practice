//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        map<int,int> mpp;
        int cnt = 0;
        int preSum = 0;
        mpp[0] = 1;
        for(int i=0;i<N;i++){
            preSum += Arr[i];
            int rem = preSum-k;
            // if(mpp.find(rem) != mpp.end()){
            //     cnt += mpp[rem];
            // }
            cnt += mpp[rem];
            mpp[preSum]++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
