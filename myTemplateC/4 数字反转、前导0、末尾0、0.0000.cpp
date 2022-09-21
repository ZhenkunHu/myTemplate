#include<bits/stdc++.h>
using namespace std;

void reverse_int(string num) {

    bool flag=1;
    for(int i=num.size()-1;i>=0;i--) {
        if(num[i]=='0'&&flag) {continue;}
        else {flag=0;}
        if(flag==0) printf("%c",num[i]);
    }
    if(flag==true) printf("0");
}

void reverse_int1(string num) {//小数复杂，要注意前导0、末尾0，0.0000

    bool flag=1;
    int per=0;//不输出小数的后导0
    for(int i=0;i<num.size();i++) {
        if(num[i]=='0'&&flag) {continue;}
        else {flag=0;per=i;break;}
    }
    if(flag==true) printf("0");//0.0000四个0时要输出一个0

    flag=1;
    for(int i=num.size()-1;i>=per;i--) {
        if(num[i]=='0'&&flag) {continue;}
        else {flag=0;}
        if(flag==0) printf("%c",num[i]);
    }

}

int main() {
    string s;
    while(cin>>s) {
        int per=s.find(".");
        int per1=s.find("/");
        int per2=s.find("%");
        if(per!=string::npos) {
            reverse_int(s.substr(0,per));
            printf(".");
            reverse_int1(s.substr(per+1));
            printf("\n");
        }
        else if(per1!=string::npos) {
            reverse_int(s.substr(0,per1));
            printf("/");
            reverse_int(s.substr(per1+1));
            printf("\n");
        }
        else if(per2!=string::npos) {
            reverse_int(s.substr(0,per2));
            printf("%%");
            //reverse_int(s.substr(per2+1));
            printf("\n");
        }
        else {
            reverse_int(s);
            printf("\n");
        }
    }
    return 0;
}
/*
P1553 数字反转（升级版）
前导零、末尾零、0.0000
*/
