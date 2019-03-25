#include<cstdio>
#include<cstring>
char s[105];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        int l=n+1,r=0;
        for(int i=1;i<=n;++i)
            if(s[i]=='>')
            {
                l=i;
                break;
            }
        for(int i=n;i>=1;--i)
            if(s[i]=='<')
            {
                r=i;
                break;
            }
        printf("%d\n",l-1<n-r?l-1:n-r);
    }
    return 0;
}