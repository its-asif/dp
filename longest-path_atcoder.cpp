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

const int N = 1e5 + 69;
ll dp[N];
vector<int> g[N];

int f(int i){
    if(g[i].size()==0) return 0;
    if(dp[i]!=-1) return dp[i];

    int ans = 0;
    for (int j = 0; j < g[i].size(); ++j)
    {
        int ttt = 1+f(g[i][j]);
        ans = max(ans,ttt);
    }
    return dp[i] = ans;
}

int main(){
    int n,m; cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
        int x,y; cin>>x>>y;
        g[x].push_back(y);
    }
    memset(dp,-1,sizeof(dp));
    int ans= INT_MIN;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, f(i));
    }
    cout<<ans;
}

