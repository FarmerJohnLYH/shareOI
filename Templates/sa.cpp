#include <cstdio>
#include <cstring>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=100100;
int sa[N],rnk[N],se[N];
int tn[N],he[N];
char s[N];
int n;
bool cmp(int *r,int a,int b,int l)
{
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void gtsa(int *x,int *y,int m)
{
	fo(i,0,m) tn[i]=0;
	fo(i,1,n) ++tn[x[y[i]]];
	fo(i,1,m) tn[i]+=tn[i-1];
	fd(i,n,1) 
		sa[tn[x[y[i]]]--]=y[i];		
}
void solve(char *r,int *sa,int n,int m)
{
	int *x=rnk,*y=se,*t;
	r[n+1]=-1;
	fo(i,1,n)x[i]=r[i]-'a'+1,y[i]=i;
	gtsa(x,y,m);
	int ct=0;
	for(int len=1;len<=n;len<<=1)
	{
		ct=0;
		fd(i,n,n-len+1) y[++ct]=i;
		fo(i,1,n)if(sa[i]>len) y[++ct]=sa[i]-len;
		gtsa(x,y,m);
		t=x,x=y,y=t;x[sa[ct=1]]=1;
		fo(i,2,n) x[sa[i]]=cmp(y,sa[i-1],sa[i],len)?(ct):(++ct);
		m=ct;
	}
}
int max(int x,int y){return(x>y)?x:y;}
void gthe(char *r,int *sa,int n)
{
	fo(i,1,n) rnk[sa[i]]=i;
	int k=0;
	fo(i,1,n)
	{
		k=max(k-1,0);
		while(r[i+k]==r[sa[rnk[i]-1]+k]) ++k;
		he[rnk[i]]=k;
	} 
}
int buf[30],b0;
void write(int x)
{
	b0=0;
	if(x==0)putchar('0');
	else
	while(x) buf[++b0]=x%10,x/=10;
	fd(i,b0,1) putchar(buf[i]+'0');
}
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	solve(s,sa,n,27);
	gthe(s,sa,n);
	fo(i,1,n) write(sa[i]),putchar(' ');puts("");
	fo(i,2,n) write(he[i]),putchar(' ');
} 
