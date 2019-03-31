#include<cstdio>
#include<cstring>
#include<cstdlib>
#define p 998244353
#define bs 257933
int v[100100],sum[100100],rdm[100100],ls[100100],rs[100100],lazy[100100],fa[100100],sz[100100],pcnt=0;
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
int Newnode(int x)
{
    ++pcnt;
    v[pcnt]=x;
    sum[pcnt]=x;
    rdm[pcnt]=rand();
    sz[pcnt]=1;
    lazy[pcnt]=1;
    return pcnt;
}

void pushdown(int rt)//lazytag 不下传
{
    if(lazy[rt]==1)
        return;
    int x=lazy[rt];
    lazy[rt]=1;
    v[rt]=Mul(v[rt],x);
    sum[rt]=Mul(sum[rt],x);
    lazy[ls[rt]]=Mul(lazy[ls[rt]],x);
    lazy[rs[rt]]=Mul(lazy[rs[rt]],x);
}
void maintain(int rt)
{
    pushdown(ls[rt]);
    pushdown(rs[rt]);
    sum[rt]=((sum[ls[rt]]+v[rt])%p+sum[rs[rt]])%p;
    sz[rt]=sz[ls[rt]]+sz[rs[rt]]+1;
    fa[ls[rt]]=rt;
    fa[rs[rt]]=rt;
}
int Merge(int a,int b)
{
    if(!a||!b)
        return a|b;
    pushdown(a);
    pushdown(b);
    if(rdm[a]<rdm[b])
    {
        rs[a]=Merge(rs[a],b);
        maintain(a);
        return a;
    }
    ls[b]=Merge(a,ls[b]);
    maintain(b);
    return b;
}
void split(int rt,int x,int &a,int &b)
{
    if(!rt)
    {
        a=b=0;
        return;
    }
    pushdown(rt);
    int L=sz[ls[rt]];
    if(x<=L)
    {
        b=rt;
        split(ls[b],x,a,ls[b]);
    }
    else
    {
        a=rt;
        split(rs[a],x-L-1,rs[a],b);
    }
    maintain(rt);
}
int getRank(int rt,int from)
{
    int ans=0;
    if(fa[rt])
        ans+=getRank(fa[rt],rt);
    if(from!=ls[rt])
        ans+=sz[ls[rt]]+1;
    return ans;
}
int root=0,lst[100100],F[100100];
int Pow[100100],Inv[100100];
int main()
{
    Pow[0]=1;
    Inv[0]=1;
    for(int i=1;i<=100000;++i)
    {
        Pow[i]=Mul(Pow[i-1],bs);
        Inv[i]=qpow(Pow[i],p-2);
    }
    int n,u,a,b,c;
    scanf("%d",&n);
    root=Newnode(1);
    lst[1]=1;
    for(int i=2;i<=n;++i)
    {
        scanf("%d",&u);
        int t=F[u];
        F[i]=u;
        while(t!=1)
        {
            int k1=getRank(lst[t],-1)-1;
            int k2=getRank(t,-1);
            split(root,k2,b,c);
            split(b,k1,a,b);
            lazy[a]=Mul(lazy[a],Pow[sz[b]]);
            lazy[b]=Mul(lazy[b],Inv[sz[a]]);
            root=Merge(Merge(b,a),c);
            fa[root]=0;
            lst[t]=i;
        }
        lazy[root]=Mul(lazy[root],bs);
        root=Merge(Newnode(i),root);
        printf("%d\n",sum[root]);
    }
    return 0;
}
