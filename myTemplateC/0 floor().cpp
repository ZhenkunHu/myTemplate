/*
输出所有形如aabb的4位完全平方数
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    for(int a=1;a<=9;a++)
    for(int b=0;b<=9;b++) {
        int n=a*1100+b*11;
        int m=floor(sqrt(n)+0.5);//如何判断一个数是完全平方数，0.5可能是避免浮点误差
        if(m*m==n) printf("%d\n",n);
    }
    return 0;
}
/*
floor : 不大于自变量的最大整数             2                2                  -3                  -3
ceil   :不小于自变量的最小整数              3                3                  -2                  -2
round:四舍五入到最邻近的整数             2                3                  -2                  -3

round(num,num_dight) 把num精确到num_dight位数
floor(),ceil() 需包含头文件<math.h>

C++中没有直接的round函数 需自己建立
double round(double r)
{
    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}
*/