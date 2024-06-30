#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=100100;
int ans;
char S[N];int n;
int jd[256];
struct Tree{
	int en,tot,ri;
	int to[N][4];
	int cst[N],len[N],fail[N][20];
	void clear()
	{
		fo(i,0,1)memset(fail[i],0,sizeof fail[i]),memset(to[i],0,sizeof to[i]);
		en=ri=0,tot=1;
		len[1]=-1,len[0]=0;
		fail[1][0]=0;fail[0][0]=1;
		fo(i,1,18) fail[1][i]=fail[fail[1][i-1]][i-1],fail[0][i]=fail[fail[0][i-1]][i-1];
		cst[1]=2,cst[0]=1;
	}
	int gtf(int x)
	{
		if(S[ri-len[x]-1]==S[ri]) return(x);
		while(S[ri-len[fail[x][0]]-1]!=S[ri])x=fail[x][0];
		return fail[x][0];
	}
	int find(int x,int mx)
	{
		if(len[x]<=mx) return(x);
//		fd(i,18,0) 
		if(len[fail[x][0]]>mx) x=fail[x][0];
		return fail[x][0];
	}
	void add(int c)
	{
		++ri;
		int tp=gtf(en);
		if(!to[tp][c])
		{
			++tot;
			memset(fail[tot],0,sizeof fail[tot]);
			fail[tot][0]=to[gtf(fail[tp][0])][c];
			fo(i,1,18) fail[tot][i]=fail[fail[tot][i-1]][i-1];
			memset(to[tot],0,sizeof to[tot]);
			to[tp][c]=tot,len[tot]=len[tp]+2,cst[tot]=len[tot];
			if(!(len[tot]&1))
			{
				int tmp=find(fail[tot][0],len[tot]/2);
				cst[tot]=min(cst[tp]+1,cst[tmp]+len[tot]/2-len[tmp]+1);
			}
			ans=min(ans,cst[tot]+n-len[tot]);
		} 
		en=to[tp][c];
	}
}t;
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	int T;
	scanf("%d\n",&T);
	memset(jd,255,sizeof jd);
	jd['A']=0,jd['C']=1,jd['G']=2,jd['T']=3;
	while(T--)
	{
		t.clear();
		char c=getchar();
		while(jd[c]==-1)c=getchar();
		n=0;
		while(jd[c]>=0)S[++n]=c,c=getchar();
		ans=oo;
		fo(i,1,n) t.add(jd[(int)S[i]]);
		printf("%d\n",ans);
	}
	return 0;
}
