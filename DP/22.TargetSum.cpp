//Refer lc -https://leetcode.com/problems/target-sum/
class Solution {
    
public:
    //Striver Way
    // int solve(int n,int target,vector<vector<int>>&dp,vector<int>&nums){
    //     if(n==0){
    //         if(target==0 and nums[0]==0) return 2;
    //         if(target==0 or target==nums[0]) return 1;
    //         return 0;
    //     }
    //     if(dp[n][target]!=-1) return dp[n][target];
    //     int np = solve(n-1,target,dp,nums);
    //     int p =0;
    //     if(target>=nums[n]) p = solve(n-1,target-nums[n],dp,nums);
    //     return dp[n][target] = p+np;
    // }
    
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n= nums.size();
    //     int sum=0;
    //     for(auto i:nums) sum+=i;
    //     if(sum-target < 0 or (sum-target)%2) return 0;
    //     vector<vector<int>>dp(n,vector<int>((sum-target)/2 +1, -1));
    //     return solve(n-1,(sum-target)/2,dp,nums);
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum-target < 0 or (sum-target)%2) return 0;
        int tar = (sum-target)/2;
        vector<vector<int>>dp(n,vector<int>(tar+1, 0));
        if(nums[0]==0) dp[0][0] = 2;
        else dp[0][0]=1;
        if(nums[0]!=0 and tar>=nums[0]) dp[0][nums[0]] =1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=tar;j++){
                int np = dp[i-1][j];
                int p = 0;
                if(j>=nums[i]) p = dp[i-1][j-nums[i]];
                dp[i][j] = p+np;
            }
        }
        return dp[n-1][tar];
    }
};
    
// class Solution {
//     // int f(int ind, int target, vector<int>& nums){
//     //     if(target == 0 && ind == nums.size()) return 1;
//     //     if(ind == nums.size()) return 0;
//     //     int pos = f(ind+1, target - nums[ind], nums);
//     //     int neg = f(ind+1, target + nums[ind], nums);
//     //     return pos+neg;
        
//     // }
//     vector<vector<int>>dp;
//     int Nsum;
//     int getSum(vector<int>&nums,int sum,int idx,int &target){
//         if(sum == target && idx == nums.size()) return 1;
//         if(idx == nums.size()) return 0;
        
//         if(dp[idx][sum + Nsum] != -1 )return dp[idx][sum + Nsum];
        
//         int add      = getSum(nums, sum + nums[idx], idx + 1, target);
//         int subtract = getSum(nums, sum - nums[idx], idx + 1, target);
        
//         return  dp[idx][sum + Nsum] = add + subtract;
//     }
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         // int n  =nums.size();
//         // return f(0, target, nums);
//         int sum = 0;
//         for(int i=0; i<nums.size(); i++)sum += nums[i];
//         if(sum > target && -1*sum > target)return 0;
        
//         Nsum = sum;
//         dp.resize(nums.size(),vector<int>(2 * sum + 2,-1));
//         return getSum(nums,0,0,target);
//     }
// };
