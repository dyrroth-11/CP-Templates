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

int part(int l,int r){
int j=l;
int k=arr[r];
for(int i=l;i<=r-1;i++){
    if(arr[i]<k){
        swap(arr[j],arr[i]);
        j++;
    }
}
swap(arr[j],arr[r]);
return j;
}

void quicksort(int l,int r){
if(l<r){
    int k=part(l,r);
    quicksort(l,k-1);
    quicksort(k+1,r);
}

}

int main(){
//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T=1;
//cin>>T;
while(T--){
cin>>n;
for(int i=0;i<n;i++){cin>>arr[i];}

quicksort(0,n-1);

for(int i=0;i<n;i++)cout<<arr[i]<<" ";
}
return 0;
}
