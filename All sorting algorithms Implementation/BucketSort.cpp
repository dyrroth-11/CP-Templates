#include <bits/stdc++.h>
using namespace std;
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
const int N=100005;
int n;
float arr[N];
int heap[N];
int p;

void bucketsort(){
vector<float> a[n];
for(int i=0;i<n;i++){
    int x=n*arr[i];
    a[x].pb(arr[i]);
}
for(int i=0;i<n;i++){
    sort(a[i].begin(),a[i].end());
}
int cnt=0;
for(int i=0;i<n;i++){
    for(int j=0;j<a[i].size();j++){
        arr[cnt++]=a[i][j];
    }
}

}


int main(){
//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T=1;
//cin>>T;
while(T--){
cin>>n;
for(int i=0;i<n;i++){cin>>arr[i];}
bucketsort();
for(int i=0;i<n;i++){
cout<<arr[i]<<" ";
}
}
return 0;
}
