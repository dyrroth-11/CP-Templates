/*
    ıllıllı 𝔻𝓎Ｒｒ𝕠𝐭𝐇 ıllıllı
 
*/
#include <bits/stdc++.h>
using namespace std;
#define N 20005
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
 
int main(){
/*ios_base::sync_with_stdio(false);
cin.tie(NULL);*/
int T=1;
//cin>>T;
while(T--){
int n,q;
cin>>n>>q;
ll arr[n];
ll f[n];
for(int i=0;i<n;i++)f[i]=1000000001;
for(int i=0;i<n;i++)cin>>arr[i];
int k=sqrt(n);
for(int i=0;i<n;i++){
  f[i/k]=min(f[i/k],arr[i]);
}
while(q--){
    int l,r;
    cin>>l>>r;l--;r--;
    long long int ans=1000000001;
    if(l/k == r/k){
      for(int i=l;i<=r;i++)ans=min(ans,arr[i]);
    }
    else{
        for(int i=l;i<(l/k+1)*k;i++)ans=min(ans,arr[i]);
        for(int i=l/k+1;i<r/k;i++)ans=min(ans,f[i]);
        for(int i=(r/k)*k;i<=r;i++)ans=min(ans,arr[i]);
    }
    cout<<ans<<"\n";
 
}
 
}
return 0;
}