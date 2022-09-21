#include<bits/stdc++.h>
using namespace std;

void reversestring(char a[], int x, int y) {
	for(x = x - 1;x >= y;x--,y++) {//索引与个数的关系//这个算法是核心
		char tmp = a[x];
		a[x] = a[y];
		a[y] = tmp;
	}
}

void reverse(char a[], int num) {
	int x = 0,y = 0;
	num += 1;//因为'\0'也要判断
	while (num--) {//要判断num次，这里也可以用for(;;)
		if (a[x] == ' ' || a[x] == '\0') {
			reversestring(a, x, y);
			y = x + 1;
			x=y;//减少一次运算
		}
		else x++;
	}
	reversestring(a, strlen(a), 0);//对整个字符串进行反转
}

int main() {
    char a[1005];
	while(gets(a)) {
        reverse(a, strlen(a));
        printf("%s\n", a);
	}
    return 0;
}
/*
int a,b;
	cin>>a>>b;
	string s=to_string(a*b);
	cout<<s<<endl;
	for(int i=s.size()-1;i>0;i--)
        if(s[i]=='0') s.pop_back();
    reverse(s.begin(),s.end());//注意反转函数
    cout<<s<<endl;
*/
/*
字符串反转
I love c++.
c++. love I
*/
