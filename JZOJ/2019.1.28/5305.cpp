#include <cstdio>  
#include <algorithm>  
#define N 200010  
using namespace std;  
int head[N][2],to[N][2],next1[N][2],cnt[2],dd[N],low[N],tot,vis[N],ins[N],sta[N],top,bel[N],num;  
int fa[N][22],deep[N],sum[N][22],log1[N],pow1[N];  
void add(int p , int x , int y)  
{  
    to[++cnt[p]][p] = y , next1[cnt[p]][p] = head[x][p] , head[x][p] = cnt[p];  
}  
void tarjan(int x , int from)  
{  
    int i , t;  
    dd[x] = low[x] = ++tot , vis[x] = ins[x] = 1 , sta[++top] = x;  
    for(i = head[x][0] ; i ; i = next1[i][0])  
    {  
        if(to[i][0] == from) continue;  
        if(!vis[to[i][0]]) tarjan(to[i][0] , x) , low[x] = min(low[x] , low[to[i][0]]);  
        else if(ins[to[i][0]]) low[x] = min(low[x] , dd[to[i][0]]);  
    }  
    if(dd[x] == low[x])  
    {  
        num++;  
        do  
        {  
            t = sta[top -- ] , ins[t] = 0 , bel[t] = num;  
            if(t != x) sum[num][0] = 1; //如果这个点不是只有自己  就标记在环中   
        }while(t != x);  
    }  
}  
void dfs(int x)  
{  
    int i;  
    for(i = 1 ; i <= log1[deep[x]] ; i ++ )   
        fa[x][i] = fa[fa[x][i - 1]][i - 1] , sum[x][i] = sum[x][i - 1] + sum[fa[x][i - 1]][i - 1];  
    for(i = head[x][1] ; i ; i = next1[i][1]) if(to[i][1] != fa[x][0])   
        fa[to[i][1]][0] = x , deep[to[i][1]] = deep[x] + 1 , dfs(to[i][1]);  
}  
int cal(int x , int y)  
{  
    int i , ans = 0;  
    if(deep[x] < deep[y]) swap(x , y);  
    for(i = log1[deep[x] - deep[y]] ; i >= 0 ; i -- )   
        if(deep[x] - deep[y] >= (1 << i)) ans += sum[x][i] , x = fa[x][i];  
    for(i = log1[deep[x]] ; i >= 0 ; i -- )   
        if(fa[x][i] != fa[y][i]) ans += sum[x][i] + sum[y][i] , x = fa[x][i] , y = fa[y][i];  
    if(x != y) ans += sum[x][0] + sum[y][0] , x = fa[x][0];  
    return ans + sum[x][0];  
}  
int main()  
{  
    int n , m , k , i , x , y;  
    scanf("%d%d" , &n , &m);  
    while(m -- ) scanf("%d%d" , &x , &y) , add(0 , x , y) , add(0 , y , x);  
    tarjan(1 , 0);  
    for(x = 1 ; x <= n ; x ++ ) for(i = head[x][0] ; i ; i = next1[i][0])  
    if(bel[x] != bel[to[i][0]]) add(1 , bel[x] , bel[to[i][0]]);    
    pow1[0] = 1 , pow1[1] = 2;  
    for(i = 2 ; i <= n ; i ++ ) log1[i] = log1[i >> 1] + 1 , pow1[i] = pow1[i - 1] * 2 % 1000000007;  
    dfs(1);//重构  
    scanf("%d" , &k);  
    while(k -- ) scanf("%d%d" , &x , &y) , printf("%d\n" , pow1[cal(bel[x] , bel[y])]);  
    return 0;  
}  
