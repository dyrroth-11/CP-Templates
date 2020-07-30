void dfs(int x){
  vis[x]=true;
  for(int i=0;i<adj[x].size();i++){
    if(vis[adj[x][i]]==false)dfs(adj[x][i]);
  }
  return;
}