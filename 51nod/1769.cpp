#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=500500,mo=1e9+7;
int n,k;
ll f[166][N];
char st[1001000];
int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%d%s",&n,st+1);int len=strlen(st+1);
	fo(i,1,len) k=(k*10+st[i]-'0')%mo;
	fo(i,1,n)
		scanf("%lld",&f[0][i]);

	return 0;
}








