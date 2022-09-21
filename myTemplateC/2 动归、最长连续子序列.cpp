#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	string str1, str2;
	while (cin>>str1>>str2) {
		if (str1.size()>str2.size())
			swap(str1, str2);
		int len1=str1.size(),len2=str2.size(),i,j,start=0,max = 0;
		vector<vector<int>> dp(len1+1,vector<int> (len2+1,0));
		for (i=1;i<=len1;i++)
			for(j=1;j<=len2;j++) {
				if(str1[i-1]==str2[j-1])
					dp[i][j]=dp[i-1][j-1]+1;//dp[i][j]=str1[i-1]==str2[j-1]? dp[i-1][j-1]+1:0;
				if (dp[i][j]>max) {
					max=dp[i][j];
					start=i-max;//减法是时间的减法，可以用时间的开始时刻代表这个时间
				}
			}
		cout<<str1.substr(start,max)<<endl;
    }
	return 0;
}
/*
https://blog.csdn.net/thecentry/article/details/82875734
状态（dp[][])、状态转移方程（依据最优子结构设计）
算法是过程，手动模拟进行理解这个过程

*/
