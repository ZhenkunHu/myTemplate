#include<bits/stdc++.h>
using namespace std;

int n,A[50],isp[50],vis[50];

int is_prime(int n)
{
	if(n<=1) return 0;
	int m=floor(sqrt(n)+0.5);
	for(int i=2;i<=m;i++)
	    if(n%i==0) return 0;
	return 1;
}

//素数环
void dfs(int cur) {
    if(cur==n&&isp[A[0]+A[n-1]]) {//递归边界。别忘了测试第一个数和最后一个数
        for(int i=0;i<n;i++) printf("%d ",A[i]);//打印方案
        printf("\n");
    }
    else
        for(int i=2;i<=n;i++) {//尝试放置每个数i
            if(!vis[i]&&isp[i+A[cur-1]]) {//如果i没有用过，并且与前一个数之和为素数
                A[cur]=i;
                vis[i]=i;//设置使用标志
                dfs(cur+1);
                vis[i]=0;//清除标志
            }
        }
}

int main() {
    scanf("%d",&n);
    for(int i=2;i<=n*2;i++) isp[i]=is_prime(i);//生成素数表，加速后续判断
    memset(vis,0,sizeof(vis));
    A[0]=1;//输出时从整数1逆时针排序//因为从A[0]开始，环又是从1开始
    dfs(1);
    return 0;
}
