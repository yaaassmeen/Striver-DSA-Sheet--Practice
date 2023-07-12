//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
   void func(string& ds, string& nums, set<string>& uniquePerms, vector<int>& freq) {
    if (ds.size() == nums.size()) {
        uniquePerms.insert(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) {
            ds.push_back(nums[i]);
            freq[i] = 1;
            func(ds, nums, uniquePerms, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
            vector<string> ans;
            string ds;
            vector<int> freq(S.size(), 0);
            set<string> uniquePerms;
            func(ds, S, uniquePerms, freq);
            ans.assign(uniquePerms.begin(), uniquePerms.end());
            sort(ans.begin(), ans.end()); // Sort the permutations lexicographically
            return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
