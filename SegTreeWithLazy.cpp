class stree {
public:
    int s;
    vll t;
    vll lazy;
    void build (int n) {
        s = n;
        t = vll(4*n,0);
        lazy = vll(4*n,0);
    }
 
    void push(int v, int tl, int tr) {
        if (lazy[v] == 0) return;
        t[v] += lazy[v]*(tr-tl+1);
        if(v<2*s) {
            lazy[v*2] += lazy[v];
            lazy[v*2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
 
    void update (int v, int tl, int tr, int l, int r, ll add) {
        push(v, tl, tr);
        if (l > r)
            return;
        if (l == tl && tr == r) {
            lazy[v] += add;
            push(v, tl, tr);
        }
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), add);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
            t[v] = (t[v*2] + t[v*2 + 1]);
        }
    }
 
    ll gsum (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l > r)
            return 0;
        if (l == tl && tr == r) {
            push(v, tl, tr);
            return t[v];
        }
        else {
            int tm = (tl + tr) / 2;
            ll ret = gsum(v*2, tl, tm, l, min(r,tm)) +
                         gsum(v*2+1, tm+1, tr, max(l,tm+1), r);
            t[v] = t[v*2] + t[v*2 + 1];
            return ret;
        }
    }
}seg;

int a[N+1]={};