#include<bits/stdc++.h>
using namespace std;

int knapsack(int N, int W, vector<int>& wt, vector<int>& val) {
    // base case 已初始化
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if (w - wt[i-1] < 0) {
                // 这种情况下只能选择不装入背包
                dp[i][w] = dp[i - 1][w];
            } else {
                // 装入或者不装入背包，择优
                dp[i][w] = max(dp[i - 1][w],dp[i - 1][w - wt[i-1]] + val[i-1]); //从0开始存储，所以val[i-1]代表第i个物品的价值
            }
        }
    }

    return dp[N][W];
}

int main() {

    int n,w;
    vector<int> wt;
    vector<int> val;
    scanf("%d%d",&n,&w);
    for(int i=0;i<n;i++) {
        int tem;
        scanf("%d",&tem);
        wt.push_back(tem);//vector不是数组，不能scanf("%d",&wt[i])，只是重载了[]运算符
    }

    for(int i=0;i<n;i++) {
        int tem;
        scanf("%d",&tem);
        val.push_back(tem);
    }

    cout<<knapsack(n,w,wt,val);

	return 0;
}
/*
https://zhuanlan.zhihu.com/p/30959069 //0-1背包 理论
https://www.cnblogs.com/labuladong/p/13927944.html //0-1背包 实现
样例：
5 10
1 2 3 4 5
5 4 3 2 1
14

blog.csdn.net/W_ang_/article/details/81844521 //拔河问题
动态规划不仅可以解决最优解问题，还可以解决存在性问题。对于难以直接求出最优解的问题，可以转换为存在性问题进行求解。

0-1背包问题中，限制了背包的最大重量。事实上，可以通过0-1背包限制任何条件。通过0-1背包，
可以求解在最大价值一定时的最大重量，可以求解最大价值一定时的最大价值。
在本题中，可以在限制最大体重和时求出最大体重，即在N个人中各选出若干个人使得其体重总和在不超过sum/2时的最大值，
是否就是答案呢?
显然不是。这个算法只保证了将N个人的体重尽量均分，但是没有保证人数均分。
*/
/* 0-1 背包错误
	int n;
	while(cin>>n) {
		int m=0;
		int sum=0;
        for(int i=0;i<n;i++) {
            cin>>w[i];
            sum=sum+w[i];
        }
        m=sum/2;
        memset(dp,0,sizeof(dp));

        for(int i=0;i<n;i++) {//从前i个人中选j个人，体重不超过k的最大值//降维，滑动数组
            for(int j=0;j<=(n+1)/2;j++) {//同时保证人数均分
                for(int k=m;k>=w[i];k--) {//类比用天平加砝码时的算法
                    dp[j+1][k]=max(dp[j+1][k],dp[j][k-w[i]]+w[i]);//0-1背包的状态转移方程
                }
            }
        }

        if(n%2==0)
            cout<<dp[n/2][m]<<" "<<sum-dp[n/2][m];
        if(n%2==1) {
            if(dp[(n+1)/2][m]>dp[(n/2)][m])
                cout<<dp[(n+1)/2][m]<<" "<<sum-dp[(n+1)/2][m];
            else
                cout<< dp[(n/2)][m]<<" "<<sum-dp[(n/2)][m];
        }
        cout<<endl;
	}
*/
