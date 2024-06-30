char s[N];
struct pali{
	int sz,cnt[N];
	int to[N][26],fail[N];
	int len[N],ln,las;
	int st[N];
	int gf(int x){while(st[ln-len[x]-1]!=st[ln])x=fail[x];return(x);}
	void add(int x)
	{
		st[++las]=x;int p=gf(las);
		if(!to[p][x]) len[++sz]=len[p]+2,fail[sz]=to[gf(fail[p])][x],to[p][x]=sz;
		++cnt[las=to[p][x]];
	}
	void init()
	{
		len[sz=1]=-1;
		fail[0]=1;
		st[0]=-1;
		las=0;
	}
}
