#include <bits/stdc++.h>

long long f(long long n,long long arr[]){
    if(arr[n]!=0) return arr[n];
    
    return arr[n]=(f(n-1,arr)+f(n-2,arr))% 1000000007;
}

long long countDistinctWays(long long nStairs) {
    long long arr[nStairs+1] ={-1};
    arr[0]=1;
    arr[1]=1;

    return f(nStairs,arr);
}