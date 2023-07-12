class Solution {
    void func(int ind, int target, vector<int> &ds, vector<vector<int>> &ans, vector<int>& candidates, int n){
        if(ind == n){
            if(target == 0)ans.push_back(ds);
            return;
        }
        //pick
        if(candidates[ind] <= target){
        ds.push_back(candidates[ind]);
        func(ind, target-candidates[ind], ds, ans, candidates, n);
        ds.pop_back();
        }
        //NOT pick
        func(ind+1, target, ds, ans, candidates, n);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        func(0, target, ds, ans, candidates, n);
        return ans;
    }
};
