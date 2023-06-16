class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> end;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int rem = target - nums[i];
            if(mp.find(rem) != mp.end()){
                end.push_back(min(i, mp[rem]));
                end.push_back(max(i, mp[rem]));
            }
            mp[nums[i]] = i;
        }
        return end;
    }
};
