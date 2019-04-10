#include<cstdio>
#include<cstring>
int Min(int x,int y){return x<y?x:y;}
struct edge
{
    int n,nxt,v;
    edge(int n,int nxt,int v)
    {
        this->n=n;
        this->nxt=nxt;
        this->v=v;
    }
    edge(){}
}e[10100];
int head[105],cur[105],ecnt=-1;
void add(int from,int to,int v)
{
    e[++ecnt]=edge(to,head[from],v);
    head[from]=ecnt;
    e[++ecnt]=edge(from,head[to],0);
    head[to]=ecnt;
}
int q[105],d[105],s,t;
bool bfs()
{
    int l=0,r=0;
    memset(d,0,sizeof(d));
    d[t]=1;
    q[++r]=t;
    while(l<r)
    {
        int x=q[++l];
        for(int i=head[x];~i;i=e[i].nxt)
            if(!d[e[i].n]&&e[i^1].v)
            {
                d[e[i].n]=d[x]+1;
                q[++r]=e[i].n;
            }
    }
    return d[s]>0;
}
int dinic(int x,int in)
{
    if(x==t)
        return in;
    int flow=in;
    for(int &i=cur[x];~i;i=e[i].nxt)
        if(e[i].v&&d[e[i].n]==d[x]-1)
        {
            int tmp=dinic(e[i].n,Min(e[i].v,flow));
            if(!tmp)
                d[e[i].n]=0;
            e[i].v-=tmp;
            e[i^1].v+=tmp;
            flow-=tmp;
            if(!flow)
                break;
        }
    return in-flow;
}
int main()
{
    memset(head,-1,sizeof(head));
    int n,m,u,v,w;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    long long ans=0;
    while(bfs())
    {
        for(int i=1;i<=n;++i)
            cur[i]=head[i];
        int tmp=dinic(s,0x3fffffff);
        while(tmp)
        {
            ans+=tmp;
            tmp=dinic(s,0x3fffffff);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
