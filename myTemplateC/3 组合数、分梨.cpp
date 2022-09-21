#include<bits/stdc++.h>
using namespace std;

int c(int m,int n) {
    if(m==0||n==1) return 1;
    if(m>=n) return c(m-n,n)+c(m,n-1); //当梨大于盘子数 则有两种分法，即每个盘子一个都不为空和只有一个盘子为空.
    return c(m,m); //当梨小于盘子数，则剩余的盘子全部没用，去掉。
}

int main() {
    int n;
    while(cin>>n) {
        int M,N;
        while(n--) {
            cin>>M>>N;
            cout<<c(M,N)<<endl;
        }
    }
    return 0;
}

/*
https://blog.csdn.net/gakki_wpt/article/details/75735946
*/
