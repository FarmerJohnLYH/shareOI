#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;

#define N 670
#define M 2049
#define eps 0.5

const double pi = acos(-1);

int A[N][N], B[N][N], Sq[N][N], S[N][N];
int a[M*M], b[M*M], c[M*M];
int n, m, h, w, _X, _Y, K;

struct Z{double x, y; Z(double a=0, double b=0){x=a; y=b;}};
Z operator+(Z a, Z b){return Z(a.x+b.x, a.y+b.y);}
Z operator-(Z a, Z b){return Z(a.x-b.x, a.y-b.y);}
Z operator*(Z a, Z b){return Z(a.x*b.x-a.y*b.y, a.x*b.y+b.x*a.y);}

struct FFT{
	Z a[M*M], b[M*M], t[M*M];
	int n, ci;
	void DFT(Z *a, int sig, int n){
		// Bit_Reverse
		for(int i=0; i<n; i++){
			int p=0;
			for(int j=0, tp=i; j<ci; j++, tp/=2) p = (p<<1) + (tp&1);
			t[p] = a[i];
		}
		// DFT
		for(int m=2; m<=n; m*=2){
			int hal = m/2;
			for(int i=0; i<hal; i++){
				Z w = Z(cos(i*sig*pi/hal), sin(i*sig*pi/hal));
				for(int k=i; k<n; k+=m){
					Z p = t[k], q = w*t[k+hal];
					t[k] = p + q;
					t[k+hal] = p - q;
				}
			}
		}
		for(int i=0; i<n; i++) a[i] = t[i];
	}
	int found(int x){
		int r = 1; for(; r<x; r*=2);
		return r*2;
	}
	int calc(int x){return (x==1)?0:calc(x/2)+1;}
	void work(int *A, int *B, int n, int *C){
		for(int i=0; i<n; i++) a[i] = Z(A[i], 0);
		for(int i=0; i<n; i++) b[i] = Z(B[i], 0);
		n = found(n);
		ci = calc(n);
		DFT(a, 1, n); DFT(b, 1, n);
		for(int i=0; i<n; i++) a[i] = a[i] * b[i];
		DFT(a, -1, n);
		for(int i=0; i<n; i++) 
		{
			C[i] = int(round(a[i].x/n));
			printf("%d ",C[i]);	
		}printf("\n");
	}
}_fft;

struct RECORD{
	int dat, x, y;
	void in(int _d, int _x, int _y){dat = _d; x = _x; y = _y;}
}Q[N*N];
bool cmp(RECORD x, RECORD y){
	if(x.dat!=y.dat) return x.dat<y.dat;
	if(x.x != y.x) return x.x<y.x;
	return x.y<y.y;
}

int main(){
	
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) for(int j=0; j<m; j++) scanf("%d", &A[i][j]);
	for(int i=0; i<n; i++) for(int j=0; j<m; j++) a[i*m+j] = A[i][j];
	
	scanf("%d%d", &h, &w);
	for(int i=0; i<h; i++) for(int j=0; j<w; j++) scanf("%d", &B[i][j]);
	for(int i=0; i<h; i++) for(int j=0; j<w; j++) b[(h-i-1)*m+w-j-1] = B[i][j];
	
	_fft.work(a, b, n*m, c);
	
	scanf("%d%d", &_X, &_Y); _X--; _Y--;
	printf("%d\n",n*m*2);
	fo(i,0,n*m*2-1)
	{
		printf("%d ",a[i]);
	}printf("\n");
	fo(i,0,n*m*2-1)
	{
		printf("%d ",b[i]);
	}printf("\n");
	int sqrb = 0, sumb = 0;
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			sqrb += B[i][j] * B[i][j];
			sumb += B[i][j];
		}
	}
	
	for(int i=n-1; i>=0; i--){
		for(int j=m-1; j>=0; j--){
			Sq[i][j] = Sq[i+1][j] + Sq[i][j+1] - Sq[i+1][j+1] + A[i][j] * A[i][j];
			S[i][j] = S[i+1][j] + S[i][j+1] - S[i+1][j+1] + A[i][j];
		}
	}
	
	int qcnt = 0;
	for(int i=0; i<=n-h; i++){
		for(int j=0; j<=m-w; j++){
		
			int p = i+h-1, q = j+w-1, x = i+_X, y = j+_Y;
			
			int ret = Sq[i][j] - Sq[i][q+1] - Sq[p+1][j] + Sq[p+1][q+1];
			ret += A[x][y] * A[x][y] * h * w + sqrb;
			ret -= 2 * (S[i][j] - S[i][q+1] - S[p+1][j] + S[p+1][q+1]) * A[x][y];
			ret += 2 * sumb * A[x][y];
			ret -= 2 * c[p*m+q];
			Q[++qcnt].in(ret, i, j);
		}
	}
	
	scanf("%d", &K);
	sort(Q+1, Q+qcnt+1, cmp);
	for(int i=1; i<=K; i++) printf("%d %d %d\n", Q[i].x+1, Q[i].y+1, Q[i].dat);
	
	return 0;
}
