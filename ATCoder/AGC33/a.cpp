#include<cstdio>
#include<cstring>
char s[1010][1010];
int qx[1001000],qy[1001000],d[1001000],l=0,r=0;
int X[4]={-1,0,0,1};
int Y[4]={0,-1,1,0};
int main()
{
  	int n,m;
  	scanf("%d%d",&n,&m);
  	for(int i=1;i<=n;++i)
      	scanf("%s",s[i]+1);
  	for(int i=1;i<=n;++i)
      	for(int j=1;j<=m;++j)
          	if(s[i][j]=='#')
            {
            	qx[++r]=i;
              	qy[r]=j;
              	d[r]=0;
            }
 	while(l<r)
    {
      	int x=qx[++l];
      	int y=qy[l];
      	for(int i=0;i<4;++i)
          	if(s[x+X[i]][y+Y[i]]=='.'&&x+X[i]>0&&x+X[i]<=n&&y+Y[i]>0&&y+Y[i]<=m)
            {
              	qx[++r]=x+X[i];
              	qy[r]=y+Y[i];
              	s[qx[r]][qy[r]]='#';
              	d[r]=d[l]+1;
            }
    }
  	printf("%d\n",d[r]);
  	return 0;
}