#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

void makeNext(char p[],int next[]) {
    int i=0,k=-1;
    next[0]=-1;
    while(i<strlen(p)-1) {
        while(k>=0&&p[i]!=p[k]) k=next[k];
        i++;k++;
        if(p[i]==p[k]) next[i]=next[k];
        else next[i]=k;
    }
}

//����Ƿ�װ�������õ�strlen()����������������n
int Find(char t[],char p[],int next[]) {
    int i=0,j=0;
    while(i<(int)strlen(p)&&j<strlen(t)) {//ע��strlen()���ص����޷�����
        if(i==-1||p[i]==t[j]) {//��ʱi��j�����Ե�++
            i++;
            j++;
        }
        else i=next[i];
    }
    if(i>=strlen(p))
        return j-strlen(p);
    else return 0;
}

int main() {
    char s1[100],s2[100];
    int Next[10000];
    while(scanf("%s%s",s1,s2)==2) {
        makeNext(s2,Next);
        cout<<Find(s1,s2,Next)<<endl;
    }
    return 0;
}
/*
aabcbabcaabcaababc
abcaababc
9
*/
