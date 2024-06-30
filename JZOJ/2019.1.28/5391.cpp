#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int N = 22;
int n,a,b;
int x[N],ans;
bool bz[N];
struct node{
	int x,y,cm;
}y[N];
int read()
{
	int n = 0;
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
bool cmp(node x,node y)
{
	return x.cm>y.cm;
}
void dfs(int fl,int s)
{
	if (s >= ans) return;
	if (fl > n)
	{
		ans = s;
		return;
	}
	if (bz[y[fl].x] || bz[y[fl].y]) dfs(fl + 1,s);
	else
	{
		bz[y[fl].x] = 1;
		dfs(fl + 1,s + x[y[fl].x]);
		bz[y[fl].x] = 0;

		bz[y[fl].y] = 1;
		dfs(fl + 1,s + x[y[fl].y]);
		bz[y[fl].y] = 0;
	}
}

int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	n = read(),a = read(),b = read();
	fo(i,1,n)
	{
		y[i].x = read(),y[i].y = read();
		y[i].cm = y[i].x * y[i].y;
		x[y[i].x] += a,x[y[i].y] += b;
	}
	sort(y + 1,y + 1 + n,cmp);
	ans = oo;
	dfs(1,0);
	printf("%d", ans);
	return 0;
}
