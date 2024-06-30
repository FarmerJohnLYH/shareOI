#pragma GCC optimize(2) 
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=1000010;
const ll mo=2030417821;
int a,c,k,m,n;
char s[N];
ll f[21][N],g[21][N],p[N],v[21][N];
ll val(ll x)
{
	return((a*x+c)/k)%m;
}
int main()
{
	freopen("zero.in","r",stdin);
	freopen("zero.out","w",stdout);
//	 freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d%d%d%d%d\n",&a,&c,&k,&m,&n);
	scanf("%s\n",s+1);
	p[0]=1,p[1]=998244353;
	fo(i,2,N-100) p[i]=p[i-1]*p[1]%mo;
	fo(i,0,m)
		f[0][i]=(i*2>=m),g[0][i]=val(i);
	fo(i,1,n) v[0][i]=s[i]-'0'; 
	fo(l,1,20) fo(i,0,m)
	{
		f[l][i]=(f[l-1][i]*p[1<<(l-1)]%mo+f[l-1][g[l-1][i]])%mo;
		g[l][i]=g[l-1][g[l-1][i]];
		v[l][i]=(v[l-1][i]*p[1<<(l-1)]%mo+v[l-1][i+(1<<(l-1))])%mo;
	}
	int ans=0;
	fo(i,0,m)
	{
		ll p=1,q=g[0][i],flag=0;
		fo(k,0,20)if((1<<k)&n)
		{
			if(v[k][p]!=f[k][q]) 
			{
				flag=1;
				break;
			}
			p=p+(1<<k),q=g[k][q];
		}
		if(!flag)++ans;
	}
	printf("%d\n",ans);
	return 0;
}











