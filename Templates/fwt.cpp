void FWT(int *a,int l,int r) {
	if (l==r) return;
	int mid=(l+r)>>1,len=mid-l+1;
	FWT(a,l,mid);FWT(a,mid+1,r);
	fo(i,l,mid)
	{
		int u=a[i],v=a[i+len];
		a[i]=(u+v)%mo;a[i+len]=(u-v)%mo;
	}
}
void IFWT(int *a,int l,int r) {
	if (l==r) return;
	int mid=(l+r)>>1,len=mid-l+1;
	fo(i,l,mid)
	{
		int u=a[i],v=a[i+len];
		a[i]=(u+v)*inv2%mo;a[i+len]=(u-v)*inv2%mo;
	}
	IFWT(a,l,mid);IFWT(a,mid+1,r);
}
//xor
//异或 tf(A)=(tf(A0)+tf(A1),tf(A0)-tf(A1))
//    utf(A)=((utf(A0)+utf(A1))/2,(utf(A0)-utf(A1))/2)
//or
//或   tf(A)=(tf(A0),tf(A1)+tf(A0))
//    utf(A)=(utf(A0),utf(A1)-utf(A0))
//and
//与   tf(A)=(tf(A0)+tf(A1),tf(A1))
//    utf(A)=(utf(A0)-utf(A1),utf(A1))