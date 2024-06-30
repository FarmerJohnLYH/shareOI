#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=1001000;
char s[N];
int a[N];
int n,d[N][2],d0;
int st[26][2];
int nex[N],f[N];
int main()
{
	 freopen("bracket.in","r",stdin);
	 freopen("bracket.out","w",stdout);
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
	scanf("%s",s+1);n=strlen(s+1);
	fo(i,1,n)
	{
		a[i]=s[i]-'a';
		if(st[a[i]][0]) 
		{
			if(!st[a[i]][1])st[a[i]][1]=i;
		}
		else st[a[i]][0]=i;
	}
	fo(i,1,n-1) 
	if(!nex[i])
	{
		d0=1;
		d[1][0]=a[i],d[1][1]=i;
		fo(k,i+1,n)
		{
			if(d0>0&&d[d0][0]==a[k]) 
			{
				nex[d[d0][1]]=k;
				--d0;
			}
			else d[++d0][0]=a[k],d[d0][1]=k;
			if(d0==0&&nex[k+1])break;
		}
	}
	fd(i,n-1,1)
		if(nex[i]) f[i]=f[nex[i]+1]+1;
	long long ans=0;
	fo(i,1,n) ans=ans+f[i];
	printf("%lld\n",ans);
	return 0;
}








