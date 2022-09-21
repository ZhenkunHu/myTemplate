#include<stdio.h>
int main() {
    int a,b,c,i,z,s;
    scanf("%d%d%d",&a,&b,&c);
    s=a%b;//先取一次模
    printf("%d.",a/b);//输出整数部分
    for(i=1;i<=c;i++)//输出小数部分
        if(i==c) {
            s*=10;
            z=s/b;//最后一位，对比下面的else部分

            if(s%b*10/b>=5)//s%b*10/b为最后一位的下一位，模仿竖式运算，针对小数的，判断四舍五入
            printf("%d",z+1);//注意特殊的%10，/10也是模仿竖式运算，但是比较特殊，针对整数的
            else printf("%d",z);
        }
        else {
            s*= 10;//乘10（因为这时才是一位整数） 输出 取模（让剩下的部分除b）
            printf("%d",s/b);
            s=s%b;
        }

    return 0;
}

/*
输出a/b，保留c位小数
模拟竖式计算
*/
