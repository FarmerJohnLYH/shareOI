#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (register int asDfg = (y),i = (x);i <= asDfg;++ i)
#define fd(i,x,y) for (register int asDfg = (y),i = (x);i >= asDfg;-- i)
using namespace std;
typedef double db;
typedef long long ll;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N = 1000100;
int n;
int a[N],s[N];
struct node{
    int v,id;
    node(int v_,int id_){v = v_,id = id_;}
    node(){}
}d[N];
int bit;
node max(node x,node y)
{
    return (x.v>y.v)?(x):(y);
}
void build(int n)
{
    for(bit=1;bit<=n+1;bit<<=1);//bit = 总节点数目 - 叶子节点数目
    for(int i=bit+1;i<=bit+n;i++) d[i].v = read(),d[i].id = i - bit;
    for(int i=bit-1;i;i--)
        d[i]=max(d[i<<1],d[i<<1|1]);
}
void updata(int x,node y)//修改 d[x] 为 y
{
    for(d[x+=bit]=y,x>>=1;x;x>>=1)
        d[x]=max(d[x<<1],d[x<<1|1]);
}
node query(int s,int t)//区间 [s,t] 最大值
{
    node ans = node(-oo,0);
    for(s+=bit-1,t+=bit+1;s^t^1;s>>=1,t>>=1)
    {
        if(~s&1) ans=max(ans,d[s^1]);
        if(t&1) ans=max(ans,d[t^1]);
    }
    return ans;
}
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    n = read();
    build(n);
    int i = 0,tot = 0,tl = 0;
    while (tot < n)
    {
        node tmp = query(i + 1,n);
        if (tmp.v > a[tl] || tl == 0) 
        {
            s[++ tot] = tmp.v;
            fo(j,i+1,tmp.id-1) a[++ tl] = d[j + bit];
            i = tmp.id;
        }
        else
        {
            s[++ tot] = a[tl --];
        }
    }
    fo(l,1,tot) printf("%d ", s[l]);
}











