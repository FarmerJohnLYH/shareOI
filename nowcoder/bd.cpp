#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long ll;

const int N=405;

struct P{int x,y,v;}a[N*N];

bool cmp(P a,P b) {return a.v<b.v;}

int n,m,k,v,tot,col[N],Id[N][N],id[N*N],f[N][N];

void inc(int &x,int y) {x=x+y>=k?k:x+y;}

int calc() {
	fo(i,1,n+m-1) fo(j,0,i) f[i][j]=0;
	f[0][0]=1;
	fo(i,1,n+m-1)
		fo(j,0,i) {
			if (col[i]<1&&j) inc(f[i][j],f[i-1][j-1]);
			if (col[i]>-1) inc(f[i][j],f[i-1][j+1]); 
		}
	return f[n+m-1][0];
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	fo(i,1,n) fo(j,1,m) {
		scanf("%d",&v);
		a[++tot].x=i;a[tot].y=j;a[tot].v=v;
	}
	sort(a+1,a+tot+1,cmp);
	fo(i,1,n*m) {
		if (col[a[i].x+a[i].y-1]) continue;
		col[a[i].x+a[i].y-1]=-1;
		int now=calc();
		if (now<k) col[a[i].x+a[i].y-1]=1,k-=now;
	}
	fo(i,1,n) {
		fo(j,1,m) {
			if (col[i+j-1]==-1) putchar('(');
			else putchar(')');
		}
		puts("");
	}
	return 0;
}
