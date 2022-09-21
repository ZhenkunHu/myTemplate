#include<bits/stdc++.h>
using namespace std;

int palindrome(const char *str, int mid) {
    int left = mid - 1, right = mid + 1;
    int len = strlen(str);
    while (str[mid] == str[right]) //考虑相邻两个字符相同的情况
        right++;
    while (left >= 0 && right < len && str[left] == str[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

int main() {
    char s[10005];
    while(cin>>s) {
        int Max=-1;
        for(int i=0;i<strlen(s);i++)
            Max=max(Max,palindrome(s,i));
        cout<<Max<<endl;
    }
    return 0;
}
/*
https://www.cnblogs.com/xiuyangleiasp/p/5070991.html
ACMCLUB
CSBIJI
SUNNY
3
3
2
*/
