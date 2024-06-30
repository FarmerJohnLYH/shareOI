#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <bitset>
#include<algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int INF=1000000007,N=1000005;

struct line {
	int l,r,id;

	bool operator <(line b) const {
		return r>b.r;
	}
} s[N];

priority_queue <line> pp;

bitset <N> prt,vis;

int read() {
	int x=0,v=1; char ch=getchar();
	for (;ch<'0'||ch>'9';v=(ch=='-')?(-1):(v),ch=getchar());
	for (;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());
	return x*v;
}

void write(int x) {
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
bool cmp(line a,line b) {
	return (a.l==b.l)?(a.r>b.r):(a.l<b.l);
}
int main() 
{
//	 freopen("failure.in","r",stdin);
//	 freopen("failure.out","w",stdout);
	 freopen("D:/LiuYuanHao/b.in","r",stdin);
	 freopen("D:/LiuYuanHao/b.out","w",stdout);
	read(); int n=read(),m=read(),ans=0,sz=0;
	fo(i,1,n) s[i].l=read(),s[i].r=read(),s[i].id=i;
	line top;
	sort(s+1,s+n+1,cmp);
	fo(i,1,m) pp.push(s[i]),++sz,vis[s[i].id]=1;
	top=pp.top(); ans=max(top.r-s[m].l,0); prt=vis;
	fo(i,m+1,n) 
	{
		pp.push(s[i]),++sz,vis[s[i].id]=1;
		top=pp.top();
		if (sz==m) 
		{
			int len=max(top.r-s[i].l,0);
			if (len>=ans) 
			{
				ans=len;
				prt=vis;
			}
		}
		if (sz>m) {
			vis[top.id]=0;
			pp.pop(),sz--;
		}
	}
	write(ans); puts("");
	fo(i,1,n) if (prt[i]) {
		write(i); putchar(' ');
	}
	return 0;
}
