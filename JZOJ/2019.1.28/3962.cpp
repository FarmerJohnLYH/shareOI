#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N=10100,P1=3628801,P2=22054033;
int n,k;
ll P;
struct node{
	char s[N];
};
bool hf[P1+10],hs[P2+10];
char st[N];
node c[N];
int c0;
bool cmp(node a,node b)
{
	int la=strlen(a.s+1),lb=strlen(b.s+1);
	if(la!=lb)return(la<lb);
	fo(i,1,la)
	if(a.s[i]!=b.s[i]) return(a.s[i]<b.s[i]);
	return 0;
}
int jd(int x,int y)
{
	int len=y-x+1;
	fd(i,(x+len/2-1),x)
	if(st[i]!=st[y-(i-x)]) return(0);
	return 1;
}
int h1(int x,int y)
{
	int rt=0;
	fo(i,x,y)
		rt=(rt*13+(st[i]-'a'+1)*7)%P1;
	return rt;
}
int h2(int x,int y)
{
	int rt=0;
	fo(i,x,y)
		rt=(rt*5+(st[i]-'a'+1)*19)%P2;
	return rt;
}
void up(int x,int a,int b)
{
	fo(i,a,b)
		c[x].s[i-a+1]=st[i];
}
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%lld",&n,&P);
	scanf("%s",st+1);
	int pp=200000000;
	fo(i,1,n) fo(j,i,min(i+(pp/n/n),n))
	{
		if(jd(i,j)&&!hf[h1(i,j)]&&!hs[h2(i,j)])
		{
			hf[h1(i,j)]=1,hs[h2(i,j)]=1;
			up(++c0,i,j);
		}	
	}
	k=P%c0+1;	
	printf("%d\n",c0);
	sort(c+1,c+1+c0,cmp);
	printf("%s\n",c[k].s+1);
	return 0;
}











