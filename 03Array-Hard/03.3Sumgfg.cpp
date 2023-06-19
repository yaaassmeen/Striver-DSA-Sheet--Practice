//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int A[], int N, int X)
    {
        // code here
        int ans = 0;
        int mn = INT_MAX;
        sort(A,A+N);
        for(int i=0;i<N;i++){
            if(i>0 && A[i] == A[i-1]) continue;
            int j = i+1;
            int k = N-1;
            while(j<k){
                int sum = A[i]  + A[j] + A[k];
                if(sum<X){
                    j++;
                    if(abs(sum-X) < mn){
                        ans = sum;
                        mn = abs(sum-X);
                    }
                }else if(sum > X){
                    k--;
                    if(abs(sum-X) < mn){
                        ans = sum;
                        mn = abs(sum-X);
                    }
                }else{
                    return sum;
                }
            }
        }
        return ans;
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
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends
