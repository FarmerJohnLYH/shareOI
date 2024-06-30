#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm> 
using namespace std;
const long long Mo = 998244353;
struct Matrix{
    long long n,m;
    long long value[6][6];
    Matrix()
    {
        memset(value,0,sizeof value);
    }
};
long long n;
Matrix a,b;
Matrix Mul(Matrix a,Matrix b) 
{
    Matrix ans = Matrix();
    for (long long i = 1;i <= a.n;i ++)
        for (long long j = 1;j <= b.m;j ++) 
            for (long long k = 1;k <= a.m;k ++)
                ans.value[i][j] = (ans.value[i][j] + a.value[i][k] * b.value[k][j]) % Mo;
    ans.n = a.n,ans.m = b.m;
    return ans;
}
Matrix MatrQsm(Matrix a,long long e)
{
    if (e == 1) return a;
    Matrix tmp = MatrQsm(a,e >> 1);
    tmp = Mul(tmp,tmp);
    if (e & 1) tmp = Mul(tmp,a);
    return tmp;
}
int main()
{
    scanf("%lld", &n);
    b = Matrix();
    b.n = 5,b.m = 5;
    b.value[1][2] = b.value[1][4] = b.value[1][5] = 
    b.value[2][1] = b.value[2][2] = b.value[2][4] = b.value[2][5] =
    b.value[3][4] = b.value[3][5] =
    b.value[4][3] = b.value[4][4] = b.value[4][5] = 
    b.value[5][5] = 1;
    //友矩阵 
    a.n = 1,a.m = 5;
    a.value[1][1] = a.value[1][2] = a.value[1][3] = 1,a.value[1][4] = 2,a.value[1][5] = 3;
    //初始矩阵 
    Matrix c = a; 
    c = MatrQsm(b,n - 1); 
    c = Mul(a,c);
    //答案矩阵 
    printf("%lld", c.value[1][5]);
}