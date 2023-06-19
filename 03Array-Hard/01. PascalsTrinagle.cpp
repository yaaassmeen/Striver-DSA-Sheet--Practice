//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
  //optimal
     vector<long long> generateRow(int row){
        vector<long long> ansR;
        long long ans = 1;
        ansR.push_back(ans);
        for(int i=1;i<row;i++){ // i = col
            ans = ans*(row-i);
            ans /= i;
            ansR.push_back(ans);
        }
        return ansR;
    }
  //Naive
    int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        vector<long long> a;
        // a = generateRow(n);
        for (int c = 1; c <= n; c++) {
            a.push_back(nCr(n - 1, c - 1));
        }
        return a;
    }
  //To generate whole pascals triangle
   vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a;
        for(int i=1;i<=numRows;i++){
            a.push_back(generateRow(i));
        }
        return a;
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends
