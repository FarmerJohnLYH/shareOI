#pragma GCC optimize(2)
//#include <ctime>
#include <queue>
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
const int N=100100,M=200200,K=55,NK=N*K;
int T;
int n,m,k,p;
struct node{
	int to,nex;
	int v;
}e[M],tf[M*K];
int tot_e,tot_tf;
int lase[N],last[NK];
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
void link(int x,int y,int c)
{
	e[++tot_e].to=y,e[tot_e].nex=lase[x];
	e[tot_e].v=c;
	lase[x]=tot_e;
}
int dis[N],d[N*55];
int vis[N];
int ind[NK],f[NK];
void trsf(int x,int y)
{
	++ ind[y];
	tf[++tot_tf].to=y,tf[tot_tf].nex=last[x];
	last[x]=tot_tf;
}
inline int hash(int x,int y)
{
	return(x+y*n);
}
typedef pair<int,int> pr;
priority_queue<pr> q;
__attribute__((optimize("O2")))
void Get_dis()
{
	dis[1]=0, q.push(pr(0 , 1));
    while(!q.empty())
    {
        int x = q.top().second;
		q.pop();
        if(vis[x]!=T+1) 
        {
	        vis[x] = T+1;
	        for(int i = lase[x] ; i ; i = e[i].nex)
	            if(dis[e[i].to] > dis[x] + e[i].v)
	                dis[e[i].to] = dis[x] + e[i].v , q.push(pr(-dis[e[i].to] , e[i].to));
        }
    }
}
__attribute__((optimize("O2")))
int main()
{
	freopen("park.in","r",stdin);
	freopen("park.out","w",stdout);
//	freopen("D:/LiuYuanHao/park8.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		//clear
		memset(dis,127,sizeof dis);
//		memset(vis,0,sizeof vis);
		memset(f,0,sizeof f);
		memset(ind,0,sizeof ind);
		memset(lase,0,sizeof lase);
		memset(last,0,sizeof last);
		tot_e=tot_tf=0;
		
		n=read(),m=read(),k=read(),p=read();
		int nk=hash(n,k);
		fo(i,1,m)
		{
			int x=read(),y=read(),c=read();
			link(x,y,c);
		}
		Get_dis();		
		fo(i,1,n) fo(j,0,k)
		{
			int fr=hash(i,j);
			for (int tmp=lase[i];tmp;tmp=e[tmp].nex)
			{
				int to=e[tmp].to,l=dis[i]+j+e[tmp].v-dis[to];
				if(l<=k)
					trsf(fr,hash(to,l));
			}
		}
		int hd=0,tl=0;
		f[hash(1,0)]=1;
		fo(i,1,nk)
			if(!ind[i]) d[++tl]=i;
			
		while(hd++<tl)
		{
			int now=d[hd];
			for (register int tmp=last[now];tmp;tmp=tf[tmp].nex)
			{
				int to=tf[tmp].to;
				f[to]+=f[now];
				while(f[to]>=p) f[to]-=p;
				if(!(--ind[to]))
					d[++tl]=to;
			}
		}
		int flag=0,ans=0;
		fo(j,0,k)
		{
			int pp=hash(n,j);
			if(ind[pp]) 
			{
				flag=1;
				break;
			}
			ans=(ans+f[pp]);
			while(ans>=p) ans-=p;
		}
		if(flag)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
