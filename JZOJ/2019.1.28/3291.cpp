#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=50500,mo=2678963;
ll n,m;
char a[N],b[N];
struct pali{
	ll sz,cnt[N];
	int to[N][26],fail[N];
	int len[N],ln,las;
	int st[N];
	int gf(int x){while(st[ln-len[x]-1]!=st[ln])x=fail[x];return(x);}
	void add(int x)
	{
		st[++ln]=x;int now=gf(las);
		if(!to[now][x]) len[++sz]=len[now]+2,fail[sz]=to[gf(fail[now])][x],to[now][x]=sz;
		++cnt[las=to[now][x]];
	}
	void init()
	{
		len[sz=1]=-1;
		fail[0]=1;
		st[0]=-1;
		las=0;
	}
	void count()
	{
		fd(i,sz,1) cnt[fail[i]]+=cnt[i];
	}
}t[2];
ll ans=0;
void dfs(int x,int y)
{
	if(t[0].len[x]>0&&t[1].len[y]>0) ans=ans+t[0].cnt[x]*t[1].cnt[y];
	fo(i,0,25)
	if(t[0].to[x][i]&&t[1].to[y][i])
		dfs(t[0].to[x][i],t[1].to[y][i]);
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%s",a+1);scanf("%s",b+1);
	n=strlen(a+1),m=strlen(b+1);
	t[0].init(),t[1].init();
	fo(i,1,n) 
		t[0].add(a[i]-'A');
	fo(i,1,m) t[1].add(b[i]-'A');
	t[0].count(),t[1].count();
	dfs(0,0);dfs(1,1);
	printf("%lld\n",ans);
	return 0;
}











