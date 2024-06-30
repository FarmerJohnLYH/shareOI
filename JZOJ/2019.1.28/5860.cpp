#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=1000100,mo=1e9+7;
int n;
char s[N];
int main()

{
	freopen("absurdity.in","r",stdin);
	freopen("absurdity.out","w",stdout);
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	int p;
	scanf("%d\n",&p);
	scanf("%s\n",s+1);
	n=strlen(s+1);
	int ans=0;
	fo(i,1,n)
		ans=(ans+1ll*i*i%mo)%mo;
		printf("%d\n",ans);
	return 0;
}











