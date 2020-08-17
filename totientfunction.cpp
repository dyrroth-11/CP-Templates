ll phi(ll n)
{
	ll ans=1;
	for(ll i=2;i*i<=n;++i)
	{
		if(n%i==0)
		{
			ll count=1;
			while(n%i==0)
			{
				n/=i;count*=i;
			}
			ans*=(count-count/i);
		}
	}
	if(n>1)ans*=n-1;
	return ans;
}