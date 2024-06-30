#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=13,mo=1e9+7,P=N*N;
int s,m,n;
int x,y,z,mc;
ll f[P],p[P][P],q[P][P],pp[P][P],g[P];
int l(int x,int y)
{
	return(x*(n+1)+y+1);
}
void init()
{
	char S[N],T[N];
	scanf("%s",S+1);
	scanf("%s",T+1);
	scanf("%d%d%d%d",&x,&y,&z,&mc);
	n=strlen(S+1);
	int cnt=0;
	int a[3];a[0]=a[1]=a[2]=0;
	fo(i,1,n) 
	{
		while(S[i]!=T[i])
		{
			int pp=0;
			if(S[i]!=T[i]&&S[i]=='a')S[i]='b',m+=x,++cnt,++pp;
			if(S[i]!=T[i]&&S[i]=='b')S[i]='c',m+=y,++cnt,++pp;
			if(S[i]!=T[i]&&S[i]=='c')S[i]='a',m+=z,++cnt,++pp;
			if(S[i]!=T[i]&&S[i]=='a')S[i]='b',m+=x,++cnt,++pp;
			if(S[i]!=T[i]&&S[i]=='b')S[i]='c',m+=y,++cnt,++pp;
			if(S[i]!=T[i]&&S[i]=='c')S[i]='a',m+=z,++cnt,++pp;
			++a[pp];
		}
	}
	s=((mc-m)/(x+y+z))*3;s+=cnt;
	f[l(a[2],a[1])]=1;
}
int main()
{
//	freopen("D:/LiuYuanHao/d2.in","r",stdin);
	init();
	fo(b,0,n) fo(c,0,n-b)
	{
		int a=n-b-c;
		if(b)p[l(b,c)][l(b-1,c+1)]=b;
		if(c)p[l(b,c)][l(b,c-1)]=c;
		if(a)p[l(b,c)][l(b+1,c)]=a;
	}
	m=l(n,1);
	++p[m][m];++p[l(0,1)][m];
	if(f[l(0,0)]) ++f[l(n,1)];
	memset(pp,0,sizeof pp);
		fo(i,1,m) pp[i][i]=1;
	fo(gg,0,33)
	{
		if((1ll<<gg)>s)break;
		if((1ll<<gg)&s) 
		{
			memset(g,0,sizeof g);
			fo(k,1,m) fo(i,1,m)
				g[i]=(g[i]+f[k]*p[k][i]%mo)%mo;
			fo(i,1,m) f[i]=g[i];
		}
		memset(q,0,sizeof q);
		fo(k,1,m) fo(i,1,m) fo(j,1,m)
			q[i][j]=(q[i][j]+p[i][k]*p[k][j]%mo)%mo;
		fo(i,1,m) fo(j,1,m) p[i][j]=q[i][j];
	}
	printf("%lld\n",f[l(n,1)]);
	return 0;
}











