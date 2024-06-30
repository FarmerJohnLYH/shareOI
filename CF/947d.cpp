#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=1001000;
int s[N],t[N],n,m,la[N],lb[N];
char c[N],d[N];
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%s\n",c+1);
	n=strlen(c+1);fo(i,1,n)
	{
		la[i]=la[i-1];
		s[i]=((c[i]!='A')?1:0)+s[i-1];	
		if(c[i]!='A') la[i]=i;
	}
	scanf("%s\n",d+1);
	m=strlen(d+1);fo(i,1,m) 
	{
		lb[i]=lb[i-1];
		t[i]=((d[i]!='A')?1:0)+t[i-1];
		if(d[i]!='A') lb[i]=i;
	}
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x,y,u,v;
		scanf("%d%d%d%d",&x,&y,&u,&v);
		int cnt1=s[y]-s[x-1],cnt2=t[v]-t[u-1];
		if(cnt1>cnt2||((cnt1+cnt2)&1))
		{
			printf("0");
			continue;
		}
		int tp=(y-max(la[y],x-1))-(v-max(lb[v],u-1));
		if(tp>=0)
		{
			if(cnt1==0&&cnt2!=0&&tp==0) printf("0");
			else if(tp%3==0)printf("1");
			else if(cnt1<cnt2) printf("1"); 
			else printf("0");
			continue;
		}
		else 
		printf("0");
	}
	printf("\n");
	return 0;
}











