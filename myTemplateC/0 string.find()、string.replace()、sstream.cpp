#include<iostream>
#include<cstring>

using namespace std;

int main(void){
	string input;
	string find_word;
	string replace_word;
	while(getline(cin,input)){//gets()��getline()���ȡ'\n',������getchar()���˵�
		input = " " + input + " ";
		getline(cin,find_word);
		getline(cin,replace_word);
		find_word = " " + find_word + " ";
		replace_word = " " + replace_word + " ";
		int pos = 0;
		while ((pos = input.find(find_word)) != string::npos){//string::nposҲ����-1
    	    input.replace(pos,find_word.size(),replace_word);//replace()�Ĳ��������ǵ�������Ҳ�������±�
    	}
    	input.erase(0,1);//��0��ʼ��ɾ��һ��Ԫ��
    	input.erase(input.size(),1);
    	cout << input << endl;
    }
}
/*
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while(getline(cin,s)) {
        stringstream ss(s);
        string s1,s2;
        cin>>s1>>s2;
        string per;
        stringstream ss2;
        while(ss>>per) {
            if(per==s1) ss2<<s2<<" ";
            else ss2<<per<<" ";
        }
        getline(ss2,s);//cin��ss2������
        s.pop_back();//���erase()
        cout<<s<<endl;
    }
    return 0;
}
*/
