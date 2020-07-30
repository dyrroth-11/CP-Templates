struct DSU{
  vector<ll> dsu;
  DSU(ll n){
    loop(i,0,n)
      dsu.pb(i);
  }
  ll root(ll x){
    if(x==dsu[x])
      return x;
    return dsu[x] = root(dsu[x]);
  }
  void merge(ll x, ll y){
    if((x=root(x))==(y=root(y)))
      return;
    dsu[x]=y;
  }
};