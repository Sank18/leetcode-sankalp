class Solution {
public:
    int dp[502][502];
    
    int f(int i, int j, vector<int>& diff, int x) {
        // cout<<"hello"<<endl;
        if (i >= (diff.size() - 1) || j - 1 < 0) {
            return 0;
        }
        if (i > j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        // cout<<"hello2"<<endl;
        int operation1 = diff[i + 1] - diff[i] + f(i + 2, j, diff, x);
        int operation2 = x + f(i + 1, j - 1, diff, x);
        int operation3 = diff[j] - diff[j - 1] + f(i, j - 2, diff, x);
        cout<<"hello"<<endl;
        
        return dp[i][j] = min({operation1, operation2, operation3});
    }
    
    int minOperations(string s1, string s2, int x) {
        vector<int> diff;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }
        int n = diff.size();
        if (n % 2 != 0) {
            return -1;
        }
        memset(dp, -1, sizeof(dp));
        return f(0, n - 1, diff, x);
    }
};
