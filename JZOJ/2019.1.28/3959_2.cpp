#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define fi first
#define se second 
using namespace std;
typedef pair<int,int> PI;
const int N=2*100100;
int cnt;
int n,m;
int l[N],r[N];
int a[N],a0,f[N];
struct node{
	int x,y,tp;
}q[N];
vector<int> t[N*4];
int gf(int x)
{
	return(f[x]==x?x:(f[x]=gf(f[x])));
}
void cg(int x,int le,int ri,int p,int cv)
{
	if(!t[x].empty())
	{
		int pq=t[x].size()-1;
		fo(i,0,pq)
		{
			int q=t[x][i];
			f[gf(q)]=cv;
			l[cv]=min(l[cv],l[q]);
			r[cv]=max(r[cv],r[q]);
		}
		t[x].clear();
	}
	if(le==ri)return;
	int mid=(le+ri)>>1;
	if(p<=mid) cg(x<<1,le,mid,p,cv);
	else cg(x<<1|1,mid+1,ri,p,cv);
}
void add(int x,int le,int ri,int ql,int qr,int cv)
{
	if(ql<=le&&ri<=qr) t[x].push_back(cv);
	else 
	{
		int mid=(le+ri)>>1;
		if(ql<=mid) add(x<<1,le,mid,ql,qr,cv);
		if(qr>mid) add(x<<1|1,mid+1,ri,ql,qr,cv);
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n)
	{
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		q[i].tp=tp,q[i].x=x,q[i].y=y;
		a[++a0]=x,a[++a0]=y;
	}
	sort(a+1,a+1+a0);
	fo(i,1,n) 
	if(q[i].tp==1)
		q[i].x=upper_bound(a+1,a+1+a0,q[i].x)-a,q[i].y=upper_bound(a+1,a+1+a0,q[i].y)-a;
	fo(i,1,n)
	{
		if(q[i].tp==1)
		{
			l[++cnt]=q[i].x,r[cnt]=q[i].y;
			f[cnt]=cnt;
			cg(1,1,a0,q[i].x,cnt),cg(1,1,a0,q[i].y,cnt);
			add(1,1,a0,l[cnt]+1,r[cnt]-1,cnt);
		}
		else
		{
			int fy=gf(q[i].x),fx=gf(q[i].y);
			if(fx==fy||(l[fx]<l[fy]&&l[fy]<r[fx])||(l[fx]<r[fy]&&r[fy]<r[fx]))
				printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}











