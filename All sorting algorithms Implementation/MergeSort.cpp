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

void mergeelements(int l,int mid,int r){
int temp[r-l+1];
int i=l,j=mid+1,k=0;
while(i<=mid && j<=r){
    if(arr[i]<=arr[j]){
        temp[k]=arr[i];
        i++;
        k++;
    }
    else{
        temp[k]=arr[j];
        j++;
        k++;
    }
}
while(i<=mid){temp[k]=arr[i];k++;i++;}
while(j<=r){temp[k]=arr[j];j++;k++;}
for(int i=0;i<k;i++)arr[l+i]=temp[i];
return;
}

void mergesort(int l,int r){
if(l==r)return;
 int mid=(l+r)/2;
 mergesort(l,mid);
 mergesort(mid+1,r);
 mergeelements(l,mid,r);
}

int main(){
//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T=1;
//cin>>T;
while(T--){
cin>>n;
for(int i=0;i<n;i++)cin>>arr[i];
mergesort(0,n-1);

for(int i=0;i<n;i++)cout<<arr[i]<<" ";
}
return 0;
}
