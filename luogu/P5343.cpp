#include<cstdio>
#include<cstring>
#define p 1000000007
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
long long read()
{
    long long x=0;
    char ch=gc();
    while(ch<'0'||ch>'9')
        ch=gc();
    while(ch>='0'&&ch<='9')
    {
        x=x*10+(ch&15);
        ch=gc();
    }
    return x;
}
int Plus(int x,int y){return x+y>=p?x+y-p:x+y;}
int Mul(int x,int y){return 1ll*x*y%p;}
struct matrix
{
    int a[105][105];
    int x,y;
    matrix(int x,int y)
    {
        this->x=x;
        this->y=y;
        memset(a,0,sizeof(a));
    }
    matrix(){}
    friend matrix operator *(matrix a,matrix b)
    {
        matrix c(a.x,b.y);
        for(int i=1;i<=c.x;++i)
            for(int j=1;j<=c.y;++j)
                for(int k=1;k<=a.y;++k)
                    c.a[i][j]=Plus(c.a[i][j],Mul(a.a[i][k],b.a[k][j]));
        return c;
    }
};
bool used[105];
int main()
{
    #ifdef wjyyy
        freopen("a.in","r",stdin);
    #endif
    long long n=read();
    int A=read(),u;
    for(int i=1;i<=A;++i)
    {
        u=read();
        used[u]=1;
    }
    int B=read();
    matrix a(101,101),ans(101,1);
    for(int i=1;i<=B;++i)
    {
        u=read();
        if(used[u]==1)
        {
            used[u]=0;
            a.a[1][u]=1;
        }
    }
    for(int i=2;i<=101;++i)
        a.a[i][i-1]=1;
    ans.a[1][1]=1;
    while(n)
    {
        if(n&1)
            ans=a*ans;
        a=a*a;
        n>>=1;
    }
    printf("%d\n",ans.a[1][1]);
    return 0;
}
