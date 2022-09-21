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

void print(const string& s,int len,char extra) {//格式控制输出函数print()
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
			M=max(M,(int)filenames[i].length());//直接max()，不用比较。可读性
		}
		int cols=(maxcol-M)/(M+2)+1,rows=(n-1)/cols+1;//这个减一，博大精深。因为合并，所以难懂
		print("",60,'-');
		cout<<"\n";
		sort(filenames,filenames+n);
		for(int r=0;r<rows;r++) {
			for(int c=0;c<cols;c++) {
				int idx=c*rows+r;//二维与一维的转化
				if(idx<n) print(filenames[idx],c==cols? M:M+2,' ');
			}
			cout<<"\n";
	    }
	}
	return 0;
}
