class Solution {
public:
int dp[12][10069];

int f(int ind,vector<int>& coins, int amount){
    if(ind==0){
        return (amount%coins[0]==0) ;
    }
    if(dp[ind][amount]!=-1) return dp[ind][amount];

    int notTake = f(ind-1,coins,amount);
    int take = 0;
    if(coins[ind]<=amount) take = f(ind,coins,amount-coins[ind]);

    return dp[ind][amount] = take + notTake;
}

int change(int amount, vector<int>& coins)  {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        return f(n-1,coins,amount);
}
};