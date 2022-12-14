// UVa129 Krypton Factor
// Rujia Liu
#include<stdio.h>
int n, L, cnt;
int S[100];

int dfs(int cur) {// 返回0表示已经得到解，无须继续搜索
  if(cnt++ == n) {
    for(int i = 0; i < cur; i++) {
      if(i % 64 == 0 && i > 0) printf("\n");//格式控制
      else if(i % 4 == 0 && i > 0) printf(" ");
      printf("%c", 'A'+S[i]); // 输出方案
    }
    printf("\n%d\n", cur);
    return 0;
  }
  for(int i = 0; i < L; i++) {
    S[cur] = i;
    int ok = 1;//标志变量
    for(int j = 1; j*2 <= cur+1; j++) {// 尝试长度为j*2的后缀，在这里j必须要从1开始
      int equal = 1;//不要把计数器当成标志变量，应该分开它们
      for(int k = 0; k < j; k++)// 检查后一半是否等于前一半
        if(S[cur-k] != S[cur-k-j]) { equal = 0; break; }//果然字符可以看成是一种特殊的整型，只是输出时有了变化
      if(equal) { ok = 0; break; }// 后一半等于前一半，方案不合法
    }
    if(ok) if(!dfs(cur+1)) return 0;// 递归搜索。如果已经找到解，则直接退出
  }
  return 1;
}

int main() {
  while(scanf("%d%d", &n, &L) == 2 && n > 0) {
    cnt = 0;
    dfs(0);//返回值为int型，但返回值只在函数里用的到
  }
  return 0;
}
