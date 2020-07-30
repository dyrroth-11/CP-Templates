#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
 
#define mod 1000000007
#define ll long long int
#define mk make_pair
#define pb push_back
#define xx first
#define yy second
 
 
double pi=3.141592653589793238;
const int M = 1e9+7;
const int Nmax=5005;
const int MM = 1e7+1;
const int N=200010;
 
 
int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T=1;
//cin>>T;
while(T--){
string a,b;
cin>>a>>b;
int aa=a.size();
int bb=b.size();
vector<vector<int>> dp(aa+1, vector<int>(bb+1,1e9));
dp[0][0]=0;
for(int i=0;i<=aa;i++){
    for(int j=0;j<=bb;j++){
        if(i)dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
        if(j)dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
        if(i && j) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(a[i-1]!=b[j-1]));
    }
}
cout<<dp[aa][bb]<<"\n";
}
return 0;
}