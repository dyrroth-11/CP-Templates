 vector<int> adj[N], adj1[N];
 bool vis[N];
 vector<int> o,c;

    void dfs1 (int v) {
        vis[v] = 1;
        for (auto x:adj[v])
            if (!vis[x])
                dfs1 (x);
        o.push_back (v);
    }

    void dfs2 (int v) {
        vis[v]=0;
        c.push_back (v);
        for (auto x:adj1[v])
            if (vis[x])
                dfs2 (x);
    }

    int main() {
        // input and other stuff.

        for (int i=0; i<n; ++i)
            if (!vis[i])
                dfs1 (i);
        for (int i=0; i<n; ++i) {
            int v = o[n-1-i];
            if (vis[v]) {
                dfs2 (v);
                //... printing next component ...
                c.clear();
            }
        }
    }