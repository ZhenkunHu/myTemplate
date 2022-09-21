#include<bits/stdc++.h>
using namespace std;

struct date {
    int a,b,c;
}a[185];

void da_push(int k,int A,int B,int C) { //自己写个push
    a[k].a=A;
    a[k].b=B;
    a[k].c=C;
}

bool cmp(date a,date b) {
    return a.a>b.a;
}

int main() {
    int n;
    int Case=1;
    while(scanf("%d",&n)==1&&n) {
        int num=0;
        for(int i=0;i<n;i++) {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            da_push(num++,x,y,z);
            da_push(num++,x,z,y);
            da_push(num++,y,x,z);
            da_push(num++,y,z,x);
            da_push(num++,z,x,y);
            da_push(num++,z,y,x);
        }

        int dp[185];//状态
        n=n*6;
        sort(a,a+n,cmp);

        for(int i=0;i<n;i++) //初始化的值，是状态转移方程的else
            dp[i]=a[i].c;

        int ans=0;
        for(int i=0;i<n;i++) {
            //写法1，比较简洁
            //int max_c=0;
            for(int j=i-1;j>=0;j--)//找第i块砖下面的最大状态
                if(a[j].a>a[i].a&&a[j].b>a[i].b&&dp[i]<dp[j]+a[i].c) //if(judge(a[j],a[i]) && dp[i] < dp[j] + 1)  dp[i] = dp[j] + 1; //矩形嵌套问题
                    dp[i]=dp[j]+a[i].c;

            //dp[i]+=max_c;//状态转移方程的数学模型和实现模型（逻辑与物理）
            if(ans<dp[i]) ans=dp[i];//有时需要更新最大值，有时能找到最大值，不需要Max或ans
            /*
            //写法2，反应本质
            int max_c=0;
            for(int j=i-1;j>=0;j--)//找第i块砖下面的最大状态
                if(a[j].a>a[i].a&&a[j].b>a[i].b&&dp[j]>max_c) //if(judge(a[j],a[i]) && dp[i] < dp[j] + 1)  dp[i] = dp[j] + 1; //矩形嵌套问题
                    max_c=dp[j];

            dp[i]+=max_c;//状态转移方程的数学模型和实现模型（逻辑与物理）
            if(ans<dp[i]) ans=dp[i];//有时需要更新最大值，有时能找到最大值，不需要Max或ans
            */
        }
        cout<<"Case "<<Case++<<": maximum height = "<<ans<<endl;
    }
    return 0;
}

/*
https://blog.csdn.net/Patrickpwq/article/details/79845987
https://www.jianshu.com/p/9c4fc496e287 //矩形嵌套问题
*/
