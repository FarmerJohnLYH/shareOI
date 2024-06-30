#include <queue>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int N=110,M=22;
struct node{
	int c,s,t,r;
	int v;
}a[N];
bool cmp(node a,node b)
{
	return(a.s<b.s);
}
int _,n,m;
priority_queue<PI> q;
PI p[M]; 
void clear(priority_queue<PI>& q)
{
    priority_queue<PI> empty;
    swap(empty, q);
}
int main()
{
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d",&_);
	while(_--)
	{
		int flag=0;
		clear(q);
		memset(a,0,sizeof a);
		scanf("%d%d",&n,&m);
		int mx=0;
		fo(i,1,n)
		{
			scanf("%d%d%d",&a[i].c,&a[i].s,&a[i].t);
			a[i].r=a[i].c-a[i].t;
			mx=max(mx,a[i].t);
		}
		sort(a+1,a+1+n,cmp);
		int a0=0,tm=0;
		while(tm<=mx)
		{
			++tm;
			while(a[a0+1].s<=tm&&a0<=n)
			{
				if(a0+1>n)break;
				PI tmp;
				tmp.fi=a[++a0].r;
				tmp.se=a0;
				q.push(tmp);
			}
			int p0=0;
			fo(i,1,m)
			{
				if(q.empty()) break;
				p[++p0]=q.top();
				q.pop();	
			}
			fo(i,1,p0)
			{
				if(a[p[i].se].t<=tm)
				{
					if(p[i].fi+a[p[i].se].t>0) 
					{
						flag=1;
						goto End;
					}
				}
				else
				{
					if(((--p[i].fi)+a[p[i].se].t)+tm>=a[p[i].se].t)
					{
						flag=1;
						goto End;
					}
					else
					if(((p[i].fi+a[p[i].se].t)>0))
						q.push(p[i]);
				}
			}
		}
		End:
		if(!flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}









