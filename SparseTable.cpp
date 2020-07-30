struct node{
	int gcd;
	int mn;
	void assign(int v,int m){ gcd=v;mn=m; }
	void merge(node &l, node &r)
	{
		gcd = __gcd(l.gcd, r.gcd);
		mn=min(l.mn,r.mn);
	}
}zero;
 
struct sparsetable{
public:
	node st[N][K];
	long long n, k, sum_ans;
	long long log[N+1];
 
	void build(int a[], int n)
	{
		log[1] = 0;
		for (int i = 2; i <= N; i++)
		    log[i] = log[i/2] + 1;
 
		k = log2(n)+1;
		for (int i = 0; i < n; i++)
   			st[i][0].assign(a[i],a[i]);
 
   		for (int j = 1; j <= k; j++)
    		for (int i = 0; i + (1 << j) <= n; i++)
        		st[i][j].merge(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
	}
 
	pair<long long,long long > gcd_query(int L, int R)
	{
		long long j = log[R - L + 1];
		long long ret = __gcd(st[L][j].gcd, st[R - (1 << j) + 1][j].gcd);
		long long ret2 = min(st[L][j].mn,st[R-(1<<j) + 1][j].mn);
		return pair<long long ,long long >(ret,ret2);
	}
 
 
 
}st;