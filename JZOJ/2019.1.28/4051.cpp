#include<cstring>
#include<cstdio>
#include<algorithm>
#define L long long
#define fo(i,a,b)for(int i=a;i<=b;i++)
using namespace std;
const int A=8005,M=17000,mo=1004535809;
int n,m,N,x,y,s,a[A],fy[A],q[A],f[M],t[M],ny,h[M];
L w[M];
L ksm(L x,int y){
	L t=1;
	for(;y;y>>=1,x=x*x%mo)if(y&1)t=t*x%mo;
	return t;
}
bool ty(int x){
	q[0]=1;
	fo(i,1,m-2){
		q[i]=q[i-1]*x%m;
		if(fy[q[i]]){
			fo(j,1,i)fy[q[j]]=0;
			return 0;
		}
		fy[q[i]]=i;
	}
	return 1;
}
void dft(int *a)
{
	fo(i,1,N)if(h[i]>i)swap(a[i],a[h[i]]);
	int A;
	for(int i=2,m;m=i>>1,i<=N;i<<=1)for(int j=0;j<N;j+=i)for(int k=0;k<m;k++)
		A=w[N/i*k]*a[j+k+m]%mo,a[j+k+m]=(a[j+k]-A+mo)%mo,a[j+k]=(a[j+k]+A)%mo;
}
void idft(int *a)
{
	fo(i,1,N>>1)swap(a[i],a[N-i]);
	dft(a);
	fo(i,0,m-2)a[i]=((L)a[i]+a[i+m-1])*ny%mo,a[i+m-1]=0;
}
void mult(int *a,int *b)
{
	dft(a);dft(b);
	fo(i,0,N-1)a[i]=(L)a[i]*b[i]%mo;
	idft(a);idft(b);
}
void mult2(int *a)
{
	dft(a);
	fo(i,0,N-1)a[i]=(L)a[i]*a[i]%mo;
	idft(a);
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&x,&s);
	fo(i,2,m)if(ty(i))break;
	fo(i,1,s)scanf("%d",&y),y?f[fy[y]]=1:0;
	for(N=1;N<m*2;N<<=1);
	fo(i,1,N-1)h[i]=i==(i&-i)?N/2/i:h[i&-i]+h[i-(i&-i)];
	w[0]=1;w[1]=ksm(3,(mo-1)/N);ny=ksm(N,mo-2);
	fo(i,2,N-1)w[i]=w[i-1]*w[1]%mo;
	for(t[0]=1;n;n>>=1,mult2(f))if(n&1)mult(t,f);
	printf("%d",t[fy[x]]);
}





