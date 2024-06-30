#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fi first
#define se second
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef pair<int,int> PI;
const int N=300300,NOD=6006000;
int n,m;
char st[N],dc[5050];
PI a[N];int tm=0;
struct acmat{
	int chd[NOD][26],tot,cnt[NOD],val[NOD];
	int fail[NOD],dep[NOD];
	void insert(char *p)
	{
		int len=strlen(p+1),w=0;
		fo(i,1,len)
		{
			if(!chd[w][p[i]-'a'])
			{
				chd[w][p[i]-'a']=++tot;
				dep[tot]=dep[w]+1;
			}
			w=chd[w][p[i]-'a'];
		}
		++cnt[w];
	}
	queue<int> q;
	void getfail()
	{
		fail[0]=0;
		fo(i,0,25)
		if(chd[0][i])
			q.push(chd[0][i]);
		while(!q.empty())
		{
			int now=q.front();q.pop();
			fo(i,0,25)
			{
				int u=chd[now][i];
				if(!u) 
				{
					chd[now][i]=chd[fail[now]][i];
					continue;
				}
				q.push(u);
				int v=fail[now];
				while(!chd[v][i]&&v) v=fail[v];
				fail[u]=chd[v][i];
			}
		}
	}
	void valc()
	{
		fo(i,1,tot) 
		if(cnt[i]) val[i]=dep[i];
		fo(i,0,25)
		if(chd[0][i])
			q.push(chd[0][i]);
		while(!q.empty())
		{
			int now=q.front();q.pop();
			fo(i,0,25)
			if(chd[now][i][dep]>dep[now])
			{
				int u=chd[now][i];
				if(!u) continue;
				q.push(u);
				if(fail[u][val])
					val[u]=max(val[u],fail[u][val]);
			}
		}/*
		fo(i,1,tot)
		{
			printf("%d %d\n",val[i],dep[i]);
		}*/
	}
	void query()
	{
		int p=0;
		fo(i,1,n)
		{
			int v=st[i]-'a';
			while(!chd[p][v]&&p) p=fail[p];
			p=chd[p][v];
			if(p&&val[p])
			{
				a[++tm].fi=i-val[p]+1;
				a[tm].se=i;
			}
		}
	}
}ac;
bool cmp(PI a,PI b)
{
	return(a.fi<b.fi||(a.fi==b.fi&&a.se>b.se));
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d\n",&n);
	scanf("%s\n",st+1);
	scanf("%d\n",&m);
	fo(i,1,m)
	{
		scanf("%s",dc+1);
		ac.insert(dc);
	}
	ac.getfail();
	ac.valc();
	ac.query();
	int ans=0;
	if(tm)
	{
		sort(a+1,a+1+tm,cmp);
		PI w=a[1];
		fo(i,2,tm)
		if(a[i].fi!=a[i-1].fi)
		{
			if(a[i].fi<=w.se+1) w.se=max(w.se,a[i].se);
			else ans+=w.se-w.fi+1,w=a[i];
		}
		ans+=w.se-w.fi+1;/*
		fo(i,1,tm)
		{
			printf("%d:%d %d\n",i,a[i].fi,a[i].se);
			
		}*/
	}
	printf("%d\n",n-ans);
	return 0;
}











