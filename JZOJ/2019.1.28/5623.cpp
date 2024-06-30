#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x),asdfgh=(y);i>=asdfgh;--i)
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
const int N=100100;
int n,q;
char st[N];
int p[N],p0;
int ans[10];
void work(int bg,int en)
{
	p0=0;
//	memset(p,0,sizeof p);
	fo(i,bg,en) 
	{
		p[++p0]=st[i]-'0';
		if(st[i]=='<') p[p0]=11;
		if(st[i]=='>') p[p0]=12;
	}
	int now=1,fx=1;
	while(now>0&&now<=p0)
	{
		int flag=0;
		if(p[now]<10) ++ans[p[now]--];
		else if(p[now]==12) fx=1,flag=now;
		else if(p[now]==11) fx=-1,flag=now;
		now+=fx;
		while(now>0&&now<=p0&&p[now]<0) now+=fx;
		if(flag&&p[now]>10) p[flag]=-1;
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/b2.in","r",stdin);
//	freopen("D:/LiuYuanHao/b.out","w",stdout);
	freopen("program.in","r",stdin);
	freopen("program.out","w",stdout); 
	scanf("%d%d",&n,&q);
	scanf("%s",st+1);
	fo(i,1,q)
	{
		memset(ans,0,sizeof ans);
		int x,y;
		scanf("%d%d",&x,&y);
		work(x,y);
		fo(i,0,9) printf("%d ",ans[i]);printf("\n");
	}
	return 0;
}











