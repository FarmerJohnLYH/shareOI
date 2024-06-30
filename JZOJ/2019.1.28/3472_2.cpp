#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define oo 2139062143
using namespace std;
typedef long long ll;
typedef double db;
const int N=110,M=11,K=9,Mo=1e9+7,LEN=33;
const int P=K*LEN;
int n,k;
char st[K][LEN];
int d[P];
int all;
int f[N][P][256+100];
bool bcz[26];
int chos[26];
struct ACAutoMachine{
	int chd[P][26];
	int fail[P];
	int sz,pt,bz[P];
	void insert(char *c,int w)
	{
		int len=strlen(c),tmp=0;
		fo(i,0,len-1)
		{
			int now=c[i]-'a';
			if(!chd[tmp][now])
			{
				chd[tmp][now]=++sz;
				memset(chd[sz],0,sizeof chd[sz]);
			}
			tmp=chd[tmp][now];
		}
		bz[tmp]|=(1<<(w-1));
	}
	bool pd[P];
	void Getfail()
	{
		memset(pd,0,sizeof pd);
		int hd=0,tl=0;
		pd[0]=1;
		fo(i,0,25)
		if(chd[0][i]) d[++tl]=chd[0][i],pd[d[tl]]=1;
	
		while(hd++<tl)
		{
			int now=d[hd];
			fo(i,0,25)
			if(chd[now][i])
			{
				int v=chd[now][i];
				if(pd[v]) continue;
				pd[v]=1;
				d[++tl]=v;
				int rt=fail[now];
				while(!chd[rt][i]&&rt) rt=fail[rt];
				fail[v]=chd[rt][i];
			}			
		}	
		fo(i,0,sz)
		{
			bz[i]|=bz[fail[i]];
			fo(j,0,25)
			{
				int p=i;
				while(p&&!chd[p][j]) p=fail[p];
				if(chd[p][j]) next[i][j]=chd[p][j];
				else next[i][j]=0;
			}
		}
	}
	int dt[2][P][2];
	int tot[2];
	int next[P][25];
	void solve()
	{
		memset(f,0,sizeof f);
		f[0][0][0]=1;
		fo(i,0,n-1)
		{
			fo(j,0,sz)
			{
				fo(s,0,all)
				if(f[i][j][s])
				{
					fo(cc,1,chos[0])
					{
						int c=chos[cc];
						int jj=next[j][c],ss=s|bz[jj];
						f[i+1][jj][ss]=(f[i+1][jj][ss]+f[i][j][s])%Mo;
					}
				}
			}
		}
		int ans=0;
		fo(i,0,sz)
		{
			ans=(ans+f[n][i][all])%Mo;
		}
		printf("%d\n",ans);
	}
	void clear()
	{
		memset(bz,0,sizeof bz);
		memset(next,0,sizeof next);
		memset(fail,0,sizeof fail);
		memset(chd[0],0,sizeof chd[0]);	
		pt=sz=0;
	}	
}ac;
int m;
int main()
{
	freopen("D:/LiuYuanHao/a2.in","r",stdin);
	scanf("%d%d\n",&n,&k);
	fo(i,1,k)
	{
		scanf("%s\n",st[i]);
		ac.insert(st[i],i);
	}
	ac.Getfail();
	scanf("%d\n",&m);
	fo(i,1,m)
	{
		char tp=getchar();
		while(!(tp<='z'&&tp>='a')) tp=getchar();
		bcz[tp-'a']=1;
	}
	fo(i,0,25)
		if(bcz[i])chos[++chos[0]]=i;		
	all=(1<<k)-1;
	ac.solve();
	return 0;
}


