#include<cstdio>
#include<cstring>
struct edge
{
    int n,nxt;
    edge(int n,int nxt)
    {
        this->n=n;
        this->nxt=nxt;
    }
    edge(){}
}e[5050];
int head[5050],ecnt=-1;
void add(int from,int to)
{
    e[++ecnt]=edge(to,head[from]);
    head[from]=ecnt;
}
int s[5050];
bool used[5050];
bool Find(int x)
{
    if(used[x])
        return false;
    used[x]=1;
    for(int i=head[x];~i;i=e[i].nxt)
        if(s[e[i].n]==-1||Find(s[e[i].n]))
        {
            s[e[i].n]=x;
            return true;
        }
    return false;
}
int a[5050],b[5050],c[5050];
int ans[5050];
int main()
{
    memset(head,-1,sizeof(head));
    memset(s,-1,sizeof(s));
    int n,m,q;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)
        scanf("%d",&b[i]);
    scanf("%d",&q);
    for(int i=1;i<=q;++i)
    {
        scanf("%d",&c[i]);
        used[c[i]]=1;
    }
    for(int i=1;i<=n;++i)
        if(!used[i])
            add(a[i],b[i]);
    int t=0;
    for(int i=q;i>=1;--i)
    {
        memset(used,0,sizeof(used));
        while(Find(t))
        {
            ++t;
            memset(used,0,sizeof(used));
        }
        ans[i]=t;
        add(a[c[i]],b[c[i]]);
    }
    for(int i=1;i<=q;++i)
        printf("%d\n",ans[i]);
    return 0;
}

