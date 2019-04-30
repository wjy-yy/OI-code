#include<cstdio>
#include<cstring>
#define p 998244353
#define inv 499122177ll
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
int read()
{
    int x=0;
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
int A[1<<17],B[1<<17],a[1<<17],b[1<<17],n,tot;
void init()
{
    for(int i=0;i<(1<<n);++i)
    {
        a[i]=A[i];
        b[i]=B[i];
    }
}
void Or(int *f)
{
    for(int bs=2;bs<=tot;bs<<=1)
    {
        int g=(bs>>1);
        for(int i=0;i<tot;i+=bs)
            for(int j=0;j<g;++j)
                f[i+j+g]=(f[i+j]+f[i+j+g])%p;
    }
}
void iOr(int *f)
{
    for(int bs=tot;bs>=2;bs>>=1)
    {
        int g=(bs>>1);
        for(int i=0;i<tot;i+=bs)
            for(int j=0;j<g;++j)
                f[i+j+g]=(f[i+j+g]+p-f[i+j])%p;
    }
}
void And(int *f)
{
    for(int bs=2;bs<=tot;bs<<=1)
    {
        int g=(bs>>1);
        for(int i=0;i<tot;i+=bs)
            for(int j=0;j<g;++j)
                f[i+j]=(f[i+j]+f[i+j+g])%p;
    }
}
void iAnd(int *f)
{
    for(int bs=tot;bs>=2;bs>>=1)
    {
        int g=(bs>>1);
        for(int i=0;i<tot;i+=bs)
            for(int j=0;j<g;++j)
                f[i+j]=(f[i+j]+p-f[i+j+g])%p;
    }
}
void Xor(int *f)
{
    for(int bs=2;bs<=tot;bs<<=1)
    {
        int g=(bs>>1);
        for(int i=0;i<tot;i+=bs)
            for(int j=0;j<g;++j)
            {
                int t0=(f[i+j]+f[i+j+g])%p,t1=(f[i+j]+p-f[i+j+g])%p;
                f[i+j]=t0;
                f[i+j+g]=t1;
            }
    }
}
void iXor(int *f)
{
    for(int bs=tot;bs>=2;bs>>=1)
    {
        int g=(bs>>1);
        for(int i=0;i<tot;i+=bs)
            for(int j=0;j<g;++j)
            {
                int t0=inv*(f[i+j]+f[i+j+g])%p,t1=inv*(f[i+j]+p-f[i+j+g])%p;
                f[i+j]=t0;
                f[i+j+g]=t1;
            }
    }
}
int main()
{
    #ifdef wjyyy
        freopen("a.in","r",stdin);
    #endif
    n=read();
    tot=(1<<n);
    for(int i=0;i<tot;++i)
        A[i]=read();
    for(int i=0;i<tot;++i)
        B[i]=read();
    init();
    Or(a);
    Or(b);
    for(int i=0;i<tot;++i)
        a[i]=(long long)a[i]*b[i]%p;
    iOr(a);
    for(int i=0;i<tot;++i)
        printf("%d ",a[i]);
    puts("");
    init();
    And(a);
    And(b);
    for(int i=0;i<tot;++i)
        a[i]=(long long)a[i]*b[i]%p;
    iAnd(a);
    for(int i=0;i<tot;++i)
        printf("%d ",a[i]);
    puts("");
    init();
    Xor(a);
    Xor(b);
    for(int i=0;i<tot;++i)
        a[i]=(long long)a[i]*b[i]%p;
    iXor(a);
    for(int i=0;i<tot;++i)
        printf("%d ",a[i]);
    return 0;
}
