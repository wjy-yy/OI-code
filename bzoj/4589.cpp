#include<cstdio>
#include<cstring>
#define p 1000000007
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
int read()
{
    int x=0;
    char ch=gc();
    while(ch<'0'||ch>'9')
    {
        if(ch==EOF)
            return -1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+(ch&15);
        ch=gc();
    }
    return x;
}
int f[1<<16];
int pri[10000],cnt;
bool is[51000];
int qpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1)
            ans=(long long)ans*x%p;
        x=(long long)x*x%p;
        y>>=1;
    }
    return ans;
}
int main()
{
    #ifdef wjyyy
        freopen("a.in","r",stdin);
    #endif 
    is[0]=is[1]=1;
    for(int i=2;i<=50500;++i)
    {
        if(!is[i])
            pri[++cnt]=i;
        for(int j=1;j<=cnt&&i*pri[j]<=50500;++j)
        {
            is[i*pri[j]]=1;
            if(i%pri[j]==0)
                break;
        }
    }
    int n=read(),m;
    while(~n)
    {
        memset(f,0,sizeof(f));
        m=read();
        int tot=1,N=0;
        while(tot<=m)
            tot<<=1,++N;
        for(int i=1;pri[i]<=m;++i)
            f[pri[i]]=1;
        for(int bs=2;bs<=tot;bs<<=1)
        {
            int g=bs>>1;
            for(int i=0;i<tot;i+=bs)
                for(int j=0;j<g;++j)
                {
                    int t0=(f[i+j]+f[i+j+g])%p,t1=(f[i+j]+p-f[i+j+g])%p;
                    f[i+j]=t0;
                    f[i+j+g]=t1;
                }
        }
        for(int i=0;i<tot;++i)
            f[i]=qpow(f[i],n);
        for(int bs=tot;bs>=2;bs>>=1)
        {
            int g=bs>>1;
            for(int i=0;i<tot;i+=bs)
                for(int j=0;j<g;++j)
                {
                    int t0=(f[i+j]+f[i+j+g])%p,t1=(f[i+j]+p-f[i+j+g])%p;
                    f[i+j]=t0;
                    f[i+j+g]=t1;
                }
        }
        printf("%lld\n",(long long)f[0]*qpow(500000004,N)%p);
        n=read();
    }
    return 0;
}