#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int Mo=1e7+7,mo=998244353;
int A,B;
int h[4][Mo+10],p[4][3];
int t[4];
int qsm(int x,int y)
{
	int rt=1;
	fo(i,0,30)
	{
		if((1<<i)&y) rt=(1ll*rt*x)%mo;
		x=1ll*x*x%mo;
	}
	return rt;
}
int jd(int x)
{
	memset(t,0,sizeof t);
	fo(i,0,3)t[i]=(1ll*x*p[i][0]+1ll*t[max(i-1,0)]*p[i][1]+p[i][2])%Mo;
	int rt=oo;
	fo(i,0,3) rt=min(rt,(++h[i][t[i]]));
	if(rt>1)return 1;
	else return 0;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	p[0][0]=17,p[0][1]=31,p[0][2]=59;
	p[1][0]=37,p[1][1]=23,p[1][2]=97;
	p[2][0]=2,p[2][1]=173,p[2][2]=47;
	p[3][0]=29,p[3][1]=341,p[3][2]=7;
	scanf("%d%d",&A,&B);
	int ans=0;
	fo(i,1,A) fo(j,1,B)
	{
		int q=qsm(i,j);
		if(jd(q)) 
			++ans;
	}
	ans=1ll*A*B-ans;
	printf("%d\n",ans);
	return 0;
}











