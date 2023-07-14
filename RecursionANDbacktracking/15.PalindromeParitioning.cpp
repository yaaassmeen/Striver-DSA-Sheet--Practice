class Solution {
    bool isPalindrome(int st, int en, string s){
        while(st<=en){
            if(s[st++] != s[en--]) return false;
        }
        return true;
    }
    void solve(int ind, vector<string> &str, string s, vector<vector<string>> &ans){
        if(ind == s.size()){
            ans.push_back(str);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(ind, i, s)){
                str.push_back(s.substr(ind, i-ind+1));
                solve(i+1, str, s, ans);
                str.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>  substrs;
        solve(0, substrs, s, ans);
        return ans;
    }
};
