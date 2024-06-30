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
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d",&k);
	scanf("%s",s+1);n=strlen(s+1);
	p[p0=1]=0;
	int tmp=0;
	fo(i,1,n) 
	{
		a[i]==a[i+tmp];
		while(a[i]==a[i-1]&&i+tmp<=n)++tmp,a[i]=a[i+tmp];
		if(i+tmp>n) 
		{
			n=i-1;
			break;	
		}
		a[i]=(k-(s[i]-'0'))%k;
		if(k==a[i]) p[++p0]=i;
	}
	if(a[n]!=0) p[++p0]=n+1;
	fo(i,1,p0) if(a[p[i]+1]>k-a[p[i]-1])
		a[p[i]]=k;
	fo(i,2,p0)
	{
		int le=p[i-1]+1,ri=p[i]-1;
		if(le>ri)continue;
		fo(j,le,ri) ans+=max(0,a[j]-a[j-1]);
	}
	printf("%d\n",ans);
	return 0;
}








