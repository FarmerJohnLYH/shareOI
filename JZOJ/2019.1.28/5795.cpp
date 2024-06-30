#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=100100,M=5000500;
int n,m;
char s[M],t[M];
int to[M][3],la[M],mx[M];
int le[N],ri[N];
int tot=1;
void add(int x)
{
	int nw=1;
	fo(i,le[x],ri[x])
	{
		if(!to[nw][t[i]-'a']) to[nw][t[i]-'a']=++tot;
		nw=to[nw][t[i]-'a'];
		if(la[nw]) mx[nw]=max(mx[nw],x-la[nw]);
		else mx[nw]=max(mx[nw],x-1);
		la[nw]=x+1;
	}
}
int query(char s[])
{
	int len=strlen(s+1);
	int nw=1;
	fo(i,1,len)
	{
		if(!to[nw][s[i]-'a']) return n;
		nw=to[nw][s[i]-'a'];
	}
	return mx[nw];
}
int main()
{
//	freopen("b.in","r",stdin);
//	freopen("b.ans","w",stdout);
//	freopen("word.in","r",stdin);
//	freopen("word.out","w",stdout);
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n)
	{
		le[i]=ri[i-1]+1;
		scanf("%s",t+le[i]);
		ri[i]=(le[i]+strlen(t+le[i])-1);
		add(i);
	}
	fo(i,2,tot)
		if(la[i]) mx[i]=max(mx[i],n+1-la[i]);
	fo(i,1,m)
	{
		scanf("%s",s+1);
		printf("%d\n",query(s));
	}
	return 0;
}











