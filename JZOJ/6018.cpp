#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=10001000;
int a[N],k,n;
char s[N];
int p[N],p0,ans;
int main()
{
	freopen("modulo.in","r",stdin);
	freopen("modulo.out","w",stdout);
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d",&k);
	scanf("%s",s+1);n=strlen(s+1);
	p[p0=1]=0;
	int tmp=0;
	fo(i,1,n) 
		a[i]=(k-(s[i]-'0'))%k;
	fo(i,1,n) 
	{
		a[i]=a[i+tmp];
		while(a[i]==a[i-1]&&i+tmp<=n)++tmp,a[i]=a[i+tmp];
		if(i+tmp>n) 
		{
			n=i-1;
			break;	
		}
		if(k==a[i]) p[++p0]=i;
	}
	fo(i,1,p0) if(a[p[i]+1]>k-a[p[i]-1])
		a[p[i]]=k;
	fo(j,1,n) ans+=max(0,a[j]-a[j-1]);
	printf("%d\n",ans);
	return 0;
}








