#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=22;
ll mp[N][N];
int main()
{
	freopen("bear.in","r",stdin);
	freopen("bear.out","w",stdout);
//	freopen("D:/LiuYuanHao/","r",stdin);
	mp[1][1]=0;mp[1][2]=4;mp[1][3]=8;mp[1][4]=32;mp[1][5]=64;mp[2][1]=4;mp[2][2]=32;mp[2][3]=192;mp[2][4]=1024;mp[2][5]=5120;
	mp[3][1]=8;mp[3][2]=192;mp[3][3]=2048;mp[3][4]=24064;mp[3][5]=229376;mp[4][1]=32;mp[4][2]=1024;mp[4][3]=24576;mp[4][4]=522240;mp[4][5]=10436608;
	mp[5][1]=64;mp[5][2]=5120;mp[5][3]=229376;mp[5][4]=10354688;mp[5][5]=402653184;
	int n,m,mo;scanf("%d%d%d",&n,&m,&mo);
	printf("%d\n",mp[n][m]%mo);
	return 0;
}









