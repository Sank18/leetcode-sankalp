class Solution {
public:
    
    long long maxPoints(vector<vector<int>>& points) {
        long long int n=points.size();
        long long int m=points[0].size();
        long long int dp[n+1][m+1];
        for(int i=0;i<m;i++)
        {
            dp[0][i]=points[0][i];
        }
        for (int i=1 ; i<n ; i++) {

			vector<long long int>leftMax(m,0);
			leftMax[0] = dp[i-1][0];
			for (int k=1 ; k<m ; k++) {
				leftMax[k] = max( leftMax[k-1] , dp[i-1][k] + k );
			}

			vector<long long int>rightMax(m,0);
			rightMax[m-1] = dp[i-1][m-1] - (m-1);
			for (int k = m-2 ; k >= 0 ; k--) {
				rightMax[k] = max( rightMax[k+1] , dp[i-1][k] - k );
			}

			for (int j=0 ; j<m ; j++) {
				dp[i][j] = points[i][j] + max( leftMax[j]-j , rightMax[j]+j );
			}
        }
        long long ans=0;
       for(int i=0;i<m;i++)
       {
           ans=max(ans,dp[n-1][i]);
       }
        return ans;
        
        
    }
};