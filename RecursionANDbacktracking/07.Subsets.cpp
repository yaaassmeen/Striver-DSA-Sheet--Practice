class Solution {
    void print(int ind, vector<vector<int>> &ans,vector<int> &a, vector<int>& nums, int n){
        if(ind == n){
            ans.push_back(a);
            return;
        }
        //NOT Pick the element in current index;
        print(ind+1, ans, a, nums, n);

        //Pick the element in current index;
        a.push_back(nums[ind]);
        print(ind+1,ans,a,nums,n);
        a.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //power set method
        // int n = nums.size();
        // vector<vector<int>> ans;
        // for(int i=0;i<pow(2,n);i++){
        //     vector<int> a;
        //     for(int j=0;j<n;j++){
        //         if((i&(1<<j)) != 0)
        //         a.push_back(nums[j]);
        //     }
        //     ans.push_back(a);
        // }
        // return ans;

        //Recurssive 
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> a;
        print(0, ans, a, nums, n);
        return ans;
    }
};
