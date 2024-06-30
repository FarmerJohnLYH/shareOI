#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define oo 2139062143
using namespace std;
const int N=200200,PRI1=39916801/*11!+1*/,PRI2=9191891;
int n,m;
char st[N];
struct node{
	int x,y;
}c[N];
int h1[N],h2[N];
int p1[N],p2[N];
int hash1(int sta)
{
	int l=sta,r=sta+m-1;
	return(1ll*(h1[r]-h1[l-1]+PRI1)%PRI1*p1[n-r]%PRI1);
}
int hash2(int sta)
{
	int l=sta,r=sta+m-1;
	return(1ll*(h2[r]-h2[l-1]+PRI2)%PRI2*p2[n-r]%PRI2);
}
bool cmp(node a,node b)
{
	return(a.x<b.x||(a.x==b.x&&a.y<b.y));
}
int main()
{
	// freopen("article.in","r",stdin);
	// freopen("article.out","w",stdout);
	freopen("D:/LiuYuanHao/park1.in","r",stdin);
	// freopen("D:/LiuYuanHao/park1.ans","w",stdout);
	scanf("%d%d\n%s",&n,&m,st+1);
	p1[0]=p2[0]=1,p1[1]=9209,p2[1]=3881;
	fo(i,2,n+100) p1[i]=(1ll*p1[i-1]*p1[1])%PRI1,p2[i]=(1ll*p2[i-1]*p2[1])%PRI2; 
//	h1[0]=p1[1],h2[0]=p2[1];
	fo(i,1,n) 
	{
		int now=st[i]-'a'+1;
		h1[i]=(h1[i-1]+1ll*now*p1[i])%PRI1,h2[i]=(h2[i-1]+1ll*now*p2[i])%PRI2;
			
	}int tot=n-m+1;
	int tmp1=hash1(1);
	int tmp2=hash1(2); 
	fo(i,1,tot)
		c[i].x=hash1(i),c[i].y=hash2(i);	
	sort(c+1,c+1+tot,cmp);
	int ans=tot;
	fo(i,2,tot)
		if(c[i].x==c[i-1].x&&c[i].y==c[i-1].y) 
			--ans;
	printf("%d\n",ans);
	return 0;
}
