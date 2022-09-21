#include<bits/stdc++.h>
using namespace std;

const int Max=105;

int main() {

    int d[Max][Max]={0};
    string s0,s1;

    while(cin>>s0>>s1) {
        int len0=s0.length(),len1=s1.length();
        for(int i=1;i<=len0;i++)
            for(int j=1;j<=len1;j++)
                if(s0[i-1]==s1[j-1])//不同种类的状态转移方程 d[i][j]=s0[i-1]==s1[j-1]? d[i-1][j-1]:max(d[i-1][j],d[i][j-1]);
                    d[i][j]=d[i-1][j-1]+1;
                else d[i][j]=max(d[i-1][j],d[i][j-1]);//全局最优解包含局部最优解
        cout<<d[len0][len1]<<endl;
    }

    return 0;
}
/*
https://blog.csdn.net/hrn1216/article/details/51534607
*/
