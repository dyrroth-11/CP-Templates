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

int Binary(int x){
int l=0,r=n-1;
while(l<r){
    int mid=(r+l)/2;
    if(arr[mid]==x)return mid+1;
    else if(arr[mid]>x)r=mid-1;
    else l=mid+1;
}
return -1;
}

int main(){
//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T=1;
//cin>>T;
while(T--){
int x;
cin>>n>>x;
for(int i=0;i<n;i++){cin>>arr[i];}
cout<<Binary(x)<<" ==\n";

}
return 0;
}
