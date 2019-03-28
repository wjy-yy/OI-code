#include<cstdio>
#include<cstring>
#define ll long long
char s[200100],t[200100];
int ch[26][400100],mx[400100],r[400100],par[400100],pcnt;
void build()
{
    int p=pcnt=1;
    for(int i=1;s[i]!='\0';++i)
    {
        int w=s[i]-'a';
        int np=++pcnt;
        mx[np]=mx[p]+1;
        r[np]=1;
        while(p&&!ch[w][p])
        {
            ch[w][p]=np;
            p=par[p];
        }
        if(!p)
            par[np]=1;
        else
        {
            int q=ch[w][p];
            if(mx[q]==mx[p]+1)
                par[np]=q;
            else
            {
                int nq=++pcnt;
                mx[nq]=mx[p]+1;
                for(int j=0;j<26;++j)
                    ch[j][nq]=ch[j][q];
                while(p&&ch[w][p]==q)
                {
                    ch[w][p]=nq;
                    p=par[p];
                }
                par[nq]=par[q];
                par[q]=par[np]=nq;
            }
        }
        p=np;
    }
}
struct edge
{
    int n,nxt;
    edge(int n,int nxt)
    {
        this->n=n;
        this->nxt=nxt;
    }
    edge(){}
}e[400100];
int head[400100],ecnt=-1;
void add(int from,int to)
{
    e[++ecnt]=edge(to,head[from]);
    head[from]=ecnt;
}
void dfs(int x)
{
    for(int i=head[x];~i;i=e[i].nxt)
    {
        dfs(e[i].n);
        r[x]+=r[e[i].n];
    }
}
ll sum[400100];
void Dfs(int x)
{
    sum[x]+=(mx[x]-mx[par[x]])*r[x];
    for(int i=head[x];~i;i=e[i].nxt)
    {
        sum[e[i].n]+=sum[x];
        Dfs(e[i].n);
    }
}
int main()
{
    freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    memset(head,-1,sizeof(head));
    scanf("%s",s+1);
    build();
    for(int i=2;i<=pcnt;++i)
        add(par[i],i);
    dfs(1);
    r[1]=0;
    Dfs(1);
    scanf("%s",t+1);
    int p=1;
    ll ans=0,len=0;
    for(int i=1;t[i]!='\0';++i)
    {
        while(p&&!ch[t[i]-'a'][p])
            p=par[p];
        if(!p)
        {
            p=1;
            len=0;
        }
        else
        {
            len=(mx[p]<len?mx[p]:len)+1;
            p=ch[t[i]-'a'][p];
        }
        //ans+=sum[par[p]]+r[p]*len[p];
        ans+=sum[par[p]]+r[p]*(len-mx[par[p]]);
    }
    printf("%lld\n",ans);
    return 0;
}

/*
aaaaaaaca
aaca

aacaacaabaacaacaa
acabaabaabaaca
*/