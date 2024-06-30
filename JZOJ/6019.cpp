#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second 
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long double db;
const int N=1001000;
const db eps=1e-8;
typedef pair<int,db> PI;
#define abs(x) (((x)<0)?(-(x)):(x))
int n,a[N];
db f;char s[N];
PI c[N];
bool cmp(PI a,PI b)
{return (a.se<b.se||(a.se==b.se&&a.fi<b.fi));}
db ans;int x,p;
int main()
{
	  freopen("real.in","r",stdin);
	  freopen("real.out","w",stdout);
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
	scanf("%Lf",&f);
	scanf("%s",s+1);n=strlen(s+1);
	fo(i,1,n) a[i]=s[i]-'0'+a[i-1],c[i].se=f*i-a[i],c[i].fi=i;
	++n;
	sort(c+1,c+1+n,cmp);
	p=-1;
	fo(i,2,n)
	{
		db tmp=(c[i].se-c[i-1].se);int y=abs(c[i].fi-c[i-1].fi),t=min(c[i].fi,c[i-1].fi);
		if(p==-1 || ans*y-tmp*x>eps || (abs(ans*y-tmp*x)<eps && t<p))
			ans=tmp,x=y,p=t;
	}
	printf("%d\n",p);
	return 0;
}








