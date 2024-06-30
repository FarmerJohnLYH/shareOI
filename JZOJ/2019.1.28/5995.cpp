#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=100100;
int n,ans;
char s[N];
void dfs(int l,int r,int d)
{
	if(l>=r-1)
	{
		if(l==r) ans=max(ans,d);
		else ans=max(ans,d+s[l]-'0');
		return ;
	}
	int mid=(r+l)/2;
	dfs(l,mid,d+s[mid]-'0'),dfs(mid+1,r,d+s[mid]-'0');
}
int main()
{
	freopen("cost.in","r",stdin);
	freopen("cost.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%s",s+1);n=strlen(s+1);
	dfs(1,n,0);
	printf("%d\n",ans);
	return 0;
}








