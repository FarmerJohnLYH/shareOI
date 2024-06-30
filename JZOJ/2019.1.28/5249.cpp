#include <cstdio>
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
const int N = 5005000;
int len,n;
struct node{
    char c;
    int le,ri;
}st[N];
int it[3];//1 L 2 R
char type,whi,ch;
char read()
{
    char ch = ' ';
    while (ch == ' '|| ch == '\n') ch = getchar();
    return ch;
}
void ins(int x,char c)
{
    
void del(int x)
{
    
}
int main()
{
    freopen("D:/LiuYuanHao/c.in","r",stdin);
    for (len = 0,ch = getchar();ch != '\n';ch = getchar())
    {
        st[++ len].c = ch;
        st[len].le = len - 1,st[len].ri = len + 1;
    }
    st[0].ri = 1,st[++ len].le = len - 1;
    n = len;
    int T;
    it[1] = 1,it[2] = len + 1;//右手字符序号
    scanf("%d\n", &T);
    bool flag = 0;
    while (T --)
    {
        if (it[1] > it[2]) swap(it[1],it[2]),flag ^= 1;
        type = read();
        if (type == '<' || type == '>' || type == 'D' || type == 'I') whi = read();
        if (type == 'I') ch = read();
        int wh = ((whi == 'L')?(1):(2));
        if (flag) wh = 3 - wh;
        if (type == '<')
        {
            if (it[wh] == 0) 
            {
                putchar('F'),putchar('\n');
                continue;
            }
            it[wh] = st[it[wh]].le;
            putchar('T'),putchar('\n');
        }
        if (type == '>')
        {
            if (it[wh] == st[n].le)
            {
                putchar('F'),putchar('\n');
                continue;
            }
            it[wh] = st[it[wh]].ri;
        }
        if (type == 'I')
        {
            // ++ len;
            st[st[it[wh]].ri].le = ++ len,
            st[len].le = it[wh],st[len].ri = st[it[wh].ri].ri;
            st[it[wh]].ri = len;
            st[len].c = ch;
        }
        if (type == 'D')
        {
            st[st[it[wh]].le].ri = st[it[wh]].ri,
            st[st[it[wh]].ri].le = st[it[wh]].le;               
        }
        if (type == 'S')
        {
            for (int tmp = st[0].ri;tmp != n;tmp = st[tmp].ri)
                putchar(st[tmp].c);
        }
        if (type == 'R')
        {
            if (flag || (it[1] == it[2]))
            {
                putchar('F'),putchar('\n');
                continue;
            }
            flag ^= 1;
            int p = st[it[1]].le;
            st[it[1]].le = it[2];
            st[st[it[2]].le].ri = p;
            putchar('T'),putchar('\n');
        }
        
    }
}






