#include <bits/stdc++.h> 
int dp[169][1069];
int f(int i,vector<int> &weight, vector<int> &value, int w){
	if(i==-1)  return 0 ;
	if(dp[i][w]!=-1) return dp[i][w];
	
	int notTake = 0 + f(i-1,weight,value,w);
	int take = INT_MIN;
	if(weight[i]<=w) take = value[i] + f(i-1,weight,value,w-weight[i]);

	return dp[i][w] = max(take, notTake);
}

int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight) 
{
	memset(dp,-1,sizeof(dp));
	return f(n-1,weight,value,maxWeight);
}