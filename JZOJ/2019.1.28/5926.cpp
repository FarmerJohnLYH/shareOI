 #pragma GCC optimize(2)
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=200200,M=500500,A=1000010000;
int n,m,L,c[N];
struct Edg{
	int x,y;ll v;
}e[M];
bool cmp(Edg a,Edg b)
{
	return(a.v<b.v);
}
int f[N];
int gf(int x){return(f[x]==x)?x:(f[x]=gf(f[x]));}
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int sz[N];
struct segtree{
	int sn[2],v;
}t[N*33];
vector<int> ve[N];
int rot[N],pt;
int query(int x,int l,int r,int p)
{
	if(l>=p)
		return t[x].v;
	if(!x||r<p)return 0;
	int mid=(l+r)>>1;
	if(p>mid) return(query(t[x].sn[1],mid+1,r,p));
	else return(query(t[x].sn[0],l,mid,p)+query(t[x].sn[1],mid+1,r,p));
}
int query2(int x,int l,int r,int p)
{
	if(r<=p)
		return t[x].v;
	if(l>p||!x)return 0;
	int mid=(l+r)>>1;
	if(p<=mid) return(query2(t[x].sn[0],l,mid,p));
	else return(query2(t[x].sn[0],l,mid,p)+query2(t[x].sn[1],mid+1,r,p));
}
void update(int x)
{
	t[x].v=0;
	fo(i,0,1)
		if(t[x].sn[i]) t[x].v+=t[t[x].sn[i]].v;
} 
void ins(int &x,int l,int r,int p,int v)
{
	if(!x) x=++pt;
	if(l==r)
	{
		t[x].v+=v;
		return;
	}
	int mid=(l+r)>>1;
	if(p>mid)ins(t[x].sn[1],mid+1,r,p,v);
	else ins(t[x].sn[0],l,mid,p,v);
	update(x);
}
void comb(int x,int y,int l,int r)
{
	if(l==r)
	{
		t[y].v+=t[x].v;
		return;
	}
	int mid=(l+r)>>1;
	fo(i,0,1)
	if(t[x].sn[i])
	{
		if((!t[y].sn[i])) t[y].sn[i]=t[x].sn[i];
		else 
		{
			if(i==0)comb(t[x].sn[i],t[y].sn[i],l,mid);
			else comb(t[x].sn[i],t[y].sn[i],mid+1,r);
		}
	}
	update(y);
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
// 	freopen("D:/LiuYuanHao/b2.in","r",stdin);
	n=read(),m=read(),L=read();
	pt=n;
	fo(i,1,n) 
	{
		c[i]=read(),f[i]=i;++c[i];
		sz[i]=1;ve[i].push_back(c[i]);
		rot[i]=i;
		ins(rot[i],1,A,c[i],1);
	}
	fo(i,1,m)
		e[i].x=read(),e[i].y=read(),e[i].v=read();
	ll sum=0;ll cntt=0; 
	sort(e+1,e+1+m,cmp);
	fo(i,1,m)
	{
		int fx,fy;
		if((fx=gf(e[i].x))!=(fy=gf(e[i].y))) 
		{
			if(sz[fx]>sz[fy])swap(fx,fy),swap(e[i].x,e[i].y);
			f[fx]=gf(fy);
			ll cnt=0;
			for(int pp=ve[fx].size()-1,l=0;l<=pp;++l)
			{
				cnt+=query(rot[fy],1,A,ve[fx][l]+L);
				cnt+=query2(rot[fy],1,A,ve[fx][l]-max(L,1));
				ve[fy].push_back(ve[fx][l]);
			}
			ve[fx].clear();
			comb(rot[fx],rot[fy],1,A);
			sum+=e[i].v*cnt;
			cntt+=cnt;
			sz[fy]+=sz[fx];
		}
	}
	printf("%lld\n",sum);
	return 0;
}







