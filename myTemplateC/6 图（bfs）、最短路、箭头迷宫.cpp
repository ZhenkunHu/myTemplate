#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

struct Node {
  int r, c, dir; // 站在(r,c)，面朝方向dir(0~3分别表示N, E, S, W)
  Node(int r=0, int c=0, int dir=0):r(r),c(c),dir(dir) {}
};

const int maxn = 10;
const char* dirs = "NESW"; // 顺时针旋转
const char* turns = "FLR";

int has_edge[maxn][maxn][4][3];//当前状态是(r,c,dir)，是否可以沿着转弯方向turn行走
int d[maxn][maxn][4];//最短路长度，兼标记数组
Node p[maxn][maxn][4];//保存了状态（r,c,dir）在BFS树中的父结点
int r0, c0, dir, r1, c1, r2, c2;

int dir_id(char c) { return strchr(dirs, c) - dirs; }//提供相应的转换函数
int turn_id(char c) { return strchr(turns, c) - turns; }

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

Node walk(const Node& u, int turn) {//行走函数，根据当前状态和转弯方式，计算出后续状态
  int dir = u.dir;
  if(turn == 1) dir = (dir + 3) % 4; // 逆时针//左右可以转化为时针
  if(turn == 2) dir = (dir + 1) % 4; // 顺时针
  return Node(u.r + dr[dir], u.c + dc[dir], dir);//这之间的映射关系，妙啊
}

bool inside(int r, int c) {//判断是否出界
  return r >= 1 && r <= 9 && c >= 1 && c <= 9;
}

bool read_case() {//输入函数
  char s[99], s2[99];
  if(scanf("%s%d%d%s%d%d", s, &r0, &c0, s2, &r2, &c2) != 6) return false;
  printf("%s\n", s);

  dir = dir_id(s2[0]);
  r1 = r0 + dr[dir];//沿着(r0,c0)走一步的坐标为(r1,c1)
  c1 = c0 + dc[dir];

  memset(has_edge, 0, sizeof(has_edge));
  for(;;) {
    int r, c;
    scanf("%d", &r);
    if(r == 0) break;
    scanf("%d", &c);
    while(scanf("%s", s) == 1 && s[0] != '*') {
      for(int i = 1; i < strlen(s); i++)
        has_edge[r][c][dir_id(s[0])][turn_id(s[i])] = 1;//r行c列的朝向能往哪里转
    }
  }
  return true;
}

void print_ans(Node u) {//可以用递归方式打印最短路的路径，也可以用循环（避免栈溢出）（优先用BFS）
  // 从目标结点逆序追溯到初始结点
  vector<Node> nodes;//像BFS
  for(;;) {
    nodes.push_back(u);
    if(d[u.r][u.c][u.dir] == 0) break;
    u = p[u.r][u.c][u.dir];//因为就一条路径，父结点只有一个儿子
  }
  nodes.push_back(Node(r0, c0, dir));//初始状态是刚刚离开出口

  // 打印解，每行10个
  int cnt = 0;
  for(int i = nodes.size()-1; i >= 0; i--) {
    if(cnt % 10 == 0) printf(" ");//这个控制很精致
    printf(" (%d,%d)", nodes[i].r, nodes[i].c);
    if(++cnt % 10 == 0) printf("\n");
  }
  if(nodes.size() % 10 != 0) printf("\n");//不到满十行时
}

void solve() {
  queue<Node> q;
  memset(d, -1, sizeof(d));
  Node u(r1, c1, dir);
  d[u.r][u.c][u.dir] = 0;
  q.push(u);
  while(!q.empty()) {
    Node u = q.front(); q.pop();
    if(u.r == r2 && u.c == c2) { print_ans(u); return; }
    for(int i = 0; i < 3; i++) {
      Node v = walk(u, i);
      if(has_edge[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir] < 0) {//未出界，非障碍，未标记
        d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
        p[v.r][v.c][v.dir] = u;
        q.push(v);
      }
    }
  }
  printf("  No Solution Possible\n");
}

int main() {
  while(read_case()) {
    solve();
  }
  return 0;
}

