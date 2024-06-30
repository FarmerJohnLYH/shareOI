#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=1048576+233,all=(1<<20)-1;
ll n,f[2][N];
ll a[N];
ll read()
{
    char ch=' ';ll q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;ll n=q*w;return n;
}
ll buf[30],b0;
void write(ll x)
{
	b0=0;
	if(x==0)putchar('0');
	else
	while(x) buf[++b0]=x%10,x/=10;
	fd(i,b0,1) putchar(buf[i]+'0');
	putchar('\n');
}
int main()
{
	 freopen("D:/LiuYuanHao/a.in","r",stdin);
	 freopen("D:/LiuYuanHao/a.out","w",stdout);
	n=read();
	fo(i,1,n) 
	{
		scanf("%d",&a[i]);
//		a[i]=read();
		++f[0][a[i]];
		
	}
	fo(k,0,19)
	{
		int o=1^(k&1);
		memset(f[o],0,sizeof f[o]);
		fo(i,0,all)
		{
			f[o][i]+=f[k&1][i];
			if(i&(1<<(k)))
				f[o][i^(1<<(k))]+=f[k&1][i];	
		}
	}
	fo(i,0,1e6)
		write(f[0][i]);
	return 0;
}








