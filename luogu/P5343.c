#include "stdio.h"
#include "string.h"
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
int m[100][105][105],mcnt=0;
int mx[100],my[100];
int mmul(int a,int b)
{
    ++mcnt;
    mx[mcnt]=mx[a];
    my[mcnt]=my[b];
    for(int i=1;i<=mx[mcnt];++i)
        for(int j=1;j<=my[mcnt];++j)
            for(int k=1;k<=my[a];++k)
                m[mcnt][i][j]=Plus(m[mcnt][i][j],Mul(m[a][i][k],m[b][k][j]));
    return mcnt;
}
int used[105];
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
    int f=++mcnt;
    mx[f]=101;
    my[f]=101;
    int ans=++mcnt;
    mx[ans]=101;
    my[ans]=1;
    for(int i=1;i<=B;++i)
    {
        u=read();
        if(used[u]==1)
        {
            used[u]=0;
            m[f][1][u]=1;
        }
    }
    for(int i=2;i<=101;++i)
        m[f][i][i-1]=1;
    m[ans][1][1]=1;
    while(n)
    {
        if(n&1)
            ans=mmul(f,ans);
        f=mmul(f,f);
        n>>=1;
    }
    printf("%d\n",m[ans][1][1]);
    return 0;
}
