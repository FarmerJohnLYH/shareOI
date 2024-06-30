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
#define fo(i,x,y) for (register int i = (x);i <= (y);++ i)
#define fd(i,x,y) for (register int i = (x);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
#define get(x) ((x=='L')?0:1)
const int N = 5000500;
char s[N],type;
int len;
int top0,top1,L,R;
char q[N * 4],S[2][N];
int n,f[2],dir;
void show()
{
    fo(i,1,top0) putchar(S[0][i]);
    for (int i = L;i != R;i += dir) putchar(q[i]);putchar(q[R]);
    fd(i,top1,0) putchar(S[1][i]);
    putchar('\n');
}
int readf()
{
    char ch; 
    scanf("%c", &ch); 
    return get(ch);
}
int main() 
{
    scanf("%s\n%d", s + 1, &n);
    int len = strlen(s + 1);
    f[0] = 0,f[1] = len;
    L = R = n+1; 
    fo(i,1,len - 1) q[R ++] = s[i];
    q[R] = s[len],dir = 1;

    fo(i,1,n)
    {
        int w;
        scanf("\n%c ", &type);
        if (type != 'R' && type != 'S') w = readf();
        if (type == '>') 
        {
            printf("%c\n", (f[w] == len)?'F':'T');
            if (f[w] < len) 
            {
                ++ f[w];
                if (w == 0) S[0][++ top0] = q[L],L += dir;
                else q[R += dir] = S[1][top1 --];
            }
        } 
        else
        if (type == '<') 
        {
            printf("%c\n",(f[w] == 0)?'F':'T');
            if (f[w] > 0) 
            {
                -- f[w];
                if (w == 0) q[L -= dir] = S[0][top0 --];
                else S[1][++ top1] = q[R],R -= dir;
            }
        } 
        else
        if (type == 'I') 
        {
            char ne; 
            scanf(" %c", &ne);
            if (w == 0) S[0][++ top0] = ne; 
            else q[R += dir] = ne;
            if (w == 0) 
            {
                if (f[1] >= f[0] ++) ++ f[1];
            } 
            else 
            {
                if (f[0] >= f[1] ++) ++f[0];
            }
            ++ len;
            printf("T\n");
        } 
        else 
        if (type == 'D') 
        {
            if (f[w] == len) 
            {
                printf("F\n"); 
                continue;
            } 
            else 
                printf("T\n");
            if (w == 0) L += dir; 
            else -- top1;
            if (w == 0) 
            {
                if (f[1] > f[0]) -- f[1];
            } 
            else 
            {
                if (f[0]>f[1]) -- f[0];
            }
            -- len;
        } 
        else 
        if (type=='R') 
        {
            // if (0) 
            // {
                // printf("F\n"); 
                // continue;
            // } 
            // else 
            printf("T\n");
            swap(L,R);dir = -dir;
        } 
        else 
        if (type=='S') show(),printf("\n");
    }
} 