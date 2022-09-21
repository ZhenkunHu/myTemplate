#include<bits/stdc++.h>
using namespace std;
int Count=0;//不想传参数就定义全局变量

void check(int n) {
    int i=2;
    int flag=1;

    for(;i*i<=n;i++) {
        if(n%i==0) {
            flag=0;//判断是否是质数
            while(n%i==0) {//将该因数i除完//按照这个顺序i都是质因数
                Count++;
                n/=i;
            }
            break;//采用这种设计是为了提高效率，因为质因数总是小的质数
        }
    }

    if(!flag) check(n);//如果不是质数，继续调用
    else {
        if(n!=1)//如果是质数，并且不为1，则数量再加1（还能再除自己一次），否则不加，结束循环
            Count++;
        return;
    }
}

int main() {
    int n;
    while(cin>>n) {
        Count=0;
        check(n);
        cout<<Count<<endl;
    }
    return 0;
}

/*
https://blog.csdn.net/qq_39304201/article/details/80024594
*/
