class Solution {
public:
// const int N= 1e4;
int dp[12][10069];

int f(int ind,vector<int>& coins, int amount){
    int ans=1;
    if(dp[ind][amount]!=-1) return dp[ind][amount];
    if(ind==0){
        if(amount%coins[0]==0) return amount/coins[0];
        else return 1e8;
    }

    int notTake = f(ind-1,coins,amount);
    int take = INT_MAX;
    if(coins[ind]<=amount) take = 1 + f(ind,coins,amount-coins[ind]);

    return dp[ind][amount] = min(take, notTake);
}

int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        int x = f(n-1,coins,amount);
        if(x>=1e8) return -1;
        else return x;
}
};