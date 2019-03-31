#include<cstdio>
#include<cmath>
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int up=sqrt(n);
        if(up*up==n)
        {
            puts("infty");
            continue;
        }
        if(n%4)
            puts("0 0");
        else
        {
            n/=4;
            up=sqrt(n);
            int cnt=0,ans=0;
            for(int i=1;i<=up;++i)
                if(n%i==0&&n/i+i>up)
                {
                    ++cnt;
                    ans=(ans+(long long)n*(n/i+i)%1000000007)%1000000007;
                }
            printf("%d %d\n",cnt,ans);
        }
    }
    return 0;
}