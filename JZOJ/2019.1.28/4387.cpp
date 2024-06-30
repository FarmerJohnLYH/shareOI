#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=100100;
int T,n;
char s[N];
int f[N];
struct node{
	int len,x;
	node(){}
	node(int l_=0,int x_=0){len=l_,x=x_;}
};
bool operator<(node a,node b)
{
	return(a.len<b.len);
}
void manacher()
{
	f[1]=0;int l=1;
	fo(i,2,n)
	{
		if(l+f[l]>i) f[i]=min(f[l-(i-l)],l+f[l]-i);
		while(s[i+f[i]+1]==s[i-f[i]-1]&&i-f[i]-1>0&&i+f[i]+1<=n)
			++f[i];
		if(i+f[i]>l+f[l]) l=i;
	}
}
int lg[N];
int solve(int l,int r)
{
	int rt=oo;
	priority_queue<node> q;q.clear();	
	fo(i,l,r) if(s[i]=='&') q.push(node(f[i],i));
	while(!q.empty())
	{
		node p=q.top();
		if(lg[p.len]+(r-l+1-p.len*2)>=rt) break;
		int tp=solve(p.x-p.len,p.x+p.len);
	}
}
int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%d",&T);
	lg[1]=1;fo(i,2,n)lg[i]=lg[i>>1]+1;
	while(T--)
	{
		memset(f,0,sizeof f);
		//clear
		scanf("%s",s+1);n=strlen(s+1);
		fd(i,n*2+1,1)
		{
			if(i&1) s[i]='&';
			else s[i]=s[i>>1];
		}n=n*2+1;
		manacher();
		int ans=solve(1,n);
		printf("%d\n",ans);
	}
	return 0;
}











