#include<iostream>
using namespace std;

int digitSquareSum(long long n) {
    long long sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(long long n) {
    long long slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
}

int main() {
    int T;
    long long a[150010];
    //a[0]=1;a[1]=7;
    int index=0;
    for(long long i=1;;i++) {
        if(isHappy(i)) {a[index++]=i;}
        if(index==150001) {break;}
    }
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        printf("%lld\n",a[n-1]);
    }
    return 0;
}

/*
https://blog.csdn.net/y492235584/article/details/82634939
*/
