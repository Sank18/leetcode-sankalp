class Solution {
public:
    bool solve(int idx, string &s, int minJ, int maxJ, vector<int> &dp){
        if(idx >= s.length() || s[idx] == '1') return false;
        if(idx == s.length() - 1) return true;
        if(dp[idx]!=-1) return dp[idx];
        dp[idx] = false;
        for(int i = minJ; i<= maxJ; i++){
            if(solve(idx + i, s, minJ, maxJ, dp)) return dp[idx] = true;
        }
        return dp[idx];
    }
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.length() - 1] == '1') return false;
        
        int cnt = 0;
      
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '1'){
                cnt++;
                if(cnt >= maxJump) return false;
            }
            else{
                cnt = 0;
            }
        }
        vector<int> dp(s.length(), -1);
        return solve(0, s, minJump, maxJump, dp);
    }
};