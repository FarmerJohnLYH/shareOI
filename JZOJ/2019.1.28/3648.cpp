#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=2002000;
int n;
char a[N],b[N];
int exa[N],exb[N];
int c[N];
void exkmp(int *ex,char *s,char *t)
{
	memset(c,0,sizeof c);
//	s[n+1]='-',t[n+1]='+';
	int p=0,e=0;
	c[1]=n;
	fo(i,2,n)
	{
		
		c[i]=c[i-p+1];
		if(i+c[i]-1>=e)
		{
			c[i]=max(0,e-i);
			while(t[i+c[i]]==t[c[i]+1]&&i+c[i]<=n) ++c[i];
		}
		if(i+c[i]-1>e)p=i,e=i+c[i]-1;
	}
	p=0,e=0;
	fo(i,1,n)
	{
		
		ex[i]=c[i-p+1];
		if(i+ex[i]-1>=e)
		{
			ex[i]=max(0,e-i);
			while(s[i+ex[i]]==t[ex[i]+1]&&i+ex[i]<=n) ++ex[i];
		}
		if(i+ex[i]-1>e)p=i,e=i+ex[i]-1;
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/b4.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d\n",&n);
	scanf("%s\n",a+1);
	scanf("%s\n",b+1);
	exkmp(exa,a,b);
	exkmp(exb,b,a);
	int ans=0;
	fo(i,1,n)
		if(exb[exa[i]+1]>=i-1) ans=max(ans,i-1+exa[i]);
	printf("%d\n",ans);
	return 0;
}











