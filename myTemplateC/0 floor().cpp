/*
�����������aabb��4λ��ȫƽ����
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    for(int a=1;a<=9;a++)
    for(int b=0;b<=9;b++) {
        int n=a*1100+b*11;
        int m=floor(sqrt(n)+0.5);//����ж�һ��������ȫƽ������0.5�����Ǳ��⸡�����
        if(m*m==n) printf("%d\n",n);
    }
    return 0;
}
/*
floor : �������Ա������������             2                2                  -3                  -3
ceil   :��С���Ա�������С����              3                3                  -2                  -2
round:�������뵽���ڽ�������             2                3                  -2                  -3

round(num,num_dight) ��num��ȷ��num_dightλ��
floor(),ceil() �����ͷ�ļ�<math.h>

C++��û��ֱ�ӵ�round���� ���Լ�����
double round(double r)
{
    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}
*/