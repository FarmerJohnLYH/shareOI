#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=100100;
int n,m;
int a,b,w;
vector<int> f[N];
int ans;
int find(int x,int y)
{
	int l=1,r=f[x].size(),rt=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(y>f[x][mid-1]) rt=mid-1,l=mid+1;
		else r=mid-1;
	}
	return rt;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,m)
	{
		scanf("%d%d%d",&a,&b,&w);
		if(f[b].empty())f[b].push_back(w);
		else f[b][0]=min(f[b][0],w);	
		if(!f[a].empty())
		{
			int k=find(a,w),q=k+2;
			if(k>=0)
			{
				int p=q-f[b].size();ans=max(ans,k+1);
				if(p<=0) f[b][q-1]=min(f[b][q-1],w);
				else fo(l,1,p) f[b].push_back(w);
			}
		}
	}
	printf("%d\n",ans+1);
	return 0;
}











