#include <bits/stdc++.h>
 
using namespace std;
 
#define mod 1000000007
#define ll long long int
#define mk make_pair
#define pb push_back
#define xx first
#define yy second
#define ar array
 
double pi=3.141592653589793238;
const int M = 1e9+7;
const int Nmax=5005;
const int MM = 1e7+1;
const int N=200010;
 
vector<ar<ll,2>> adj[N];
vector<int> ad[N];
bool vis[N];
bool vi[N];
ll d[N];
int p[N];
int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T=1;
//cin>>T;
while(T--){
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++){
    ll x,y,z;
    cin>>x>>y>>z;x--;y--;
    adj[x].pb({z,y});
}
memset(d,0xc0,sizeof(d));
d[0]=0;
for(int i=0;i<=n;i++){
    int flag=false;
    for(int j=0;j<n;j++){
        for(ar<ll,2> x: adj[j]){
            if( d[x[1]]>d[j]+x[0]){
                p[x[1]]=j;
                d[x[1]]=d[j]+x[0];
                if(i==n){
                    while(!vis[j]){
                        vis[j]=1;
                        j=p[j];
                    }
                    int u=j;
                    vector<int> ans;
                    ans.pb(u);
                    u=p[u];
                    while(u^j){
                        ans.pb(u);
                        u=p[u];
                    }
                    ans.pb(u);
                    cout<<"YES\n";
                    reverse(ans.begin(),ans.end() );
                    for(auto xx:ans)cout<<xx+1<<" ";
                    return 0;
                }
            }
        }
    }
}
cout<<"NO\n";
}
return