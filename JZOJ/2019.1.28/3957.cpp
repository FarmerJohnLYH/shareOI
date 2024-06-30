#include <cstdio>
#include <cstring>
#include <iostream>
#define oo (1ll<<60)
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define cl(x) memset(x,0,sizeof x);
using namespace std;
typedef long long ll; 
const int N=100100,mo=4982371;
int n,m;
int lc[N],rc[N],fa[N],root;
ll hs[3][4],ky[3][N],cnt[5][mo+1000];
ll le[3],ri[3];
ll ans;
void dfs(int x,int flag)
{
	if(lc[x])dfs(lc[x],flag);
	if(rc[x])dfs(rc[x],flag);
	
	if(lc[x])fo(i,0,2)le[i]=ky[i][lc[x]];else cl(le);
	if(rc[x])fo(i,0,2)ri[i]=ky[i][rc[x]];else cl(ri);
	fo(i,0,2) ky[i][x]=(0ll+hs[i][0]*le[i]+hs[i][1]*(ri[i]*ri[i])+hs[i][2]*(le[i]^ri[i])+hs[i][3])%mo;
	if(!flag) 
	{
		fo(i,0,2)++cnt[i][ky[i][x]];
	}
	else
	{
		ll rt=oo;
		fo(i,0,2) rt=min(rt,cnt[i][ky[i][x]]);
		ans=ans+rt;
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
	hs[0][0]=223,hs[0][1]=293,hs[0][2]=311,hs[0][3]=251,
	hs[1][0]=349,hs[1][1]=353,hs[1][2]=357,hs[1][3]=373,
	hs[2][0]=577,hs[2][1]=593,hs[2][2]=599,hs[2][3]=379;
	scanf("%d%d",&n,&m);
	fo(i,1,n)
	{
		scanf("%d%d",&lc[i],&rc[i]);
		if(lc[i]<0)lc[i]=0;if(rc[i]<0)rc[i]=0;
		fa[lc[i]]=fa[rc[i]]=i;
	}
	fa[0]=0;
	fo(i,1,n)if(!fa[i]){root=i;break;}
	dfs(root,0);
	cl(fa);cl(lc);cl(rc);cl(ky);
	fo(i,1,m)
	{
		scanf("%d%d",&lc[i],&rc[i]);
		if(lc[i]<0)lc[i]=0;if(rc[i]<0)rc[i]=0;
		fa[lc[i]]=fa[rc[i]]=i;
	}
	fa[0]=0;
	fo(i,1,n)if(!fa[i]){root=i;break;}
	ans=0;
	dfs(root,1);
	printf("%lld\n",ans);
	return 0;
}
