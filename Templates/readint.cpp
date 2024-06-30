int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int buf[30],b0;
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	b0=0;
	if(x==0)putchar('0');
	else
	while(x) buf[++b0]=x%10,x/=10;
	fd(i,b0,1) putchar(buf[i]+'0');
}