
void dft(ll *a){
	fo(i,1,Q)if(i<h[i])swap(a[i],a[h[i]]);ll A;
	for(int i=2,j,k,m,g=1;m=i>>1,i<=Q;g++,i<<=1)for(j=0;j<Q;j+=i)for(k=0;k<m;k++)
		A=w[(Q>>g)*k]*a[j+m+k],a[j+m+k]=(a[j+k]-A)%mo,a[j+k]=(a[j+k]+A)%mo;
}
	w[0]=1;w[1]=ksm(3,(mo-1)/Q);Ny=ksm(Q,mo-2);
	fo(i,1,Q)w[i]=w[i-1]*w[1]%mo,h[i]=(h[i>>1]>>1)|(i&1)*(Q>>1);
	dft(a);dft(b);
	fo(i,0,Q)a[i]=a[i]*b[i]%mo;
	fo(i,1,Q>>1)swap(a[i],a[Q-i]);
	dft(a);