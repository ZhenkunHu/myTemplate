#include<bits/stdc++.h>
using namespace std;

void reversestring(char a[], int x, int y) {
	for(x = x - 1;x >= y;x--,y++) {//����������Ĺ�ϵ//����㷨�Ǻ���
		char tmp = a[x];
		a[x] = a[y];
		a[y] = tmp;
	}
}

void reverse(char a[], int num) {
	int x = 0,y = 0;
	num += 1;//��Ϊ'\0'ҲҪ�ж�
	while (num--) {//Ҫ�ж�num�Σ�����Ҳ������for(;;)
		if (a[x] == ' ' || a[x] == '\0') {
			reversestring(a, x, y);
			y = x + 1;
			x=y;//����һ������
		}
		else x++;
	}
	reversestring(a, strlen(a), 0);//�������ַ������з�ת
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
    reverse(s.begin(),s.end());//ע�ⷴת����
    cout<<s<<endl;
*/
/*
�ַ�����ת
I love c++.
c++. love I
*/
