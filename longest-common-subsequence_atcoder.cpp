#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

#define fi(n) for(ll i=0; i<n; i++)
#define fj(n) for(ll j=0; j<n; j++)
#define rfi(n) for(ll i = n-1; i >=0; --i)
#define fa(n) for(auto i:n)
#define fa2(n) for(auto i:n) cout<<i<<' ';
#define llt ll t; cin>>t; while(t--)
#define lln ll n; cin>>n;
#define llnm ll n,m; cin>>n>>m;
#define llx ll x; cin>>x;
#define llxy ll x,y; cin>>x>>y;
#define llab ll a,b; cin>>a>>b;

#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define pbx ll xx; cin>> xx; v.pb(xx);
#define pbs string xx; cin>> xx; v.pb(xx);
#define all(x) x.begin(), x.end()
#define srt(x) sort(all(x))
#define rsrt(x) sort(all(x),greater<ll>())
#define veccin(n) vll v(n); fi(n) cin>>v[i];

#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/__gcd(a,b)))

#define endl "\n"
#define nl <<endl
#define sp <<' '
#define sps <<' '<<
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define C(x) cout<< x <<endl;
#define F i.first
#define S i.second
using namespace std;
// const int N = 1e5+69;
ll dp[3069][3069];

ll f(int i, int j,string &s1, string &s2){
    if(i==-1 || j==-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    
    if(s1[i]==s2[j]) return dp[i][j] = 1 + f(i-1,j-1,s1,s2); 
    else  return dp[i][j] = max( f(i-1,j,s1,s2), f(i,j-1,s1,s2));
}

int main(){
    string s1,s2; cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();
    memset(dp,-1,sizeof(dp));
    int x= f(n-1,m-1,s1,s2);
    int i=n-1,j=m-1;
    string s ="";
    if(x==0) return 0;
    while(i>-1 && j>-1){
        if(s1[i]==s2[j]){
            s += s1[i];
            i--;j--;
        }
        else if(dp[i-1][j] > dp[i][j-1] && i!=0) i--;
        else j--;
        if(s.size()==x) break;
    }
    reverse(s.begin(),s.end());
    cout<<s;
}

// Runtime Error 2