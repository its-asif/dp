class Solution {
public:
int dp[2569];

 int lis(int n,vector<int> &v){
    int ans=1;
    if(dp[n]!=-1) return dp[n];

    for (int i = 0; i < n; ++i)
    {
        if(v[i]<v[n]){
            ans = max(ans, lis(i,v)+1);
        }
    }
    return dp[n] = ans;
 }

int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int mx=0;
        memset(dp,-1,sizeof(dp));
        for (int i = 0; i < n; ++i)
        {
            mx = max(mx,lis(i,nums));
        }
        return mx;
    }
};