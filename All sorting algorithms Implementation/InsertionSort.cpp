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


int main(){
//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T=1;
//cin>>T;
while(T--){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)cin>>arr[i];

for(int i=1;i<n;i++){
        int cnt=i;
    while(cnt>0 && arr[cnt]<arr[cnt-1]){
        swap(arr[cnt],arr[cnt-1]);
        cnt--;
    }
}

for(int i=0;i<n;i++)cout<<arr[i]<<" ";
}
return 0;
}
