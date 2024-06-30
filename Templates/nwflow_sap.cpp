int dfs(int x,int qv)
{
	if(x==tt) return qv;
	int nw=0;
	for(int tp=las[x];tp;tp=tp[nex])
	if(v[tp]>0 && d[to[tp]]+1==d[x])
	{
		int tmp=dfs(to[tp],min(v[tp],qv-nw));
		nw+=tmp,v[tp]-=tmp,v[tp^1]+=tmp;
		if(qv==nw) return qv;
	}
	--g[d[x]],++d[x],++g[d[x]];
	if(g[d[x]-1]==0) d[ss]=cnt;
	return nw;
}
int main()
{ 
	g[0]=cnt;
	while(d[ss]<cnt) sum+=dfs(ss,oo);
}
