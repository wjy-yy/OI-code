#include<cstdio>
#include<cstring>
#include<queue>
using std::priority_queue;
int read()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
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
}e[200100];
int head[100100],ecnt=-1;
void add(int from,int to,int v)
{
    e[++ecnt]=edge(to,head[from],v);
    head[from]=ecnt;
}
struct sta
{
    int n,dis;
    sta(int n,int dis)
    {
        this->n=n;
        this->dis=dis;
    }
    sta(){}
    friend bool operator <(sta a,sta b)
    {return a.dis>b.dis;}
};
priority_queue<sta> q;
int dis[100100];
int main()
{
    memset(dis,0x3f,sizeof(dis));
    memset(head,-1,sizeof(head));
    int n,m,S,u,v,w;
    scanf("%d%d%d",&n,&m,&S);
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    dis[S]=0;
    q.push(sta(S,0));
    while(!q.empty())
    {
        sta k=q.top();
        q.pop();
        if(k.dis>dis[k.n])
            continue;
        for(int i=head[k.n];~i;i=e[i].nxt)
            if(dis[e[i].n]>k.dis+e[i].v)
            {
                dis[e[i].n]=k.dis+e[i].v;
                q.push(sta(e[i].n,dis[e[i].n]));
            }
    }
    for(int i=1;i<=n;++i)
        printf("%d ",dis[i]);
    return 0;
}
