#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=100100;
int f[2][N],n;
int ans;
int a[N],t[N];
vector<int> s[2][N];
int du[2][N];
int sz[N];
ll p1=19260817,p2=311,p3=1109,p4=727;
int rnd()
{
	p4=(p4*p2+p3)%p1;
	return (p4%2)?1:(-1);
}
#define lowbit(x) ((x)&(-x))
void add(int x,int v)
{
	while(x<=n) t[x]+=v,x+=lowbit(x);
}
int query(int x)
{
	int rt=0;
	while(x) rt+=t[x],x-=lowbit(x);
	return rt;
}
void run(int x,int c)
{
	for(int p=s[0][x].size()-1,i=0;i<=p;++i)
	{
		int tt=s[0][x][i];	
		run(tt);
	}
}
int solve()
{
	fo(i,1,n) 
	{
		a[i]=-2;t[i]=0;
		if(du[0][i]==0) a[i]=rnd(); 
	}
	fo(p,0,1)
	{
		run(rt[0],p);
		fo(k,0,1)
		if(check(rt[1])) return 1;	
	}
	return 0;
}
int main()
{
	// freopen("D:/LiuYuanHao/","r",stdin);
	freopen("cpp.in","r",stdin);
	freopen("cpp.out","w",stdout);
	scanf("%d",&n);
	fo(k,0,1) fo(i,1,n) 
	{
		scanf("%d",&f[k][i]);
		if(f[k][i]!=-1)
		{
			s[k][f[k][i]].push_back(i);
			++du[k][f[k][i]];
		} else rt[k]=i;
	}
	int eps=66;
	while(eps--)
	{
		if(solve())
		{
			printf("POSSIBLE\n");
			fo(i,1,n) printf("%d ",a[i]);
			return 0;
		}
	}
	printf("IMPOSSIBLE\n");
	return 0;
}








