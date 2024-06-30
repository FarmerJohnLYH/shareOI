ll qsm(ll a,ll b)
{
	ll x=1;
	a%=Mo,b%=(Mo-1);
	while(b)
	{
		x=((b&1))?((x*(a))%Mo):(x);
		b>>=1,a=(a*a)%Mo;
	}
	return x;
}