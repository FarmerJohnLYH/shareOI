#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int LEN=100100,N=13;
int n,T,len;
int p[LEN];
char S[LEN],s[LEN];
int h[2][LEN],po[N];
bool f[N][LEN];
void gethash(int opt,char *str,int len)
{
	fo(i,1,len) h[opt][i]=h[opt][i-1]*p[1]+str[i];
}
int hash(int opt,int l,int r)
{
    return (r>l)?h[opt][r]-h[opt][l-1]*p[r-l+1]:-1;
}
int main()
{
	freopen("D:/LiuYuanHao/c2.in","r",stdin);
	freopen("D:/LiuYuanHao/c.out","w",stdout);
	p[0]=1,p[1]=131;
	fo(i,2,LEN-1) p[i]=p[i-1]*p[1];
	scanf("%s",S+1);
	S[len=strlen(S+1)+1]='?';
	gethash(0,S,len);	
	fo(i,1,len) 
		if(S[i]=='*'||S[i]=='?') po[++n]=i;
	scanf("%d",&T);
	while(T--)
	{
		memset(f,0,sizeof f);
		scanf("%s",s+1);
		len=strlen(s+1);
		gethash(1,s,len);
		s[++len]='#';
		f[0][0]=1;
		fo(i,0,n-1) 
		{
			if(S[po[i]]=='*') 
				fo(j,1,len) f[i][j]|=f[i][j-1];
			fo(j,0,len)
			if(f[i][j])
			{
				int l=(po[i+1]-1)-(po[i]+1);
				if(j+l<=len)
				if(hash(0,po[i]+1,po[i+1]-1)==hash(1,j+1,j+l+1))
				{
					if(S[po[i+1]]=='?') f[i+1][j+l+2]=1; else f[i+1][j+l+1]=1;
				}
			}	
		}
		if(f[n][len]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}











