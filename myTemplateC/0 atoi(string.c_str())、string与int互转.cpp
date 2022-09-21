#include<bits/stdc++.h>
using namespace std;

int main()
{
    char c[10]="12345";//char*转int

    int a;
    sscanf(c,"%d",&a);//会去掉前导0;
    cout<<"sscanf:"<<a<<endl;

    cout<<atoi(c)*10<<endl;
    string s="12345";//string转int
    cout<<atoi(s.c_str())*10<<endl;//char c[10]; strcpy(c,s.c_str());

    stringstream ss(s);
    ss>>a;
    cout<<a*10<<endl;

    a=12345;//int转string
    sprintf(c,"%d",a);//itoa()是跨平台的，尽量不用
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
C++中char类型可以自动转换成string类型，即你可以用char类型字符串直接给string类型变量赋值。但反过来是不行的，string类型不能隐式的将string类型转换成char类型，想要转换，必须显式调用c_str()函数。给你举个例子：
string s1;
const char *pc = "a character array";
s1 = pc; // ok

char *str = s1; // 编译时刻类型错误

const char *str = s1.c_str(); // ok
*/
