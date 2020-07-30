void bfs(int x){
queue<int> q;
q.push(x);
d[x]=0;
p[x]=-1;
vis[x]=true;
while(!q.empty()){
  int s=q.front();
  q.pop();
  for(int i=0;i<adj[s].size();i++){
    if(vis[adj[s][i]]==false){
      vis[adj[s][i]]=true;
      d[adj[s][i]]=d[s]+1;
      p[adj[s][i]]=s;
      q.push(adj[s][i]);
    }
  }
}
return;
}