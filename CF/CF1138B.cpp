#include<cstdio>
#include<cstring>
#include<vector>
using std::vector;
vector<int> v[4];
char s[5050],t[5050];
int Abs(int x)
{
    return x<0?-x:x;
}
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    scanf("%s",t+1);
    for(int i=1;i<=n;++i)
        v[s[i]-'0'+(t[i]-'0')*2].push_back(i);
    int a=v[0].size(),b=v[1].size(),c=v[2].size(),d=v[3].size(),h=n/2;
    for(int i=0;i<=d;++i)
    {
        if(d-i+c>h||i+b>h)
            continue;
        if(i<d-i)
        {
            if(b<d-2*i)
                continue;
            for(int j=0;j<i;++j)
                printf("%d ",v[3][j]);
            h-=i;
            for(int j=0;j<d-2*i;++j)
                printf("%d ",v[1][j]);
            h-=d-2*i;
            for(int j=0;j<c;++j)
                printf("%d ",v[2][j]);
            h-=c;
            for(int j=0;j<h;++j)
                printf("%d ",v[0][j]);
            return 0;
        }
        else
        {
            if(c<2*i-d)
                continue;
            c-=2*i-d;//c拿去补对面了
            for(int j=0;j<i;++j)
                printf("%d ",v[3][j]);
            h-=i;
            for(int j=0;j<c;++j)
                printf("%d ",v[2][j]);
            h-=c;
            for(int j=0;j<h;++j)
                printf("%d ",v[0][j]);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
