#include<cstdio>
#include<cstring>
#include<queue>
using std::queue;
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
}e[500100];
int head[10010],ecnt=-1;
void add(int from,int to,int v)
{
    e[++ecnt]=edge(to,head[from],v);
    head[from]=ecnt;
}
queue<int> q;
bool used[10010];
int dis[10010];
int main()
{
    memset(head,-1,sizeof(head));
    memset(dis,0x3f,sizeof(dis));
    int n,m,S,u,v,w;
    scanf("%d%d%d",&n,&m,&S);
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    q.push(S);
    dis[S]=0;
    used[S]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        used[x]=0;
        for(int i=head[x];~i;i=e[i].nxt)
            if(dis[e[i].n]>dis[x]+e[i].v)
            {
                dis[e[i].n]=dis[x]+e[i].v;
                if(!used[e[i].n])
                {
                    q.push(e[i].n);
                    used[e[i].n]=1;
                }
            }
    }
    for(int i=1;i<=n;++i)
        printf("%d ",dis[i]<1000000000?dis[i]:2147483647);
    return 0;
}