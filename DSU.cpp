struct DSU{
  vector<ll> dsu;
  vector<ll> s;
  DSU(ll n){
    for(int i=0;i<n;i++)
     {dsu.pb(i);
      s.pb(1);}
  }
  ll root(ll x){
    if(x==dsu[x])
      return x;
      ll k=root(dsu[x]);
    return dsu[x] =k;
  }
  bool merge(ll x, ll y){
    if((x=root(x))==(y=root(y)))
      return 0;
    dsu[x]=y;
    s[y]+=s[x];
    //s[x]=s[y];
    return 1;
  }
};
