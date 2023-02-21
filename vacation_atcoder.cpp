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
// int dp[101][N];
int a[100069],b[100069],c[100069];
int da[100069],db[100069],dc[100069];

int f(int i,char ch){
    if(i==-1) return 0;

    if(ch=='a'){
        if(da[i]!=-1) return da[i];
        int first = b[i] + f(i-1,'b');
        int second = c[i] + f(i-1,'c');
        return da[i] = max(first,second);
    }
    if(ch=='b'){
        if(db[i]!=-1) return db[i];
        int first = a[i] + f(i-1,'a');
        int second = c[i] + f(i-1,'c');
        return db[i] = max(first,second);
    }
    if(ch=='c'){
        if(dc[i]!=-1) return dc[i];
        int first = b[i] + f(i-1,'b');
        int second = a[i] + f(i-1,'a');
        return dc[i] = max(first,second);
    }
    return 0;
}

int main(){
    int n; cin>>n;
    // int a[n],b[n],c[n];
    fi(n) cin>>a[i]>>b[i]>>c[i];
    memset(da,-1,sizeof(da));
    memset(db,-1,sizeof(db));
    memset(dc,-1,sizeof(dc));
    int ans1 = f(n-1,'a');
    int ans2 = f(n-1,'b');
    int ans3 = f(n-1,'c');
    cout<< max(ans1,max(ans2,ans3));
}