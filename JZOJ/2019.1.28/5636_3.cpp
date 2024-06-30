#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll N=100100;
ll phi[N];
ll w[N];
ll n,mo,q,t,tw;
ll ph(ll x){
	ll ans=x;
	for (ll i=2;i*i<=x;i++){
		if (x%i==0){
			ans=ans/i*(i-1);
			while (x%i==0)x/=i;
		}
	}
	if (x>1)ans=ans/x*(x-1);
	return ans;
}
ll power(ll a,ll b,ll mo){
	ll ans=1;
	while (b){
		if (b&1)ans=ans*a%mo;
		a=a*a%mo;
		b>>=1;
	}return ans;
}
ll solve(ll l,ll r,ll mox){
	ll mo=phi[mox];
	if (mo<=1)return 0;
	if (l==r)return w[l]%mo;
	if (tw>l)return power(w[l],solve(l+1,r,mox+1)+phi[mox+1],phi[mox]);
	return power(w[l],solve(l+1,r,mox),mo);
}
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n>>mo;
	scanf("%lld%lld",&n,&Mo);
	fo(i,1,n) scanf("%lld",&w[i]);
	while (mo>1)
	{
		phi[++t]=mo;
		mo=ph(mo);
	}phi[++t]=1; 
	mo=phi[1];
	for (cin>>q;q--;){
		ll l,r;
		scanf("%lld%lld",&l,&r);
		ll a=w[r];tw=l;
		for (ll i=r-1;i>=l;i--){
			ll b=1;
			while (a--&&w[i]>1){
				b=b*w[i];
				if (b>mo){tw=i+1;break;}
			}a=b;
			if (tw==i+1)break;
		}if (w[r]>mo)tw=r;
		printf("%lld\n",solve(l,r,1));
	}
}