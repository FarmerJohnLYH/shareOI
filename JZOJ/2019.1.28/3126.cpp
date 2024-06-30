#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=1001000;
int n,q,tot,tr[N][26];
int ans[N];
char s[N];
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	tot=1;
	scanf("%d%d",&n,&q);
	fo(i,1,n)
	{
		scanf("%s",s+1);
		int len=strlen(s+1),tmp=0;
		int x=1,flag=1;
		fo(j,1,len)
		{
			if(!tr[x][s[j]-'a'])
			{
				flag=0;
				tr[x][s[j]-'a']=++tot;
			}
			x=tr[x][s[j]-'a'];
			if(flag)++tmp;
		}
		ans[i]=max(tmp,ans[i-1]);
	}
	while(q--)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
}