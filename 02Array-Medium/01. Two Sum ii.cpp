class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int l = 0, r = nums.size()-1;
        while(l<r){
            int s = nums[l] + nums[r];
            if(s == target){
                ans.push_back(min(l,r)+1); 
                ans.push_back(max(l,r)+1); 
                break;
            }
            else if(s < target){
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};
