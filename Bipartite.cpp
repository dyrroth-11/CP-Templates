#include <bits/stdc++.h>
#define inf 1000000007
#define N 200005
using namespace std;
int n,m;
vector<int> adj[N];
bool vis[N]={};
//int p[N];
int d[N];
 
void bfs(int x){
queue<int> q;
q.push(x);
d[x]=1;
//p[x]=-1;
vis[x]=true;
while(!q.empty()){
  int s=q.front();
  q.pop();
  for(int i=0;i<adj[s].size();i++){
    if(vis[adj[s][i]]==false){
      vis[adj[s][i]]=true;
      d[adj[s][i]]=d[s]%2+1;
      //p[adj[s][i]]=s;
      q.push(adj[s][i]);
    }
    else if(d[adj[s][i]]==d[s]){
      cout<<"IMPOSSIBLE\n";
      exit;
    }
  }
}
return;
}
 
int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
int t=1;
//cin>>t;
while(t--){
cin>>n>>m;
int a,b;
for(int i=0;i<m;i++){
  cin>>a>>b;
  a--;b--;
  adj[a].push_back(b);
  adj[b].push_back(a);
}
for(int i=0;i<=n;i++)d[i]=inf;
for(int i=0;i<n;i++){
  if(!vis[i])bfs(i);
}
for(int i=0;i<n;i++)cout<<d[i]<<" ";
}
	return 0;
}