#include<cstdio>
int a[10100];
int main()
{
    int n,cnt=0,mx=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)
    {
        if(i>mx)
        {
            ++cnt;
            mx=0;
        }
        mx=mx>a[i]?mx:a[i];
    }
    printf("%d\n",cnt);
    return 0;
}