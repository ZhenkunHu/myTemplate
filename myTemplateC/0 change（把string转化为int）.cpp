/*
change()把string转化为int
*/
#include<bits/stdc++.h>
using namespace std;
int change (string in){
    char *p;
    int i=0,n=0,result=0;
    p=&in[0];
    while(*p!='\0'){
        n++;
        p++;
    }
    //cout<<"in "<<in<<endl;
    for(i=0;i<n;i++){
        result = result + ((in[n-i-1]-'0') * pow(10,i));
    }
    return result;
}
int main(){
    const int max = 10000;
    char t[max],*p;
    string in;
    int result=0,a,b,c;
    while(scanf("%s",t)!=EOF){
        a=0,b=0,c=0;
        char mark;
        p=t;
        while(*p>='0'&&*p<='9'){
            in = in + *p;
            p++;
        }
        a = change(in);
        in.clear();
        mark=*p;
        p++;
        while(*p>='0'&&*p<='9'){
            in = in + *p;
            p++;
        }
        b = change(in);
        in.clear();
        p++;
        while(*p>='0'&&*p<='9'){
            in = in + *p;
            p++;
        }
        c = change(in);
        in.clear();
        if(mark=='+'){
            if(a+b==c){
                result++;
            }
        }else{
            if(a-b==c){
                result++;
            }
        }
    }
    cout<<result<<endl;
    return 0;
}

