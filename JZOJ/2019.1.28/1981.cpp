#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 1000010000
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=110;
int n,s1,s2,d;
int sum(int x)
{
	int s=0;
	while(x) s+=x%10,x/=10;
	return s;
}
int tot,a[N];
bitset<oo>bz;
int flag;
void dfs(int o,int p1,int p2,int p)
{
	if(flag)return;
	if(p1>s1||p2>s2||p>d)return;
	if((n-o+1)*9+p1<s1||(n-o+1)*9+p2<s2)return;
	int num=p+p2*11+p1*9999+o*8999100;
	if(bz[num])return;
	bz[num]=1;
	if(o>n)
	{
		if(p1==s1&&p2==s2&&p==0)
		{
			fo(i,1,n)printf("%d",a[i]);
			printf("\n");
			flag=1;
		}
		return;
	}
	else
	fo(i,p*10,p*10+9)
	{
		int x=i/d,np=i-x*d;
		a[o]=x;
		dfs(o+1,p1+x,p2+i%10,np);
		if(flag)return;
	}
}
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d%d%d%d",&n,&s1,&s2,&d);
	fo(i,1,9)fo(p,0,d-1)
	{
		a[1]=i,dfs(2,i,sum(i*d+p),p);
		if(flag)return 0;
	}
	printf("-1\n");
	return 0;
}
