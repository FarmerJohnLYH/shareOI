#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=1001000;
int L,R;
int a[N];
int solve(int n)
{
	memset(a,0,sizeof a);
	fo(i,2,n) 
	{
		if(i*i>n)break;
		int rt=i;
		fo(j,2,n)
		{
			rt=rt*i;
			if(rt>n)break;
			fo(k,1,i-1) 
			{
				if(k*rt>n)break;
				a[k*rt]=1;
			}
		}
	}
	int rt=0;
	fo(i,1,n)
	{
		if(a[i])
		{
			++rt;
//			printf("a[%d]=1,",i);
		}
	}
	return rt;
}
int main()
{
	freopen("rinascimento.in","r",stdin);
	freopen("rinascimento.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.ans","w",stdout);
	scanf("%d%d",&L,&R);
	printf("%d",solve(R)-solve(L-1));
	return 0;
}











