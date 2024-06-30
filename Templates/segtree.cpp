//文中数组大小需要 [4 * 元素个数]

//————基本 兹瓷单点修改 O(log) 区间查询 max O(log) 单点查询 O(1)————
/*单点查询 第 x 个元素 d[bit + x]*/
void build(int n)
{
    for(bit=1;bit<=n+1;bit<<=1);//bit = 总节点数目 - 叶子节点数目
    for(int i=bit+1;i<=bit+n;i++)
        scanf("%d",&d[i]);
    for(int i=bit-1;i;i--)
        d[i]=max(d[i<<1],d[i<<1|1]);
}
void update(int x,int y)//修改 d[x] 为 y
{
    for(d[x+=bit]=y,x>>=1;x;x>>=1)
        d[x]=max(d[x<<1],d[x<<1|1]);
}
int query(int s,int t)//区间 [s,t] 最大值
{
    int ans=-1;
    for(s+=bit-1,t+=bit+1;s^t^1;s>>=1,t>>=1)
    {
        if(~s&1) ans=max(ans,d[s^1]);
        if(t&1) ans=max(ans,d[t^1]);
    }
    return ans;
}

//————差分 兹瓷单点修改 O(log) 区间取 max O(log) 单点查询 O(log) 区间修改 O(log) ————
void build(int n)
{
    for(bit=1;bit<=n+1;bit<<=1);//bit = 总节点数目 - 叶子节点数目
    for(int i=bit+1;i<=bit+n;i++)
        scanf("%d",&d[i]);
    for(int i=bit-1;i;i--)
    {
        d[i]=min(d[i<<1],d[i<<1|1]);
        d[i<<1]-=d[i];d[i<<1|1]-=d[i];
    }
}
void query(int x)//x = t + bit 单点查询 第 t 个元素
{
    int res=0;
    while(x)
        res+=d[x],x>>=1;
    return res;
}
void update(int s,int t,int x)//区间修改 [s,t] 为 x 单点修改由此间接实现即可
{
    int tmp;
    for(s+=bit-1,t+=bit+1;s^t^1;s>>=1,t>>=1)
    {
        if(~s&1) d[s^1]=x;
        if(t&1) d[t^1]=x;
        tmp=min(d[s],d[s^1]);d[s]-=tmp;d[s^1]-=tmp;d[s>>1]+=tmp;
        tmp=min(d[t],d[t^1]);d[t]-=tmp;d[t^1]-=tmp;d[t>>1]+=tmp;
    }
    while(s>1) tmp=min(d[s],d[s^1]),d[s]-=tmp,d[s^1]-=tmp,d[s>>=1]+=tmp;
}
int query(int s,int t) //区间查询 [s,t] 最大值
{
    int lans=-1,rans=-1,ans=-1;
    for(s+=bit-1,t+=bit+1;s^t^1;s>>=1,t>>=1)
    {
        lans+=d[s];rans+=d[t];
        if(~s&1)
            lans=max(lans,d[s^1]);
        if(t&1)
            rans=max(rans,d[t^1]);
    }
    for(ans=max(lans,rans);s>1;)
        ans+=d[s>>=1];
    return ans;
}













