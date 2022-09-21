#include<bits/stdc++.h>
using namespace std;

char x;
long long coe,value,opp=1;
double ans;

int main() {

    long long cur=0,sign=1;bool value_gotten=false;

    while(true) {
        char c=getchar();
        if(c>='a'&&c<='z') {
            x=c;
            if(cur==0&&!value_gotten) {
                coe+=opp*sign;
                value_gotten=false;
            }
            else {
                coe+=opp*sign*cur;
                cur=0;sign=1;value_gotten=false;
            }
        }
        else if(c=='-') {
            value+=-opp*sign*cur;
            cur=0;sign=-1;value_gotten=false;
        }
        else if(c=='+') {
            value+=-opp*sign*cur;
            cur=0;sign=1;value_gotten=false;
        }
        else if(c>='0'&&c<='9') {
            cur=cur*10+c-'0';
            value_gotten=true;
        }
        else if(c=='=') {
            value+=-opp*sign*cur;
            cur=0;sign=1;opp=-opp;value_gotten=false;
        }
        else {
            value+=-opp*sign*cur;
            break;
        }
    }
//cout<<value<<" "<<coe<<endl;
    ans=double(value)/coe;
    printf("%c=%.3f",x,ans==0?abs(ans):ans);
    return 0;
}
/*
P1022 ¼ÆËãÆ÷µÄ¸ÄÁ¼
*/
