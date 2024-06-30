
#include<iostream>  
#include<algorithm>  
#include<string>  
#include<iomanip>  
#include<memory.h>  
#include<time.h>  
#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<stdbool.h>  
#include<math.h>  
#define min(a,b) ((a)<(b)?(a):(b))  
#define max(a,b) ((a)>(b)?(a):(b))  
#define abs(a) ((a)>0?(a):(-(a)))  
#define lowbit(a) (a&(-a))  
#define sqr(a) ((a)*(a))  
#define swap(a,b) ((a)^=(b),(b)^=(a),(a)^=(b))  
#define eps 1e-8  
#define J 10000000  
#define MAX 0x7f7f7f7f  
#define PI 3.1415926535897  
#define N 1007  
#define M 10007  
using namespace std;  
typedef long long LL;  
int cas,cass;  
int n,m,lll,ans;  
LL k[M];  
char ch[N];  
void write(LL a[])  
{  
    printf("%lld",a[a[0]]);  
    fd(i,a[0] - 1,1) printf("%lld",a[i]);  
}  
int cmp(LL a[],LL b[])//-1:a=b  0:a<b  1:a>b  
{    
    if (a[0] != b[0]) return (a[0] > b[0]);  
    fd(i,a[0],1)
    if (a[i] != b[i]) return (a[i] > b[i]);  
    return -1;
}  
void mult(LL a[],LL b[],LL c[])  
{  
    LL t[M];  
    memset(t,0,sizeof t);
    t[0] = a[0] + b[0] + 1;  
    fo(i,1,a[0]) fo(j,1,b[0])
        t[i + j - 1] += a[i] * b[j];
    fo(i,1,t[0]) t[i + 1] += t[i] / J,t[i] %= J;
    while (!t[t[0]] && t[0] > 1) -- t[0];  
    fo(i,0,t[0]) c[i] = t[i];
}  
void qsm(LL a[],LL x)  
{  
    LL t[M];
    t[0] = 1,t[1] = 2;
    a[0] = a[1] = 1;  
    while (x)  
    {  
        if (x & 1) mult(a,t,a);  
        mult(t,t,t);  
        x >>= 1;  
    }  
}  
void ins(char s[],LL a[])  
{  
    int l = strlen(s);
    for (int tmp = l,a[0] = 1;i > 6;i -= 7,++ a[0])
    {  
        fo(j,0,6) a[a[0] = a[a[0]]] * 10 + (s[i - 7 + j] -'0');
    }  
    for (int tmp = 0;s[tmp])
    a[a[0]] = a[a[0]] * 10 + s[j] - '0';
    for(j=0;j<i;j++)  
        a[a[0]]=a[a[0]]*10+s[j]-'0';  
}  
void summing(LL a[],LL b[],LL c[])  
{  
    LL t[M];  
    memset(t,0,sizeof t);
    t[0]=max(a[0],b[0]);  
    fo(i,1,t[0]) t[i] = a[i] + b[i];
    fo(i,1,t[0]) t[i + 1] += t[i] / J,t[i] %= J;
    while (t[t[0] + 1]) ++ t[0];  
    memcpy(c,t,sizeof(t));  
}  
void minu(LL a[],LL b[],LL c[])  
{  
    int i;  
    LL t[M];
    memset(t,0,sizeof t);  
    t[0] = a[0];  
    fo(i,1,t[0]) t[i] = a[i] - b[i];
    fo(i,1,t[0] - 1) 
    if (t[i] < 0) -- t[i + 1],t[i] += J;
    while (!t[t[0]] && t[0] > 1) -- t[0];  
    memcpy(c,t,sizeof(t));  
}  
void divt(LL a[])  
{  
    fd(i,a[0],2)
    {  
        if (a[i] & 1) a[i - 1] += J;  
        a[i] >>= 1;  
    }  
    a[1] >>= 1;  
    while (!a[a[0]] && a[0] > 1) -- a[0];  
}  
void sigc(LL t[],LL mid,LL tt[])  
{  
    qsm(t,mid - 1);  
    tt[1] = n - 3;  
    mult(t,tt,t);  
    tt[1] = mid * 3;  
    summing(t,tt,t);  
    tt[1] = n;  
    minu(t,tt,t);  
}  
void work()  
{  
    LL t[M],tt[M];
    memset(t,0,sizeof t);
    memset(tt,0,sizeof tt);
    tt[0] = 1;  
    int l = 1，r = 3340;  
    while (l <= r)  
    {  
        int mid = (l + r) >> 1;  
        sigc(t,mid,tt);  
        int j = cmp(k,t);  
        if (j == -1)  
        {  
            qsm(t,mid-2);  
            tt[1] = n - 1;  
            mult(t,tt,t);  
            tt[1] = 1;  
            summing(t,tt,t);  
            write(t);  
            return;  
        }  
        if (j) l = mid + 1;  
        else r = mid - 1;  
    }  
    sigc(t,r,tt);  
    minu(k,t,k);  
    qsm(t,r);  
    tt[1] = 2;  
    minu(t,tt,t);  
    summing(k,t,t);  
    write(t);  
}  
int main()  
{  
    freopen("D:/LiuYuanHao/s.in","r",stdin);
    ans[1][1] = 1;
    ans[2][1] = 1,ans[2][2] = 2,ans[2][3] = 3;
    while (scanf("%d", &n) != EOF)  
    {
        if (n < 4)  
        {  
            scanf("%d",&m);
            if (n <= 2) 
                if (ans[n][m] == 0) printf("-1");
                else printf("%d", ans[n][m]);
            if (n == 3)  
            {  
                qsm(k,(m + 2) / 3);  
                if (m % 3 == 1) -- k[1];  
                if (m % 3 == 0) ++ k[1];  
                write(k);  
            }
            continue; 
        }  
        memset(k,0,sizeof k);  
        scanf("%s", ch);  
        ins(ch,k);  
        work();  
    }  
}  
  