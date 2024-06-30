#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (register int i = (x);i <= (y);++ i)
#define fd(i,x,y) for (register int i = (x);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N = 200200,Mo = 1e9 + 7;
int n,m;
int head[N][2],to[N][2],next1[N][2];
int cnt[2],dfn[N],low[N],tot,vis[N];
int ins[N],sta[N],top,bel[N],num;  
int fa[N][22],dep[N],sum[N][22];
int log1[N],tw[N];  
void link(int p,int x,int y)  
{  
    to[++ cnt[p]][p] = y,next1[cnt[p]][p] = head[x][p],head[x][p] = cnt[p];  
}  
void tarjan(int x ,int f)  
{  
    int i , t;  
    dfn[x] = low[x] = ++ tot ,vis[x] = ins[x] = 1,sta[++ top] = x;  
    for(i = head[x][0] ; i ; i = next1[i][0])  
    {  
        if(to[i][0] == f) continue;  
        if(!vis[to[i][0]]) tarjan(to[i][0] , x) , low[x] = min(low[x] , low[to[i][0]]);  
        else if(ins[to[i][0]]) low[x] = min(low[x] , dfn[to[i][0]]);  
    }  
    if(dfn[x] == low[x])  
    {  
        ++ num;  
        do  
        {  
            t = sta[top -- ],ins[t] = 0,bel[t] = num;  
            if(t != x) sum[num][0] = 1;  
        }while(t != x);  
    }  
}  
void dfs(int x)  
{  
    fo(i,1,log1[dep[x]])  
        fa[x][i] = fa[fa[x][i - 1]][i - 1] , sum[x][i] = sum[x][i - 1] + sum[fa[x][i - 1]][i - 1];  
    for(int i = head[x][1];i;i = next1[i][1]) 
    if(to[i][1] != fa[x][0])   
        fa[to[i][1]][0] = x ,dep[to[i][1]] = dep[x] + 1,dfs(to[i][1]);  
}  
int lca(int x , int y)  
{  
    int ans = 0;  
    if(dep[x] < dep[y]) swap(x , y);  
    fd(i,log1[dep[x] - dep[y]],0)
        if(dep[x] - dep[y] >= (1 << i)) ans += sum[x][i],x = fa[x][i];  
    fd(i,log1[dep[x]],0)
        if(fa[x][i] != fa[y][i]) ans += sum[x][i] + sum[y][i],x = fa[x][i],y = fa[y][i];  
    if(x != y) ans += sum[x][0] + sum[y][0] , x = fa[x][0];  
    return ans + sum[x][0];  
}  
int main()  
{  
    freopen("D:/LiuYuanHao/","r",stdin);
    n = read(),m = read();
    fo(i,1,m)
    {
        x = read(),y = read();
        link(0,x,y),link(0,y,x);
    }
    tarjan(1,0);  
    fo(x,1,n)
        for(int i = head[x][0];i;i = next1[i][0])  
            if(bel[x] != bel[to[i][0]]) link(1 , bel[x] , bel[to[i][0]]);    
    tw[0] = 1;  
    fo(i,1,n) log1[i] = log1[i >> 1] + 1 , tw[i] = (tw[i - 1] << 1) % Mo;  
    dfs(1);
    scanf("%d" , &k);
    while (k --)
    {
        int x = read(),y = read();
        printf("%d\n" , tw[lca(bel[x] , bel[y])]);
    }
}  
