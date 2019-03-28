#include<cstdio>
#include<cstring>
char s[1000100];
int mx[2000100],r[2000100],ch[26][2000100],par[2000100],pcnt;
void build()
{
    int p=pcnt=1;
    for(int i=1;s[i]!='\0';++i)
    {
        int w=s[i]-'a';
        int np=++pcnt;
        r[np]=1;
        mx[np]=mx[p]+1;
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
}e[2000100];
int head[2000100],ecnt=-1;
void add(int from,int to)
{
    e[++ecnt]=edge(to,head[from]);
    head[from]=ecnt;
}
long long ans=0;
void dfs(int x)
{
    for(int i=head[x];~i;i=e[i].nxt)
    {
        dfs(e[i].n);
        r[x]+=r[e[i].n];
    }
    if(r[x]>1)
        ans=ans>(long long)mx[x]*r[x]?ans:(long long)mx[x]*r[x];
}
int main()
{
    memset(head,-1,sizeof(head));
    scanf("%s",s+1);
    build();
    for(int i=2;i<=pcnt;++i)
        add(par[i],i);
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}