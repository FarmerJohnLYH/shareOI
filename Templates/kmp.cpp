int p[N];
int ls=n,lt=m;
int j=0;p[1]=0;
fo(i,2,lt)
{
	while(t[i]!=t[j+1]&&j)j=p[j];
	if(t[i]==t[j+1])++j;
	p[i]=j;
}
j=0;
fo(i,1,ls)
{
	while(s[i]!=t[j+1]&&j)j=p[j];
	if(s[i]==t[j+1])++j;
	if(j==lt)
	{
		//s[i..i+lt-1]==t[]
	}
}

#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 101000
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
char s[N],t[N];
int next[N],extend[N],n,m,nm;
void getextend()
{
    next[1]=n;
    int a=0,p=0;
    fo(i,2,n)
    {
        int j=next[i-a+1];
        if(i+j>p) for(j=max(0,p-i);i+j<=n && t[i+j]==t[j+1];j++);
        next[i]=j;
        if(i+j-1>p) a=i,p=i+j-1;
    }
    a=p=0;
    fo(i,1,n)
    {
        int j=next[i-a+1];
        if(i+j>p) for(j=max(0,p-i+1);i+j<=n && s[i+j]==t[j+1];j++);
        extend[i]=j;
        if(i+j-1>p) a=i,p=i+j-1;
    }
}
int main()
{
    freopen("exkmp.in","r",stdin);
    scanf("%s\n",s+1);n=strlen(s+1);
    scanf("%s\n",t+1);
    getextend();
    fo(i,1,n) printf("%d ",extend[i]);
}
