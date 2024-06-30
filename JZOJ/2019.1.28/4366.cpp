//n log n
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=4*100100;
int n;
char st[N];
int p[N];
void mc()
{
	int mid=0;
	p[1]=0;
	fo(i,2,n)
	{
		p[i]=(p[mid]+mid>i)?(min(p[mid-(i-mid)],p[mid]+mid-i)-1):0;
		while(st[i+p[i]+1]==st[i-p[i]-1]) ++p[i];
		if(p[i]+i>p[mid]+mid) mid=i;
	}
}
int t[N*4];
void insert(int x,int l,int r,int p,int v)
{
	if(l==r)
	{
		t[x]=max(t[x],v);
		return;
	}
	int mid=(l+r)>>1;
	if(p>mid) insert(x<<1|1,mid+1,r,p,v);
	else insert(x<<1,l,mid,p,v);
	t[x]=max(t[x<<1],t[x<<1|1]);
}
int query(int x,int l,int r,int ql,int qr)
{
	if(l>=ql&&r<=qr)
	{
		return(t[x]);
	}
	int mid=(l+r)>>1,rt=0;
	if(ql<=mid) rt=max(rt,query(x<<1,l,mid,ql,qr));
	if(qr>mid) rt=max(rt,query(x<<1|1,mid+1,r,ql,qr));
	return rt;	
}
int solve(int x,int l,int r,int v)
{
	int rt=oo;
	if(t[x]<v) return rt;
	if(l==r) return(l);
	int mid=(l+r)>>1;
	rt=min(rt,solve(x<<1,l,mid,v));
	if(rt==oo)rt=min(rt,solve(x<<1|1,mid+1,r,v));
	return rt;
}
int q(int x,int l,int r,int ql,int qr,int v)
{
	int rt=oo;
	if(t[x]<v) return rt;
	if(l>=ql&&r<=qr)
	{
		rt=solve(x,l,r,v);
		return rt;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) rt=min(rt,q(x<<1,l,mid,ql,qr,v));
	if(rt==oo&&qr>mid) rt=min(rt,q(x<<1|1,mid+1,r,ql,qr,v));
	return rt;	
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	int mm;
	scanf("%s",st+1);n=(mm=strlen(st+1))*2+1;
	st[0]='-',st[n]='#';
	fd(i,n-1,1)
	{
		if(i&1) st[i]='#';
		else st[i]=st[(i/2)];
	}
	int nm=n-1;
	n=(n-1)*2+1;
	fo(i,nm+1,n) st[i]=st[i-nm];
	st[n+1]='+';
	nm=strlen(st)-2;
	mc();
	insert(1,1,n,1,1+p[1]);	
	int ans=0;
	fo(i,2,n)
	{
/*		int l=max(i-mm,1),r=i-1;
		if(query(1,1,n,l,r)>=i-p[i]) 
		{
			int f=r;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(query(1,1,n,l,mid)>=i-p[i]) r=mid-1,f=mid;
				else l=mid+1;
			}
			ans=max(ans,i-f);
		}
*/		
		int f=q(1,1,n,max(i-mm,1),i-1,i-p[i]);
		ans=max(ans,i-f);
		insert(1,1,n,i,i+p[i]);	
	}
	printf("%d\n",ans);
	return 0;
}











