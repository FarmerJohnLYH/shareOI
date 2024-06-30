#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=11;
int n,k;
vector<int> t[N];
int a[N][2];
int ans,c[N],f[N];
int dep[N];
int check()
{
	memset(c,0,sizeof c);
	fo(i,1,n)
	{
		int x=a[i][0],y=a[i][1];
		while(x!=y)
		{
			if(dep[x]<dep[y])swap(x,y);
			++c[x];x=f[x];
		}
	}
	int flag=0;
	fo(i,1,n)
	{
		if(c[i]>=2&&c[i]<k) return 0;
		if(c[i]==k) ++flag;
	}
	if(!flag)return 0;
	return 1;
}
void dfs(int x)
{
	if(x>k)
	{
		if(check()) 
			++ans;
		return;
	}
	fo(i,1,n) fo(j,i+1,n)
	{
		a[x][0]=i,a[x][1]=j;
		dfs(x+1);
	}
}
void run(int x)
{
	for(int p=t[x].size()-1,i=0;i<=p;++i)
	if(t[x][i]!=f[x])
	{
		f[t[x][i]]=x;
		dep[t[x][i]]=dep[x]+1;
		run(t[x][i]);
	}
}
int main()
{
	freopen("admirable.in","r",stdin);
	freopen("admirable.out","w",stdout);
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
	scanf("%d%d",&n,&k);
	fo(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		t[x].push_back(y),t[y].push_back(x);
	}
	dep[1]=1;
	run(1);
	dfs(1);
	printf("%d\n",ans);
	return 0;
}











