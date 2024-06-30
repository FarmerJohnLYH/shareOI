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
const int N = 100100;
int n,k;
int a[N],t[N];
int main()
{
	// freopen("trans.in","r",stdin);
	// freopen("trans.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);
	while (scanf("%d%d", &n, &k) != EOF)
	{
		memset(t,0,sizeof t);
		fo(i,1,n) 
		{
			char ch = ' ';
			while (ch == ' ' || ch == '\n') scanf("%c", &ch);
			// if (ch != '2' && ch != '3') a[i] = ;
			// else 
			a[i] = ch - '0';		
		}
		int l = 1;
		fo(i,1,k)
		{
			while (!(a[l] == 2 && a[l + 1] == 3) && l < n) ++ l;
			if (l == n) break;
			if (l & 1) a[l + 1] = 2,++ t[l + 1],++ l; else a[l] = 3,++ t[l], -- l;
			if (t[l] >= 3)
			{
				if (a[l - 1] == 2 && a[l + 1] == 3) 
				{
					if ((k - i) % 2) a[l] = 5 - a[l];
					break;
				}
				break;
			}
			-- l;
		}
		fo(i,1,n) printf("%d", a[i]);
		printf("\n");
	}
	return 0;
}