#include<bits/stdc++.h>
using namespace std;

int main()
{
    char c[10]="12345";//char*תint

    int a;
    sscanf(c,"%d",&a);//��ȥ��ǰ��0;
    cout<<"sscanf:"<<a<<endl;

    cout<<atoi(c)*10<<endl;
    string s="12345";//stringתint
    cout<<atoi(s.c_str())*10<<endl;//char c[10]; strcpy(c,s.c_str());

    stringstream ss(s);
    ss>>a;
    cout<<a*10<<endl;

    a=12345;//intתstring
    sprintf(c,"%d",a);//itoa()�ǿ�ƽ̨�ģ���������
    cout<<c<<endl;

    string s=to_string(a);

    a=123;
    ss<<a;
    ss>>s;
    cout<<s<<endl;
    return 0;
}
/*
https://www.cnblogs.com/bluestorm/p/3168719.html
C++��char���Ϳ����Զ�ת����string���ͣ����������char�����ַ���ֱ�Ӹ�string���ͱ�����ֵ�����������ǲ��еģ�string���Ͳ�����ʽ�Ľ�string����ת����char���ͣ���Ҫת����������ʽ����c_str()����������ٸ����ӣ�
string s1;
const char *pc = "a character array";
s1 = pc; // ok

char *str = s1; // ����ʱ�����ʹ���

const char *str = s1.c_str(); // ok
*/
