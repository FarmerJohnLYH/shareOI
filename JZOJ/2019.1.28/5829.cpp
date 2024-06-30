#pragma GCC optimize(3)
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> PI;
const int N=100100;
char s[N];
int n,m;
	int t[26][N*4];
	PI tag[26][N*4];
	int ql,qr;
	void down(int x,int le,int ri,int tp)
	{
		int mid=(le+ri)>>1;
		if(tag[tp][x].fi==1)
		{
			fo(i,0,1) 
			{
				int y=x<<1|i;
				if(tag[tp][y].fi==0) tag[tp][y]=tag[tp][x];
				else tag[tp][y].se+=tag[tp][x].se;
				if(tag[tp][y].fi==1) 
				{
					if(y&1) t[tp][y]+=tag[tp][x].se*(ri-mid);
					else t[tp][y]+=tag[tp][x].se*(mid+1-le);
				}
				else if(tag[tp][y].fi==2) 
				{
					if(y&1) t[tp][y]=tag[tp][x].se*(ri-mid);
					else t[tp][y]=tag[tp][x].se*(mid+1-le);
				}
			}
		}else
		{
			fo(i,0,1)
			{
				int y=x<<1|i;
				if(tag[tp][y].fi==2) 
					tag[tp][y].se=tag[tp][x].se;
				else tag[tp][y]=tag[tp][x];
				if(y&1) t[tp][y]=tag[tp][x].se*(ri-mid);
				else t[tp][y]=tag[tp][x].se*(mid+1-le);
			}
		}
		tag[tp][x].fi=tag[tp][x].se=0;
		t[tp][x]=t[tp][x<<1]+t[tp][x<<1|1];
	}
	void add(int x,int l,int r,int tp)
	{
		if(tag[tp][x].fi&&l!=r) down(x,l,r,tp);
		if(ql<=l&&r<=qr) 
		{
			t[tp][x]+=r-l+1;
			tag[tp][x].fi=1,tag[tp][x].se=1;
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) add(x<<1,l,mid,tp);
		if(qr>mid) add(x<<1|1,mid+1,r,tp);
		t[tp][x]=t[tp][x<<1]+t[tp][x<<1|1];
	}
	int query(int x,int l,int r,int tp)
	{
		if(tag[tp][x].fi&&l!=r) down(x,l,r,tp);
		if(ql<=l&&r<=qr)
		{
			int qaq=t[tp][x];
			t[tp][x]=0;
			tag[tp][x].fi=2,tag[tp][x].se=0;	
			return(qaq);
		}
		int mid=(l+r)>>1,rt=0;
		if(ql<=mid) rt+=query(x<<1,l,mid,tp);
		if(qr>mid) rt+=query(x<<1|1,mid+1,r,tp);
		t[tp][x]=t[tp][x<<1]+t[tp][x<<1|1];
		return rt;
	}
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int main()
{
//	freopen("D:/LiuYuanHao/a1.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	fo(i,1,n) ql=qr=i,add(1,1,n,s[i]-'a');
	fo(i,1,m)
	{
		int l=read(),r=read(),tp=read(),cnt;
		cnt=l-1;
		fo(p,0,25)
		{
			ql=l,qr=r;
			int k=(tp==1)?p:(25-p),nw=query(1,1,n,k);
			if(nw)
			{
				ql=cnt+1,qr=cnt+nw;
				add(1,1,n,k),cnt+=nw;
				if(cnt==r)break;
			}
		}
	}
	fo(i,1,n) fo(j,0,25)
	{
		ql=qr=i;
		if(query(1,1,n,j))
		{
			putchar(j+'a');
			break;
		}
	} 
	putchar('\n');
	return 0;
}











