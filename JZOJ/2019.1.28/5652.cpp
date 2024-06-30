#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N=100100;
int a[N],tg,n;
//s 0  l 1 for_end
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
		char ch=0;while(ch!='s'&&ch!='l') ch=getchar();
		
		tg=((!(n&1) ^ (ch=='l')))?1:0;
		while(ch!='\n') ch=getchar();
		fo(i,1,n)
			scanf("%d",&a[i]);
		int gp=(n+1)/2,ans=oo;
		if(!tg)
		{
			fo(i,1,n-gp)
				ans=min(ans,a[gp+i]-a[i]);
			printf("%d\n",ans);
			continue;
		}
		int le=1,ri=a[n]-a[1];
		while(le<=ri)
		{
			int mid=(le+ri)>>1;
			int st=1,tot=1;
			fo(i,2,n)
			{
				if(a[i]-a[st]>mid) 
					++tot,st=i;
			}
			if(tot>gp) le=mid+1;
			else ri=mid-1,ans=mid;
		}
		printf("%d\n",ans);
	}
	return 0;
}











