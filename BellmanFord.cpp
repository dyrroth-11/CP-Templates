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
const int N=501;
 
//vector<ar<ll,2>> adj[N];
//bool vis[N];
ll d[N][N];
int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T=1;
//cin>>T;
while(T--){
int n,m,q;
cin>>n>>m>>q;
memset(d,0x3f,sizeof(d));
for(int i=0;i<m;i++){
    int x,y,z;
    cin>>x>>y>>z;x--;y--;
    d[x][y]=min(d[x][y],z+0LL);
    d[y][x]=min(d[y][x],z+0LL);
}
for(int i=0;i<n;i++)d[i][i]=0;
for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
    }
}
while(q--){
    int x,y;
    cin>>x>>y;x--;y--;
    if(d[x][y]>=1e18)cout<<"-1\n";
    else cout<<d[x][y]<<"\n";
}
}
return