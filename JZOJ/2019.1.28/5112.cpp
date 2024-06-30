#include <cstdio>
#include <vector> 
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define abs(x) (((x)>=0)?(x):(-(x)))
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define fo(i,x,y) for (int i = (x);i <= (y);++ i)
#define fd(i,x,y) for (int i = (x);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
const int LEN = 200200;
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;
    int n=q*w;return n;
}
struct node{
    int las,col,pre,suf;
};
vector<node>s[LEN];
struct edge{
    int a,b,c;
    bool ms;
}e[LEN];
int las[LEN];
int n,m,k,q;
int col[LEN],f[LEN],ans[LEN];
bool cmp(edge x,edge y) {return x.c < y.c;}
int gf(int x)
{
    return (f[x] == x)?(x):(f[x] = gf(f[x]));
}
void mst()
{
    fo(i,1,m)
    {
        int fx = gf(e[i].a),fy = gf(e[i].b);
        if (fx != fy) 
            e[i].ms = true,f[fx] = fy;
    }
}
void work(int x,int v)
{
    int Pr = s[x][v].pre,Su = s[x][v].suf,t = gf(s[x][v].las);
    if (s[x][Su].las <= t)
    {
        s[x][Pr].suf=Su,s[x][Su].pre=Pr;
        if (s[x][Pr].col == s[x][Su].col)//combine
            s[x][Pr].suf = s[x][Su].suf,s[x][s[x][Pr].suf].pre = Pr;
    }
}
int main()
{
    freopen("D:/LiuYuanHao/5112.in","r",stdin);
    n = read(),m = read(),k = read(),q = read();
    fo(i,1,m) e[i].a = read(),e[i].b = read(),e[i].c = read();
    fo(i,1,n) col[i] = read(),f[i] = i,las[i] = 0; 
    sort(e + 1,e + 1 + m,cmp); 
    mst();
    //mean_change(*f)
    fo(i,1,q)
    {
        int x = read(),y = read();
        int sz = s[x].size();
        s[x].push_back((node){las[x],col[x],sz - 1,sz + 1});
        col[x] = y,las[x] = f[i] = i;
    }
    fo(i,1,n)
    {
        int sz = s[i].size();
        s[i].push_back((node){las[i],col[i],sz - 1,sz + 1});
        s[i].push_back((node){q + 1,0,0,0}); 
    }
    f[q + 1] = q + 1;
    fo(i,1,m)
    if (e[i].ms)
    {
        int x = e[i].a,y = e[i].b;
        for(int now = 0;now <= q;)
        {
            int v = 0,u = 0;
            now = gf(now + 1);
            if (now > q) break;
            for (int Su = s[x][v].suf;s[x][Su].las <= now;)
                v = Su,Su = s[x][Su].suf;        
            for (int Su = s[y][u].suf;s[y][Su].las <= now;)
                u = Su,Su = s[y][Su].suf; 
            if (s[x][v].col != s[y][u].col) ans[now] = e[i].c,f[now] = now + 1;
            else now = min(s[x][s[x][v].suf].las,s[y][s[y][u].suf].las) - 1;
            work(x,v),work(y,u);
        }
    }
    fo(i,1,q) printf("%d\n", ans[i]);
}