#include <cmath>
#include <ctime>
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
const int P=10100;
int a,b,c,d;
int n,m;
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int tmp=b;
    while(tmp%c) tmp+=b;
    for (;!((n>a)&&(n>=c)&&(m>d)&&(m>=b)&&((n*a)&1^1)&&((m*d)&1^1));tmp+=b)
    {
        printf("");
    }

    return 0;
}


/*





    repeat
         inc(max,b);
         while max mod c<>0 do inc(max,b);
         n:=max div b;
         m:=max div c;
    until (n>a)and(n>=c)and(m>d)and(m>=b)and((n*a) mod 2=0)and((m*d) mod 2=0);
    writeln(n,' ',m);
    t:=n+1;
    for i:=1 to n do begin
        k:=0;
        while k<b do begin
            inc(k);
            writeln(i,' ',t);
            inc(t);
            if t>n+m then t:=n+1;
        end;
    end;
    t:=1;
    for i:=1 to n do begin
        while pd[i]<a do begin
            inc(t);
            if pd[t]<a then begin
            writeln(i,' ',t);
            inc(pd[i]);
            inc(pd[t]);
            end;
            if t=n then t:=i;
        end;
        if t=i then inc(t);
    end;
    t:=n+1;
    for i:=n+1 to n+m do begin
        while pd[i]<d do begin
            inc(t);
            if pd[t]<d then begin
            writeln(i,' ',t);
            inc(pd[i]);
            inc(pd[t]);
            end;
            if t=n+m then t:=i;
        end;
        if t=i then inc(t);
    end;
end.*/