/*
UVA1592
自顶向下，逐步求精。一点一点的攻破
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<sstream>
using namespace std;
typedef pair<int,int> PII;//这个结构体很强。二元组
const int maxr = 10000 + 5;
const int maxc = 10 + 5;
int m, n, db[maxr][maxc], cnt;

map<string, int> id;//转化思想。预处理。把每个字符串变成数字，这样每个单元格都变成了数字。
int ID(const string& s)
{
    if(!id.count(s)) {
    id[s] = ++cnt;
    }
    return id[s];
}

void find() {
  for(int c1 = 0; c1 < m; c1++)
    for(int c2 = c1+1; c2 < m; c2++) {
      map<PII, int> d;
      for(int i = 0; i < n; i++) {
        PII p = make_pair(db[i][c1], db[i][c2]);//把两列看成一个整体。二元组。make_pair()
        if(d.count(p)) {//整体思想。理解p
          printf("NO\n");
          printf("%d %d\n", d[p]+1, i+1);//当前行，下一行 //因为从0开的
          printf("%d %d\n", c1+1, c2+1);//当前列，下一列
          return;
        }
        d[p] = i;
      }
    }
  printf("YES\n");//如果没找到，输出YES。
}

int main() {
  string s;
  while(getline(cin, s)) {
    stringstream ss(s);
    if(!(ss >> n >> m)) break;//跳出循环
    cnt = 0;
    id.clear();//id.clear()
    for(int i = 0; i < n; i++) {
      getline(cin, s);//或者cin>>s;
      int lastpos = -1;//初始化用int
      for(int j = 0; j < m; j++) {
        int p = s.find(',', lastpos+1);//find()的使用find ',' form (lastpos+1)//用英语的观点理解函数的参数顺序
        if(p == string::npos) p = s.length();//找到最后的情况
        db[i][j] = ID(s.substr(lastpos+1, p - lastpos - 1));//substr()的使用，类似java
        lastpos = p;//重新赋值。
      }
    }
    find();
  }
  return 0;
}
