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
int arr[N];
int heap[N];
int p;

void jaadu(int x){
int l=2*x+1;
int r=2*x+2;
int cnt=x;
if(l<p && heap[l]<heap[cnt])cnt=l;
if(r<p && heap[r]<heap[cnt]) cnt=r;
if(cnt != x){
    swap(heap[x],heap[cnt]);
    jaadu(cnt);
}
}

void insrt(int x){
    heap[p]=x;
    int i=p;
    p++;
    while(i!=0 && heap[(i-1)/2]>heap[i]){
        int t=heap[(i-1)/2];
        heap[(i-1)/2]=heap[i];
        heap[i]=t;
        i=(i-1)/2;
    }
    //cout<<heap[0]<<"  --\n";
}
int get_max(){
int k=heap[0];
p--;
heap[0]=heap[p];
jaadu(0);
return k;
}


int main(){
//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T=1;
//cin>>T;
while(T--){
cin>>n;
for(int i=0;i<n;i++){cin>>arr[i];insrt(arr[i]);}

for(int i=0;i<n;i++)cout<<get_max()<<" ";
}
return 0;
}
