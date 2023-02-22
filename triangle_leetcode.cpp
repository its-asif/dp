class Solution {
public:
int dp[201][201];
    long long f(int i,int j,int n,vector<vector<int>>& v){
        if(i==0) return v[0][0];
        if(dp[i][j]!=-1) return dp[i][j];

        long long up = INT_MAX, left = INT_MAX;
        if(i>0 && j!=i) up = v[i][j] + f(i-1,j,n,v);
        if(j>0) left = v[i][j] + f(i-1,j-1,n,v);

        return dp[i][j] = min(up,left);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        long long ans= INT_MAX;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            ans = min(ans,f(n-1,i,n,triangle));
        }
        return ans;
    }
};