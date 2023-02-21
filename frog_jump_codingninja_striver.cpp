#include <bits/stdc++.h> 
int f(int idx, vector<int> &heights, int arr[]){
    if(arr[idx]!=0 || idx==0) return arr[idx];

    int first = f(idx-1,heights,arr) + abs( heights[idx] - heights[idx-1] ) ;
    int second = INT_MAX;
    if(idx>1) second = f(idx-2,heights,arr) + abs( heights[idx]-heights[idx-2]) ;
    return arr[idx]=min(first,second);
}

int frogJump(int n, vector<int> &heights)
{
    int arr[n]={0};
    return f(n-1,heights,arr);
}