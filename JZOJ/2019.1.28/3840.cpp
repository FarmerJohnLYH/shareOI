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
const int N=100100;
int n,Q,startSeed,threshold,maxDist;
int curValue;
struct node{
	int fi,se;
	int nex;
}q[N];
int qls[N];
int genNextRandom() 
{
    curValue = (curValue * 1999 + 17) % 1000003;
    return curValue;
}
int fa[N];
void generateInput() 
{
    for (int i = 0; i < n-1; i++) 
    {
        int val = genNextRandom() % maxDist;
		fa[i] = genNextRandom();
        if (fa[i] < threshold) {
            fa[i] = i;
        } else {
            fa[i] = fa[i] % (i + 1);
        }
        link(i+2,fa[i]+1,val),link(fa[i]+1,i+2,val);
    }
    fo(i,1,Q)
    {
    	q[i].tp=genNextRandom()%2+1,q[i].x=genNextRandom()%n+1;
    	if(q[i].tp==1)
    	{
    		if(!q[i].tp[adr])
    			q[i].tp[adr]=i,q[i].nex=q[i].x[qls],q[i].x[qls]=i;
    	}
    	else q[i].nex=q[i].x[qls],q[i].x[qls]=i;
    }
}

int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%d%d%d%d%d",&n,&Q,&startSeed,&threshold,&maxDist);
	curValue = startSeed;
	generateInput();
    dfs(1);
    ll ot=0;
    fo(i,1,q) 
    	pr^+
	return 0;
}











