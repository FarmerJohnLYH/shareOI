#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
const int N=100100*2;
int n;
ll ans;
struct node{
	int x,y;
	ll cta,ctb;
}a[N];
bool cmp(node a,node b)
{
	return(a.x<b.x);
}
bool cmy(node a,node b)
{
	return(a.y>b.y);
}
int t[N];
int lowbit(int x){return(x)&(-x);};
void add(int x,int v)
{
	for(;x<=n*2;x+=lowbit(x)) t[x]+=v;
}
int qry(int x)
{
	int rt=0;
	for(;x;x-=lowbit(x))rt+=t[x];
	return rt;
}
priority_queue<PI> q;
void solve()
{
	memset(t,0,sizeof t);
	fo(i,1,n)
	{
		if(!q.empty())
		{
			PI p=q.top();p.fi=-p.fi;
			while(p.fi<a[i].x) 
			{
				a[p.se].ctb+=qry(a[p.se].y-1)-qry(a[p.se].x);
				q.pop();
				if(q.empty())break;
				p=q.top();p.fi=-p.fi;
			}
		}
		a[i].cta+=qry(a[i].x)+qry(2*n)-qry(a[i].y);
		a[i].ctb-=qry(a[i].y-1)-qry(a[i].x);
		add(a[i].y,1);
		q.push(make_pair(-a[i].y,i));
	}
	while(!q.empty())
	{
		PI p=q.top();p.fi=-p.fi;
		a[p.se].ctb+=qry(a[p.se].y-1)-qry(a[p.se].x);
		q.pop();
		if(q.empty())break;
	}
	memset(t,0,sizeof t);
	sort(a+1,a+1+n,cmy);
	fo(i,1,n)
	{
		a[i].cta+=qry(2*n)-qry(a[i].y);
		add(a[i].x,1);
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d\n",&n);
	fo(i,1,n)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
		a[i].cta=a[i].ctb=0;
	}
	sort(a+1,a+1+n,cmp);
	solve();
	sort(a+1,a+1+n,cmp);	
	fo(i,1,n)
		ans=ans+(1ll*(n-a[i].cta-a[i].ctb-1)*(a[i].cta+a[i].ctb)/2)+(1ll*a[i].cta*a[i].ctb);
	ans=(1ll*n*(n-1)*(n-2)/6)-ans;
	printf("%lld\n",ans);
	return 0;
}











