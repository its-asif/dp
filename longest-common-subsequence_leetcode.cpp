class Solution {
public:
int dp[1001][1001];
    int f(int n, int m, string &s1, string &s2){
        if(n<0 || m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];

        if(s1[n]==s2[m]) return 1 + f(n-1,m-1,s1,s2);
        else{
            return dp[n][m] = max(f(n,m-1,s1,s2),f(n-1,m,s1,s2));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size()-1;
        int m = text2.size()-1;
        memset(dp,-1,sizeof(dp));
        return f(n,m,text1,text2);
    }
};