#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=11;
int a[N];
int n,cnt;
int flag=0;
int st[N];
void dfs(int x,int y)
{
	if(flag)return;
	if(x>n)
	{
		if(y*2==cnt) 
		{
			flag=1;
			printf("%d\n",st[0]);
			fo(i,1,st[0]) printf("%d ",st[i]);
		}
		return;
	}
	st[++st[0]]=x;
	dfs(x+1,y+a[x]);
	--st[0];
	dfs(x+1,y);
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]),cnt+=a[i];
	dfs(1,0);
	if(flag)return 0;
	printf("-1\n");
	return 0;
}











