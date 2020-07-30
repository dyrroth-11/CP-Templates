struct node
{
    ll sum;
}fake={0};
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ memset(a,0,sizeof(a)); }
    node tree[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.sum=max(a.sum,b.sum);
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret={val};
        return ret;
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            tree[v]=make_node(a[st]);
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void update(ll v,ll st,ll en,ll in,ll val)
    {
        ll mid=(st+en)>>1;
        if(st==en)
        {
            tree[v]=make_node(val);
            a[st]=val;
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in,val);
        else
            update(v<<1 | 1,mid+1,en,in,val);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    int  query(ll v,ll st,ll en,ll k,ll l)
    {
        if(tree[v].sum<k)return -1;
        if(en<l)return -1;
        if(en==st )return st;
        ll mid=(st+en)>>1;
        ll x=query(v<<1,st,mid,k,l);
        if(x==-1)return query(v<<1 | 1,mid+1,en,k,l);
        return  x;
    }
}seg;
 