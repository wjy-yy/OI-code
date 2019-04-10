#include<cmath>
#include<cstdio>
#include<cstring>
#define db double
const db pi=acos(-1);
struct cpl
{
    db x,y;
    cpl(db x,db y)
    {
        this->x=x;
        this->y=y;
    }
    cpl(){}
    friend cpl operator +(cpl a,cpl b)
    {return cpl(a.x+b.x,a.y+b.y);}
    friend cpl operator -(cpl a,cpl b)
    {return cpl(a.x-b.x,a.y-b.y);}
    friend cpl operator *(cpl a,cpl b)
    {return cpl(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
}a[1<<21],b[1<<21],omg[2][1<<21];
int tot=1,len;
int pos[1<<21];
void FFT(cpl *f,int flag)
{
    for(int i=0;i<tot;++i)
        if(pos[i]>i)
        {
            cpl t=f[pos[i]];
            f[pos[i]]=f[i];
            f[i]=t;
        }
    for(int bs=2;bs<=tot;bs<<=1)
        for(int j=0;j<tot;j+=bs)
        {
            int g=bs>>1;
            for(int k=0;k<g;++k)
            {
                cpl t1=f[j+k],t2=omg[flag][tot/bs*k]*f[j+k+g];
                f[j+k]=t1+t2;
                f[j+k+g]=t1-t2;
            }
        }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(tot<=n+m)
    {
        tot<<=1;
        ++len;
    }
    for(int i=0;i<tot;++i)
    {
        pos[i]=(pos[i>>1]>>1)|((i&1)<<(len-1));
        db d=2*pi*i/tot;
        omg[0][i]=cpl(cos(d),sin(d));
        omg[1][i]=cpl(omg[0][i].x,-omg[0][i].y);
    }
    for(int i=0;i<=n;++i)
        scanf("%lf",&a[i].x);
    for(int i=0;i<=m;++i)
        scanf("%lf",&b[i].x);
    FFT(a,0);
    FFT(b,0);
    for(int i=0;i<tot;++i)
        a[i]=a[i]*b[i];
    FFT(a,1);
    for(int i=0;i<=n+m;++i)
        printf("%d ",int(a[i].x/tot+.5));
    return 0;
}