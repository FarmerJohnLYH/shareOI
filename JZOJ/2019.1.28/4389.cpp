#include<cstdio>
#include<cstring>
#include<iostream>
#define oo 2139062143
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=22,M=11,P=(1<<M);
struct node{
	int x,y,s;
	node(int x_=0,int y_=0,int s_=0)
	{
		x=x_,y=y_,s=s_;
	}
}d[N*N*P],st;
int fx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m,v[M];
int a[N][N],dis[N][N][P];
int vis[N][N][P];
char S[N][N];
int jd(int x,int y)
{
	return(x>=1&&x<=n&&y>=1&&y<=m);
}
int mi(int x){return(1<<(x-1));}
void solve()
{
	memset(dis,127,sizeof dis);
	int hd=0,tl=1;st.s=0;
	d[tl]=st;
	vis[st.x][st.y][0]=1;dis[st.x][st.y][0]=0;
	while(hd++<tl)
	{
		node nw=d[hd];
		fo(fy,0,3)
		{
			int xx=nw.x+fx[fy][0],yy=nw.y+fx[fy][1];
			if(jd(xx,yy))
			if(S[xx][yy]=='.')
			{
				int sts=nw.s;
				if(fy==1)sts^=a[nw.x][nw.y];
				else if(fy==3)sts^=a[xx][yy];
				if(dis[xx][yy][sts]>dis[nw.x][nw.y][nw.s]+1)
				{	
					dis[xx][yy][sts]=dis[nw.x][nw.y][nw.s]+1;
					if(!vis[xx][yy][sts])
					{
						vis[xx][yy][sts]=1;
						d[++tl]=node(xx,yy,sts);
					}
				}
			}
		}
		vis[nw.x][nw.y][nw.s]=0;
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/c1.in","r",stdin);
	scanf("%d%d",&n,&m);
	int mp=0,al=0;
	fo(i,1,n)
	{
		scanf("%s",S[i]+1);
		fo(j,1,m) if(S[i][j]>='0'&&S[i][j]<='8') ++mp,S[i][j]=S[i][j]-'0';
	}
	memset(v,128,sizeof v);
	fo(i,1,mp) scanf("%d",&v[i]);
	al=mp;
	fo(i,1,n) fo(j,1,m) 
	{
		if(S[i][j]=='B') S[i][j]=++mp;
		if(S[i][j]=='S') st.x=i,st.y=j,S[i][j]='.';
	}
	fo(i,1,n) fo(j,1,m) 
	if(S[i][j]=='.') fo(l,i+1,n) 
		if(S[l][j]>=1&&S[l][j]<=mp) 
			a[i][j]|=mi(S[l][j]);
	solve();
	ll ans=0;
	fo(i,0,mi(mp+1)-1)
	{
		ll tp=0;int flag=0;
		fo(j,1,mp) if(i&(mi(j))) 
		{
			tp=tp+v[j];
			if(j>al) flag=1;
		}
		ans=max(ans,tp-dis[st.x][st.y][i]);
	}
	printf("%lld\n",ans);	
}
