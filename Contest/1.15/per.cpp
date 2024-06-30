#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
const int N=300300,M=N*33;
int n,a[N],p[N],an[N];
int ans,t[M][2],v[M];
int tot=1;
void add(int va,int id)
{
	int p=1,d=1;
	fd(i,30,0)
	{
		d=((1<<i)&va)?1:0;
		if(!t[p][d]) t[p][d]=++tot;
		p=t[p][d];
	}
	v[p]=a[id];
}
int query(int va)
{
	int p=1,d;
	fd(i,30,0)
	{
		d=((1<<i)&va)?1:0;
		if(t[p][d]) p=t[p][d];
		else p=t[p][d^1];
	}
	return(v[p]^va);
}
int find(int m)
{
	int f=a[1]&m;
	fo(i,2,n) 
		if((a[i]&m)!=f)
		{
			return 1;
		}
	return 0;
}
const int mo=19260817;
int d[2][N],tn[2][mo+100];
struct node{
	priority_queue<int> a,de;
	int top()
	{ 
		int x=a.top();
		while(!de.empty() && x==de.top()) a.pop(),de.pop(),x=a.top();
		return x;
	}
	void push(int x)
	{a.push(x);}
	void del(int x)
	{de.push(x);}
}g[2];
priority_queue<int> q[2][mo+100];
int ha[mo],id[2][N];
int h(int x)
{
	int v=x;
	x=x*11ll%mo;
	while(ha[x]!=v&&ha[x]!=-1) x=(x+1)%mo;
	if(ha[x]==-1)ha[x]=v;
	return x;
}
int d0[2],all;
int be[N];
void solve()
{
	fo(k,0,1)
		fo(i,1,d0[k])
			++tn[k][h(d[k][i])],q[k][h(d[k][i])].push(-id[k][i]),g[k].push(-id[k][i]);
	fo(i,1,d0[0])
		all+=tn[0][h(d[0][i])]*tn[1][h(a[0]^d[0][i])];
	int x=1;
	if(tn[be[x]^1][h(a[x]^a[0])]==all) ++x;
	fo(i,1,n-1)
	{
//		int y=q[be[]].;
	}
}
int main()
{
	// freopen("per.in","r",stdin);
	// freopen("per.out","w",stdout);
	return 0;
	scanf("%d",&n);
	int le=0,ri;
	fo(i,1,n)
	{
		scanf("%d",&a[i]);
		le=max(le,a[i]);a[0]^=a[i];
	}
	memset(ha,255,sizeof ha);
	ri=1;
	while(ri<le) ri<<=1;
	int qaq=ri;
	--ri;
	le=0;
	while(!find(qaq)) qaq>>=1;
	fo(i,1,n)
		if(a[i]&qaq) add(a[i],i),d[0][++d0[0]]=a[i],id[0][d0[0]]=i,be[i]=0;
	ans=(1ll<<31)-1;
	fo(i,1,n) 
		if((a[i]&qaq)==0) 
			ans=min(ans,query(a[i])),d[1][++d0[1]]=a[i],id[1][d0[1]]=i,be[i]=1;
	
	solve();
	
	fo(i,1,n) printf("%d ",p[i]);
	return 0;
}







