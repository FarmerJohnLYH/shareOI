
void fnit(int cs)
{
	w[0]=1,w[1]=qsm(3,(mo-1)/cs);
	fo(i,2,cs-1) w[i]=1ll*w[i-1]*w[1]%mo;
	wz[0]=0;fo(i,1,cs-1) wz[i]=(wz[i>>1]>>1)+((i&1)*(cs>>1)); 
	rsz=qsm(cs,mo-2);
}

void dft(int flag)
{
	fo(i,0,cs-1) e[wz[i]]=a[i];int tp;
	if(flag==-1) fo(i,1,cs>>1) swap(w[i],w[cs-i]);
	for(int wv=2,hf=1;wv<=cs;hf=wv,wv<<=1)
	fo(i,0,hf-1) for(int j=i;j+hf<cs;j+=wv)
	tp=1ll*w[cs/wv*i]*e[j+hf]%mo,e[j+hf]=(e[j]-tp+mo)%mo,e[j]=(e[j]+tp)%mo;
	if(flag==-1) fo(i,1,cs>>1) swap(w[i],w[cs-i]);
	fo(i,0,cs-1)
	{
		a[i]=e[i];
		if(flag==-1)a[i]=1ll*a[i]*rsz%mo;
	}
}
