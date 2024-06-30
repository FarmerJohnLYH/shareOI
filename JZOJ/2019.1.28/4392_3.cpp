#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll ans[30],a,n,Ans,lim,l,r,sum;
ll ban[100100];
ll c[300],p[]={2,3,5,7,11,13,17,19,23,29,31};
ll gcd(ll a,ll b){
	if (a<b)return gcd(b,a);
	if (b==0)return a;
	return gcd(b,a%b);
}
void dfs(ll x,ll lcm,ll w){
	if (x>lim){
		if (lcm==1)w=0;
		sum+=w*(r/lcm-l/lcm);
		return;
	}
	dfs(x+1,lcm,w);
	if (c[x])dfs(x+1,lcm*x/gcd(x,lcm),-w);
}
void solve(ll d){
	lim=d;sum=n;ll i;
	memset(c,0,sizeof c);
	for (i=0;p[i]<=lim;i++)c[p[i]]=1;
	for (l=n,r=2*n,i=2;i<=lim;i++,l+=n,r+=n){
		dfs(i,1,-1);
		c[i*2]=c[i*3]=c[i*5]=1;c[i]=0;
	}
	ans[d]=n*d-sum;
}
int main(){
	cin>>a>>n;
	Ans=(a-1)*n+1;
	for (ll i=2;i*i<=a;i++){
		ll k=1,cnt=0;
		if (ban[i])continue;
		while (k<=a/i){
			k*=i,cnt++;
			if (k*k<=a)ban[k]=1;
		}
		if (!ans[cnt])solve(cnt);
		Ans-=ans[cnt];
	}
	cout<<Ans<<endl;
}
