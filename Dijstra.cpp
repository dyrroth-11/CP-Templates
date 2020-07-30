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
bool vis[N];
ll d[N];
 
int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T=1;
//cin>>T;
while(T--){
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++){
    int x,y,z;
    cin>>x>>y>>z;x--;y--;
    adj[x].pb({z,y});
}
priority_queue<ar<ll,2> , vector<ar<ll,2>> ,greater<ar<ll,2>>> q;
memset(d,0x3f,sizeof(d));
d[0]=0;
q.push({0,0});
while(!q.empty()){
    ar<ll,2> x;
    x=q.top();
    q.pop();
    if(d[x[1]]<x[0])continue;
    for(auto y:adj[x[1]]){
        if(d[y[1]]>d[x[1]]+y[0]){
            d[y[1]]=d[x[1]]+y[0];
            q.push({d[y[1]],y[1]});
        }
    }
}
for(int i=0;i<n;i++)cout<<d[i]<<" ";
}
return 0;
}