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
int n;  
const int maxn=100000;  
bool apple[maxn+20];
bool visited[maxn+20];
int branch_index;  
struct branch
{  
    int dest;  
    int next;  
}branchs[2*(maxn+20)];  
struct node  
{  
    int tag;
    int min_tag;
    int next;
}nodes[maxn+20];  
void add(int p1,int p2)  
{  
    branchs[branch_index].dest=p2;  
    branchs[branch_index].next=nodes[p1].next;  
    nodes[p1].next=branch_index;  
    branch_index++;  
    branchs[branch_index].dest=p1;  
    branchs[branch_index].next=nodes[p2].next;  
    nodes[p2].next=branch_index;  
    branch_index++;  
}  
int Tim;  
void dfs(int i)  
{  
    visited[i]=true;  
    nodes[i].min_tag=Tim; 
    int p=nodes[i].next;  
    while(p>=0)  
    {  
        if(!visited[branchs[p].dest]) dfs(branchs[p].dest);  
        p=branchs[p].next;  
    }  
    nodes[i].tag=Tim++;
}  
int tree_array[maxn+20];
void change(int i)  
{  
    int t=1;  
    if(apple[i]) t=-1;
    apple[i]=!apple[i];  
    while(i<=n)  
    {  
        tree_array[i]+=t;  
        i=i+lowbit(i);  
    }     
}  
int query(int i)  
{  
    int ans=0;  
    while(i>0)  
    {  
        ans+=tree_array[i];  
        i=i-lowbit(i);  
    }  
    return ans;  
}  
int main()  
{  
    scanf("%d",&n);  
    int p1,p2;  
    branch_index=0;  
    Tim=1;  
    memset(nodes,-1,sizeof(nodes));  
    memset(apple,1,sizeof(apple));  
    memset(visited,0,sizeof(visited));  
    for(int i=1;i<n;i++)  
    {  
        scanf("%d%d",&p1,&p2);  
        add(p1,p2);
    }  
    dfs(1);
    for(int i=1;i<=n;i++) tree_array[i]=lowbit(i);  
    int m;  
    char opt[3];  
    scanf("%d",&m);  
    for(int i=0;i<m;i++)  
    {  
        scanf("%s%d",opt,&p1);  
        if(opt[0]=='Q') printf("%d\n",query(nodes[p1].tag)-query(nodes[p1].min_tag-1));  
        else change(nodes[p1].tag);  
    }  
    return 0;  
}  
