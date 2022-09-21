// UVa10129 Play on Words
// Rujia Liu
// 题意：输入n个单词，是否可以排成一个序列，使得每个单词的第一个字母和上一个单词的最后一个字母相同
// 算法：把字母看作结点，单词看成有向边，则有解当且仅当图中有欧拉路径。注意要先判连通
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int maxn = 1000 + 5;

// 并查集（代码摘自《算法竞赛入门经典——训练指南》第三章），判断连通
int pa[256];
int findset(int x) { return pa[x] != x ? pa[x] = findset(pa[x]) : x; }

int used[256], deg[256]; // 是否出现过；度数

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n;
    char word[maxn];

    scanf("%d", &n);
    memset(used, 0, sizeof(used));
    memset(deg, 0, sizeof(deg));
    for(int ch = 'a'; ch <= 'z'; ch++) pa[ch] = ch; // 初始化并查集
    int cc = 26; // 连通块个数

    for(int i = 0; i < n; i++) {
      scanf("%s", word);
      char c1 = word[0], c2 = word[strlen(word)-1];
      deg[c1]++;//入度，存在入度和出度的相互抵消
      deg[c2]--;//出度
      used[c1] = used[c2] = 1;//标记用过，某种属性可以用变量的值来模拟
      int s1 = findset(c1), s2 = findset(c2);//找祖宗
      if(s1 != s2) { pa[s1] = s2; cc--; }//如果祖宗不相同，让s1的父亲为s2,连通快个数减一
    }//用的都是邻接矩阵

    vector<int> d;
    for(int ch = 'a'; ch <= 'z'; ch++) {
      if(!used[ch]) cc--; // 没出现过的字母，连通块减1
      else if(deg[ch] != 0) d.push_back(deg[ch]);//如果入度和出度抵消为零，放入向量
    }
    bool ok = false;
    if(cc == 1 && (d.empty() || (d.size() == 2 && (d[0] == 1 || d[0] == -1)))) ok = true;//判断连通，判断度数
    if(ok) printf("Ordering is possible.\n");
    else printf("The door cannot be opened.\n");
  }
  return 0;
}
/*
3 2 acm ibm 3 acm malform mouse 2 ok ok
*/
