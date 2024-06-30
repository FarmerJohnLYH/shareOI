#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x);asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int M=100100,LEN=60006000;
int n,m;
struct node{
	char c;
	int le,ri;
}a[LEN];
void ins(int x,char y)
{
	a[++n].c=y,a[n].le=x,a[n].ri=a[x].ri;
	a[a[n].le].ri=n,a[a[n].ri].le=n;
}
void del(int x)
{
	a[a[x].le].ri=a[x].ri,a[a[x].ri].le=a[x].le;
}
int find(int x)
{
	int rt=0;
	fo(i,1,x) rt=a[rt].ri;
	return rt;
}
int main()
{
	freopen("editor.in","r",stdin);
	freopen("editor.out","w",stdout);
//	freopen("D:/LiuYuanHao/b1.in","r",stdin);
	scanf("%d\n",&m);
	while(m--)
	{
		char typ,ch;
		int x,y,l,r;
		scanf("%c",&typ);
		if(typ=='I')
		{
			scanf("%d %c\n",&x,&ch);
			int now=find(x);
			ins(now,ch);
		}
		if(typ=='D')
		{
			scanf("%d %d\n",&x,&y);
			int now=find(x);
			fo(i,1,y-x+1)
				del(now),now=a[now].ri;
		}
		if(typ=='C')
		{
			scanf("%d %d %d\n",&l,&r,&x);
			int now=find(x),fr=find(l); 
			fo(i,1,r-l+1)
			{
				ins(now,a[fr].c);
				fr=a[fr].ri,now=a[now].ri;
			}
		}
		if(typ=='R')
		{
			scanf("%d %d\n",&x,&y);
			int fx=find(x),fy=find(y);
			fo(i,1,(y-x+1)/2)
			{
				swap(a[fx].c,a[fy].c);
				fx=a[fx].ri,fy=a[fy].le;
			}
		}
		if(typ=='Q')
		{
			scanf("%d\n",&x);
			int now=find(x);
			printf("%c",a[now].c);
		}
	}
}











