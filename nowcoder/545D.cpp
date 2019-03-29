#include<cstdio>
#include<cstring>
int Max(int x,int y){return x>y?x:y;}
int a[25][25],n;
struct node
{
    node *ch[2];
    node()
    {
        ch[0]=ch[1]=NULL;
    }
}*root[25];
void Insert(node *rt,int x,int t)//x 是 01 串 t 是第几位
{
    if(t==-1)
        return;
    int p=(x>>t)&1;
    if(!rt->ch[p])
        rt->ch[p]=new node();
    Insert(rt->ch[p],x,t-1);
}
void dfs1(int x,int y,int z)
{
    if(x+y==n+1)
    {
        if(!root[y])
            root[y]=new node();
        Insert(root[y],z,31);
        return;
    }
    if(x<n)
        dfs1(x+1,y,z^a[x+1][y]);
    if(y<n)
        dfs1(x,y+1,z^a[x][y+1]);
}
int match(node *rt,int x,int t)
{
    int p=(x>>t)&1;
    if(rt->ch[!p])
        return (1<<t)+match(rt->ch[!p],x,t-1);
    if(rt->ch[p])
        return match(rt->ch[p],x,t-1);
    return 0;
}
int ans=0;
void dfs2(int x,int y,int z)
{
    if(x+y==n+2)
    {
        int tmp=Max(match(root[y-1],z,31),match(root[y],z,31));
        ans=Max(ans,tmp);
        return;
    }
    dfs2(x-1,y,z^a[x-1][y]);
    dfs2(x,y-1,z^a[x][y-1]);
}
int main()
{
    int e;
    scanf("%d%d",&n,&e);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            scanf("%d",&a[i][j]);
    if(n==1)
    {
        printf("%d\n",e^a[1][1]);
        return 0;
    }
    dfs1(1,1,e^a[1][1]);
    dfs2(n,n,a[n][n]);
    printf("%d\n",ans);
    return 0;
}