#include<cstdio>
#include<cstring>
#define p 1000000007
struct edge
{
    int n,nxt;
    edge(int n,int nxt)
    {
        this->n=n;
        this->nxt=nxt;
    }
    edge(){}
}e[200100];
int head[100100],ecnt=-1;
void add(int from,int to)
{
    e[++ecnt]=edge(to,head[from]);
    head[from]=ecnt;
    e[++ecnt]=edge(from,head[to]);
    head[to]=ecnt;
}
int Plus(int x,int y){return x+y>=p?x+y-p:x+y;}
int Mul(int x,int y){return 1ll*x*y%p;}
int qpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1)
            ans=Mul(ans,x);
        x=Mul(x,x);
        y>>=1;
    }
    return ans;
}
bool used[100100];
int dfs(int x)
{
    used[x]=1;
    int cnt=1;
    for(int i=head[x];~i;i=e[i].nxt)
        if(!used[e[i].n])
            cnt+=dfs(e[i].n);
    return cnt;
}
int main()
{
    memset(head,-1,sizeof(head));
    int n,m,u,v,w;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;++i)
    {
        scanf("%d%d%d",&u,&v,&w);
        if(!w)
            add(u,v);
    }
    int ans=qpow(n,m);
    for(int i=1;i<=n;++i)
        if(!used[i])
        {
            int tmp=dfs(i);
            ans=Plus(ans,p-qpow(tmp,m));
        }
    printf("%d\n",ans);
    return 0;
}