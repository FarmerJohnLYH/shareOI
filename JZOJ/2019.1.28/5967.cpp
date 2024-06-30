#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=400400;
int n,q,le,ri;
int a[N],va;
void work(int le,int ri,int &va)
{
	fo(i,le,ri) if(a[i]>va) swap(a[i],va);
}
int main()
{
	freopen("in.in","r",stdin);
	freopen("in.out","w",stdout);
	// freopen("D:/LiuYuanHao/a4.in","r",stdin);
	// freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d%d",&n,&q);
	fo(i,1,n) scanf("%d",&a[i]);
	while(q--)
	{
		scanf("%d%d%d",&le,&ri,&va);
		if(le>ri) work(le,n,va),work(1,ri,va);
		else work(le,ri,va);
		printf("%d\n",va);
	}
	return 0;
}








