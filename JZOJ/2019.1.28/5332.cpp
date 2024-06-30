#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=1010,K=22,mo=1e9+7;
int n,len,k;
char st[N];
int to[N][K],fail[N];
int sz,v[N];
int s0[2],s[2][N];
void ins()
{
	int x=0;len=strlen(st+1);
	fo(i,1,len)
	{
		if(!to[x][st[i]-'0']) to[x][st[i]-'0']=++sz;
		x=to[x][st[i]-'0'];
	}
	++v[x];
}
void init()
{
	queue<int> qu;
	fo(j,0,9)if(to[0][j]) qu.push(to[0][j]);
	while(!qu.empty())
	{
		int x=qu.front();qu.pop();
		fo(j,0,9)
		{
			if(!to[x][j]) 
			{
				to[x][j]=to[fail[x]][j];	
			}
			else
			{
				int y=fail[x];
				while(y&&!to[y][j]) y=fail[y];
				fail[to[x][j]]=y;
				qu.push(to[x][j]);	
			}
		}
	}
}
int f[N][N][K][2];
void add(int &x,int y)
{
	x=(x+y)%mo;
}
int Ans(int t)
{
	memset(f,0,sizeof f);
	f[0][0][0][1]=1;
	fo(i,1,s0[t]) fo(j,0,sz) fo(kp,0,k)
	{
		int p=f[i-1][j][kp][1];
		fo(l,0,9)
//		if(to[j][l])
		{
			int va=min(kp+v[j],k);
			if(l<s[t][i])
				add(f[i][to[j][l]][min(kp+v[j],k)][0],f[i-1][j][kp][1]);
			if(l==s[t][i])
				add(f[i][to[j][l]][min(kp+v[j],k)][1],f[i-1][j][kp][1]);
			add(f[i][to[j][l]][min(kp+v[j],k)][0],f[i-1][j][kp][0]);
		}
	}
	int ans=0;
	fo(i,1,sz) 
		add(ans,(f[s0[t]][i][k][0]+f[s0[t]][i][k][1])%mo);
	return ans;
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&k);
	scanf("%s ",st+1);s0[0]=strlen(st+1);
	fo(i,1,s0[0]) s[0][i]=st[i]-'0';
	scanf("%s\n",st+1);s0[1]=strlen(st+1);
	fo(i,1,s0[1]) s[1][i]=st[i]-'0';
	fo(i,1,n)
	{
		scanf("%s\n",st+1);
		ins();
	}
	init();
	printf("%d\n",(Ans(1)-Ans(0)+mo)%mo);
	return 0;
}








