/*
UVa 400
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxcol=60;
const int maxn=100+5;
string filenames[maxn];

void print(const string& s,int len,char extra) {//��ʽ�����������print()
	cout<<s;
	for(int i=0;i<len-s.length();i++)
	  cout<<extra;
}

int main() {
	int n;
	while(cin>>n) {
		int M=0;
		for(int i=0;i<n;i++) {
			cin>>filenames[i];
			M=max(M,(int)filenames[i].length());//ֱ��max()�����ñȽϡ��ɶ���
		}
		int cols=(maxcol-M)/(M+2)+1,rows=(n-1)/cols+1;//�����һ���������Ϊ�ϲ��������Ѷ�
		print("",60,'-');
		cout<<"\n";
		sort(filenames,filenames+n);
		for(int r=0;r<rows;r++) {
			for(int c=0;c<cols;c++) {
				int idx=c*rows+r;//��ά��һά��ת��
				if(idx<n) print(filenames[idx],c==cols? M:M+2,' ');
			}
			cout<<"\n";
	    }
	}
	return 0;
}
