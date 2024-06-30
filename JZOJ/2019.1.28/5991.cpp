#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=22;
ll a[N],n,c,d[N];
int main()
{
	// freopen("juice.in","r",stdin);
	// freopen("juice.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld",&n);
	fo(i,1,n) scanf("%lld",&d[i]),d[i]*=2,d[0]+=d[i];
	sort(d+1,d+1+n);
	fo(k,1,n)
	if(a[0]%k==0)
	{
		ll hd=2,tl=n,v=d[0]/k;
		fo(i,1,n) a[i]=d[i]%v;
		sort(a+1,a+1+n);
		c=a[1];while(!c && hd<=tl) c=a[hd],++hd;
		int flag=0;
		while(hd<=tl)
		{
			if(c==v) c=a[hd],++hd;
			else 
			if(c>v)
			{
				flag=1;
				break;
			}
			else 
			{
				if(c+a[hd]>=v)
				{
					c=c+a[hd]-v,++hd;
					if(c==0&&hd<=tl) c=a[hd],++hd;			
				}
				else 
				{
					c=c+a[tl]-v,--tl;
					if(c==0&&hd<=tl) c=a[hd],++hd;
				}
			}
			if(c<0) 
			{
				flag=1;
				break;
			}
		}
		if(c>v) flag=1;
		if(!flag)
		{
			printf("%d\n",k);
			return 0;
		}
	}
	return 0;
}

