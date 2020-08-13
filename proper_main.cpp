#include<bits/stdc++.h>
using namespace std;
 
#define vvi             vector<vector<int>>
#define ld              long double
#define mod             1000000007
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vpii            vector<pair<int,int>>
#define fr(i,a,b)       for(int i = a; i < b; i += 1)
#define all(x)          x.begin(),x.end()
#define sz(a)           (int)(a.size())
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define input(a)        for(auto it = a.begin(); it != a.end(); it++) { int value; cin >> value; *it = value;}
#define print(a)        for(auto it = a.begin() ; it != a.end() ; it++){ cout << *it << " " ;}cout << '\n';
#define SS                      stringstream
#define db(...)                 __f(#__VA_ARGS__, __VA_ARGS__)
 
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
 
int power(int x ,int y )
{
    if( y == 0 )
        return 1;
    
    int temp = power(x,y/2);
    
    if( y % 2 == 0 )
        return temp*temp;
    else
        return x*temp*temp;
}
 
int fac[22001];
int power(int x, int y, int p) 
{ 
    int res = 1;      // Initialize result 
 
    x = x % p;  // Update x if it is more than or 
                // equal to p 
 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
 
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
 
// Returns n^(-1) mod p 
int modInverse(int n, int p) 
{ 
    return power(n, p-2, p); 
} 
 
 
// Returns nCr % p using Fermat's little 
// theorem. 
int nCrModPFermat(int n, int r, int p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
 
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
 
 
  return (fac[n]* modInverse(fac[r], p) % p * 
    modInverse(fac[n-r], p) % p) % p; 
}
 
 
struct info
{
    int x;
    info () : x(0) {};
};
 
int *arr;
 
struct SegTree
{
    int N;
    vector<info> st;
 
    SegTree(int n)
    {
        N = n;
        st.resize(4 * N + 5);
    }
 
    void merge(info &cur, info &l, info &r)
    {
        cur.x = max(l.x, r.x);
    }
 
    void Build(int node, int L, int R)
    {
        if (L == R)
        {
            st[node].x = arr[L];
            return;
        }
        int M = (L + R) / 2;
        Build(node * 2, L, M);
        Build(node * 2 + 1, M + 1, R);
        merge(st[node], st[node * 2], st[node * 2 + 1]);
    }
 
    info Query(int node, int L, int R, int i, int j)
    {
        if (j < L || i > R)
            return info();
        if (i <= L && R <= j)
            return st[node];
        int M = (L + R) / 2;
        info left = Query(node * 2, L, M, i, j);
        info right = Query(node * 2 + 1, M + 1, R, i, j);
        info cur;
        merge(cur, left, right);
        return cur;
    }
 
    void Update(int node, int L, int R, int pos, int val)
    {
        if (L == R)
        {
            st[node].x += val;
            return;
        }
        int M = (L + R) / 2;
        if (pos <= M)
            Update(node * 2, L, M, pos, val);
        else
            Update(node * 2 + 1, M + 1, R, pos, val);
 
        merge(st[node], st[node * 2], st[node * 2 + 1]);
    }
 
    info query(int l, int r) { return Query(1, 0, N, l, r); }
 
    void update(int pos, int val) { Update(1, 0, N, pos, val); }
 
    void build() { Build(1, 0, N); }
};
 
vector<vector<pair<int, int>>> adj;
 
int dijkstra(int s)
{
 
    int n = adj.size();
    vi d(n, inf);
    vi p(n, -1);
 
    d[s] = 0;
    set<pair<int, int> > q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
 
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
 
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
 
    if (d[n - 1] == inf)
        d[n - 1] = -1;
 
    return d[n - 1];
}

int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}
 
int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}
 
class union_find
{
 
public:
    int *pr;
    int *sz;
 
    union_find(int n)
    {
        pr = new int[n + 1];
        sz = new int[n + 1];
 
        for (int i = 1; i <= n; ++i)
            pr[i] = i, sz[i] = 1;
    }
 
    int root(int i)
    {
        if (pr[i] == i)
            return i;
 
        return pr[i] = root(pr[pr[i]]);
    }
 
    int find(int i, int j)
    {
        return (root(i) == root(j));
    }
 
    int un(int i, int j)
    {
        int u = root(i);
        int v = root(j);
 
        if (u == v)
            return 0;
 
        if (sz[u] < sz[v])
            swap(u, v);
 
        pr[v] = u;
        sz[u] += sz[v];
 
        return 1;
    }
};
 
void SieveOfEratosthenes(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
 
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        {  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
 
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          cout << p << " "; 
} 
 
 
 
vi primes;
 
  void sieve ()
  {
    int i, j;
    bitset <3200> bs;
    bs.set();
    bs[0]=bs[1]=0;
    for (i=2; i<=3180; i++)
    {
        if (bs[i]==1)
        {
            for (j=i*i; j<=3180; j+=i)
                bs[j]=0;
            primes.pb(i);
        }
    }
}
 
// vector<int> prefix_function (string Z) {
 
//     int n = (int) Z.length();
 
//     vector<int> F (n);
 
//      F[0]=0;
 
//     for (int i=1; i<n; ++i) {
 
//         int j = F[i-1];
 
//         while (j > 0 && Z[i] != Z[j])
 
//             j = F[j-1];
 
//         if (Z[i] == Z[j])  ++j;
 
//         F[i] = j;
 
//     }
 
//     return F;
 
// }
// vi Z(string s)
// {
//  int L = 0, R = 0;
// for (int i = 1; i < n; i++) 
// {
//     if (i > R) 
//     {
//         L = R = i;
//         while (R < n && s[R-L] == s[R]) 
//         {
//             R++;
//         }
//         z[i] = R-L; 
//         R--;
//     } 
//     else 
//     {
//         int k = i-L;
//         if (z[k] < R-i+1) 
//         {
//             z[i] = z[k];
//         } 
//         else 
//         {
//             L = i;
//             while (R < n && s[R-L] == s[R]) 
//             {
//                 R++;
//             }
//             z[i] = R-L; 
//             R--;
//         }
//     }
// }
//}

bool isPrime(int n)
{
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }
    
    return true;
}
 
void FASTIO()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
const int mxN = 1e5 + 100;
int n, d;
vector<pair<int,pii>> v;

void test_case()
{
    cin >> n >> d;
    v = vector<pair<int, pii>> (n);
    for(int i = 0; i < n; i++)
    {
        int t, s, d;
        cin >> d >> t >> s;
        v[i].ff = d;
        v[i].ss.ff = t;
        v[i].ss.ss = s;
        // db(d, t, s);
    }

    sort(all(v));
    int ans = 0;

    multiset<pair<int,int>> s;
    int j = 0;
    for(int i = 1; i <= d; i++)
    {
        while(j < n && v[j].ff == i)
        {
            s.insert({v[j].ss.ss, v[j].ss.ff});
            j += 1;
        }

        if(sz(s) == 0)
            continue;

        pii p = *(prev(s.end()));
        s.erase(s.find(p));
        if(p.ss == 1)
            continue;
        s.insert({p.ff, p.ss - 1});
    }

    for(auto it : s)
    {
        ans = ans + (it.ff * it.ss);
    }

    cout << ans << '\n';
}
 
int32_t main()
{
    FASTIO();
 
    int t;
    t = 1;
    cin >> t;
 
    for(int i = 1; i <= t; i++)
    {
        //cout << "Case #" << i << ": ";
        test_case();
    }
    return 0;
} 