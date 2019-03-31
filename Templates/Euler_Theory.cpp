#include<cstdio>
#include<cstring>
int Phi(int x)
{
    int ans=x;
    for(int i=2;i*i<=x;++i)
        if(x%i==0)
        {
            ans=ans/i*(i-1);
            while(x%i==0)
                x/=i;
        }
    if(x>1)
        ans=ans/x*(x-1);
    return ans;
}
int gcd(int x,int y)
{
    while(y)
    {
        int t=x%y;
        x=y;
        y=t;
    }
    return x;
}
int qpow(int x,int y,int p)
{
    int ans=1;
    while(y)
    {
        if(y&1)
            ans=1ll*ans*x%p;
        x=1ll*x*x%p;
        y>>=1;
    }
    return ans;
}
char s[20001000];
int main()
{
    int a,b,p,flag=0;
    scanf("%d%d",&a,&p);
    scanf("%s",s+1);
    if(gcd(a,p)==1)
        flag=1;
    int f=Phi(p);
    for(int i=1;s[i]!='\0';++i)
    {
        b=b*10+s[i]-'0';
        if(b>=f)
        {
            flag|=2;
            b%=f;
        }
    }
    if(flag==3)
        b+=f;
    printf("%d\n",qpow(a,b,p));
    return 0;
}