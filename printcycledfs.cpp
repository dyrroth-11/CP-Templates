#include <bits/stdc++.h>
 
using namespace std;
 
#define mod 1000000007
#define ll long long int
#define mk make_pair
#define pb push_back
#define xx first
#define yy second
 
 
double pi=3.141592653589793238;
const int M = 1e9+7;
const int Nmax=5005;
const int MM = 1e7+1;
const int N=200010;
vector<int> adj[N];
bool vis[N];
int p[N];
void dfs(int x ,int pa){
p[x]=pa;
vis[x]=1;
    for(auto i:adj[x]){
        if(i==pa)continue;
        else if(!vis[i])dfs(i,x);
        else{
            int k=x;
            vector<int> ans;
            while(k!=i){
                ans.pb(k);
                k=p[k];
            }
            ans.pb(i);
            ans.pb(x);
            cout<<ans.size()<<"\n";
            for(auto j:ans)cout<<j+1<<" ";
            exit(0);
        }
    }
}
 
int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T=1;
//cin>>T;
while(T--){
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;x--;y--;
    adj[x].pb(y);
    adj[y].pb(x);
 
}
for(int i=0;i<n;i++){
    if(!vis[i])dfs(i,-1);
}
cout<<"IMPOSSIBLE\n";
}
return