#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#define N 666670
#define mo 19260817
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
int i,j,k,l,n,m,K;
int ans,sum,temp;
int gs[N],a[N],f1[N];
int pm[N];
int Sig_B[N],Bi,Ci;
int Sig_A[N],Sig_A2[N],Gs[N],Ai;
int tr[N];
int la[N],bw[N],hd[N];
int Calc[N];
bool bz[N];
int read(){
	int fh=0,rs=0;char ch=0;
	while((ch<'0'||ch>'9')&&(ch^'-'))ch=getchar();
	if(ch=='-')fh=1,ch=getchar();
	while(ch>='0'&&ch<='9')rs=(rs<<3)+(rs<<1)+(ch^'0'),ch=getchar();
	return fh?-rs:rs;
}
int lowbit(int x){return x&(-x);}
void add(int x,int num){
	for(;x<=n;x=x+lowbit(x))tr[x]=tr[x]+num;
}
int qry(int x){
	int rs=0;
	for(;x;x=x-lowbit(x))rs=rs+tr[x];
	return rs;
}
int main(){
	n=read();
    fo(i,1,n){
    	a[i]=read();
    	if(!hd[a[i]])hd[a[i]]=i;
    	la[i]=bw[a[i]];
    	bw[a[i]]=i;
    	gs[a[i]]++;
	}
	fo(i,1,n)if(gs[i]){
		f1[i]=1ll*gs[i]*(gs[i]-1)%mo;
		f1[i]=1ll*f1[i]*9630409%mo;
		sum=(sum+f1[i])%mo;
	}
	fo(i,1,n)if(gs[i]){
		ans=(ans+1ll*f1[i]*(sum-f1[i]+mo)%mo)%mo;
	}
	ans=(1ll*ans*9630409)%mo;//总数 
	//AABB
	pm[0]=0;
	fo(i,2,n){
		Calc[i]=(Calc[i-1]+i-1)%mo;
	}
	fo(i,1,n){
		pm[i]=pm[la[i]]+1;
		sum=(sum-(gs[a[i]]-pm[i])+mo)%mo;
		temp=(sum-Calc[gs[a[i]]-pm[i]]+mo)%mo;
		ans=(ans-1ll*temp*(pm[i]-1)%mo+mo)%mo;
	}
	//ABBA
	K=sqrt(n/log2(n));
	fo(i,1,n)if(gs[i]>=K)bz[i]=1;
	//1 LPPL
	fo(i,1,n)if(bz[i]){
		fo(j,1,n)Sig_B[j]=0;
		Bi=0;
		fo(j,1,n){
			k=a[j];
			if(k==i)Bi++;
			else
			if(!bz[a[j]]){
				Ci=gs[i]-Bi;
			    ans=(ans-1ll*Sig_B[k]*Ci%mo+mo)%mo;
			    Sig_B[k]+=Bi;
			}
		}
	}
	//2 *LL*
	fo(i,1,n)if(bz[i]){
		fo(j,1,n)Sig_A[j]=Sig_A2[j]=Gs[j]=0;
		temp=0;
		fo(j,1,n){
			if(a[j]==i)Ai++;
			else{
				k=a[j];
				temp=(temp+1ll*Gs[k]*(1ll*Ai*Ai)%mo)%mo;
				temp=(temp+Sig_A2[k]+Sig_A[k])%mo;
				temp=(temp-2ll*Ai*Sig_A[k]%mo)%mo;
				temp=(temp-1ll*Gs[k]*Ai%mo)%mo;
				Sig_A[k]=(Sig_A[k]+Ai)%mo;
				Sig_A2[k]=(Sig_A2[k]+1ll*Ai*Ai%mo)%mo;
				Gs[k]++;
			}
		}
		ans=(ans-1ll*temp*9630409%mo+mo)%mo;
	}
	//3 PPPP
	fo(i,1,n)if(gs[a[i]]&&!bz[a[i]]){
		for(j=la[i];j;j=la[j]){
			temp=(qry(i-1)-qry(j)+mo)%mo;
			temp=(temp-Calc[pm[i]-pm[j]]+mo)%mo;
			ans=(ans-temp+mo)%mo;
			add(j,1);
		}
	}
	printf("%d",ans);
	return 0;
}