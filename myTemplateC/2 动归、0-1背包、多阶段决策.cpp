#include<bits/stdc++.h>
using namespace std;

int knapsack(int N, int W, vector<int>& wt, vector<int>& val) {
    // base case �ѳ�ʼ��
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if (w - wt[i-1] < 0) {
                // ���������ֻ��ѡ��װ�뱳��
                dp[i][w] = dp[i - 1][w];
            } else {
                // װ����߲�װ�뱳��������
                dp[i][w] = max(dp[i - 1][w],dp[i - 1][w - wt[i-1]] + val[i-1]); //��0��ʼ�洢������val[i-1]�����i����Ʒ�ļ�ֵ
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
        wt.push_back(tem);//vector�������飬����scanf("%d",&wt[i])��ֻ��������[]�����
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
https://zhuanlan.zhihu.com/p/30959069 //0-1���� ����
https://www.cnblogs.com/labuladong/p/13927944.html //0-1���� ʵ��
������
5 10
1 2 3 4 5
5 4 3 2 1
14

blog.csdn.net/W_ang_/article/details/81844521 //�κ�����
��̬�滮�������Խ�����Ž����⣬�����Խ�����������⡣��������ֱ��������Ž�����⣬����ת��Ϊ���������������⡣

0-1���������У������˱����������������ʵ�ϣ�����ͨ��0-1���������κ�������ͨ��0-1������
�������������ֵһ��ʱ����������������������ֵһ��ʱ������ֵ��
�ڱ����У�����������������غ�ʱ���������أ�����N�����и�ѡ�����ɸ���ʹ���������ܺ��ڲ�����sum/2ʱ�����ֵ��
�Ƿ���Ǵ���?
��Ȼ���ǡ�����㷨ֻ��֤�˽�N���˵����ؾ������֣�����û�б�֤�������֡�
*/
/* 0-1 ��������
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

        for(int i=0;i<n;i++) {//��ǰi������ѡj���ˣ����ز�����k�����ֵ//��ά����������
            for(int j=0;j<=(n+1)/2;j++) {//ͬʱ��֤��������
                for(int k=m;k>=w[i];k--) {//�������ƽ������ʱ���㷨
                    dp[j+1][k]=max(dp[j+1][k],dp[j][k-w[i]]+w[i]);//0-1������״̬ת�Ʒ���
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
