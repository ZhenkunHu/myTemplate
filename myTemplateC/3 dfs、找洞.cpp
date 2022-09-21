#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>//已知大小用数组，未知大小用 vector //组件之间相互连接 
#include<set>//深搜标记后，可用set确定连通块的个数 
using namespace std;

char bin[256][5];//只用了十六进制字符的那几个整型 

const int maxh = 200 + 5;
const int maxw = 50 * 4 + 5;//两个十六进制与八个二进制 

int H, W, pic[maxh][maxw], color[maxh][maxw];
char line[maxw];

void decode(char ch, int row, int col) {//解码，把十六进制转化为二进制 
  for(int i = 0; i < 4; i++)
    pic[row][col+i] = bin[ch][i] - '0';
}

const int dr[] = {-1, 1, 0, 0};// 下上左右 
const int dc[] = {0, 0, -1, 1};//下上左右 

// dfs from (row, col) and paint color c
void dfs(int row, int col, int c) {//深搜的参数按功能确定，像普通函数一样 
  color[row][col] = c;
  for(int i = 0; i < 4; i++) {//一层循环相邻四个格子与二层循环相邻八个格子 
    int row2 = row + dr[i];
    int col2 = col + dc[i];
    if(row2 >= 0 && row2 < H && col2 >= 0 && col2 < W && pic[row2][col2] == pic[row][col] && color[row2][col2] == 0)
      dfs(row2, col2, c);//没有出界，同种像素，没有访问过 
  }
}

vector<set<int> > neighbors;

void check_neighbors(int row, int col) { 
  for(int i = 0; i < 4; i++) {
    int row2 = row + dr[i];
    int col2 = col + dc[i];//没有出界，存在相邻色素为0，相邻色素要排除外部空白的那一个连通块 
    if(row2 >= 0 && row2 < H && col2 >= 0&& col2 < W && pic[row2][col2] == 0 && color[row2][col2] != 1)
      neighbors[color[row][col]].insert(color[row2][col2]); //把属于同一个洞的像素放在同一个集合里 
  }
}

const char* code = "WAKJSD";// 常量数组 

char recognize(int c) {// 把有几个洞转化为符号 
  int cnt = neighbors[c].size();//因为set中的元素只出现一次 
  return code[cnt];
}

// use this function to print the decoded picture
void print() { 
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) printf("%d", pic[i][j]);
    printf("\n");
  }
}

int main() {
  strcpy(bin['0'], "0000");//对二维数组的理解 
  strcpy(bin['1'], "0001");//转二进制对应就行 
  strcpy(bin['2'], "0010");//转高进制相乘就行 
  strcpy(bin['3'], "0011");
  strcpy(bin['4'], "0100");
  strcpy(bin['5'], "0101");
  strcpy(bin['6'], "0110");
  strcpy(bin['7'], "0111");
  strcpy(bin['8'], "1000");
  strcpy(bin['9'], "1001");
  strcpy(bin['a'], "1010");
  strcpy(bin['b'], "1011");
  strcpy(bin['c'], "1100");
  strcpy(bin['d'], "1101");
  strcpy(bin['e'], "1110");
  strcpy(bin['f'], "1111");

  int kase = 0;
  while(scanf("%d%d", &H, &W) == 2 && H) {
    memset(pic, 0, sizeof(pic));
    for(int i = 0; i < H; i++) {
      scanf("%s", line);
      for(int j = 0; j < W; j++)
        decode(line[j], i+1, j*4+1);//把十六进制转化为二进制 
    }

    H += 2;// 防止溢出 
    W = W * 4 + 2; 

    int cnt = 0;
    vector<int> cc; // connected components of 1//连接组件 
    memset(color, 0, sizeof(color));
    for(int i = 0; i < H; i++)
      for(int j = 0; j < W; j++)
        if(!color[i][j]) {
          dfs(i, j, ++cnt);
          if(pic[i][j] == 1) cc.push_back(cnt);// cnt为2、4、7、8,分别为象形符号的黑色像素连通块 
        }

    neighbors.clear();
    neighbors.resize(cnt+1);//vector.resize() 
    for(int i = 0; i < H; i++)
      for(int j = 0; j < W; j++)
        if(pic[i][j] == 1)
          check_neighbors(i, j);

    vector<char> ans;
    for(int i = 0; i < cc.size(); i++)
      ans.push_back(recognize(cc[i]));
    sort(ans.begin(), ans.end());
print(); 
    printf("Case %d: ", ++kase);
    for(int i = 0; i < ans.size(); i++) printf("%c", ans[i]);
    printf("\n");
  }
  return 0;
}
/*输入样例 
100 25

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

00000f8000000000000000000

00001fe000000000000000000

00007ff000000000000000000

00007ff800000000000000000

0000f8f800000000000000000

0001f07c00000000000000000

0001e03c00000000001800000

0001e01c00000000003c00000

0001c01c00000000007c00000

0003c01e0000000000f800000

0003c01e0000000001f000000

0001c01c0000000003f000000

0001c01c0000000007e000000

0001e01c000000000fc000000

0001e03c000000001fc000000

0000e03c000000001fc000000

0000f038000000003ff000000

0000f078000000003ff800000

00007870000000007ff800000

000038f0000000007cfc00000

00003ce0000000007c7c00000

00781fc0f0000000f87c00000

007ffffff0000000f07c00000

007ffffff0000000f07c00000

007ffffff0000001f07c00000

007ffffff0000000e03e00000

007fcf81f0000000603e00000

00000f8000000000003e00000

00000f8000000000003e00000

00000f8000000000003e00000

00000f8000000000001e00000

00000f8000000000001f00000

00000fc000000000001f00000

00000fc000000000001f00000

00000fc000000000001f00000

00000fc000000000000f00000

00001fc000000000000f80000

00001fc000000000000f80000

00001fc000000000000f80000

00001fc000000000000f80000

00001fe000000000000f80000

00001fe000000000000780000

00001fe0000000000007c0000

00001fe0000000000007c0000

00003fe0000000000007c0000

00003fe0000000000007c0000

00003fe0000000000007c0000

00003fe0000c00000003c0000

00000000003ff0000003c0000

00000000007ff8000003e0000

0000000001fffc000003e0000

0000000003e03f000003e0000

0000000007c00f000003e0000

000000000f0003800003f0000

000000000e0001c00003fc000

000000001c0001e00007fe000

000000003c0000e0000fff000

000000073c000070000fdf000

0000001ff8000070001f0f800

0000001ff8000070001e07800

0000003cf0000078001e03800

0000003870000033001e03800

000000307800003fc01e03800

000000703800007fe00e03800

000000703800007ce00e03800

000000703c000078700703800

000000701e0000f0700701000

000000701e0000e0700300000

000000700f0001c0700000000

0000006007800380600000000

000000e003e00700600000000

000000e001fe7e00600000000

000000e000fffc00e00000000

000000e0000ff000e00000000

000000f800038000e00000000

000000fff0000000e00000000

000000fffff00000e00000000

00000003ffffe000c00000000

0000000007ffffc0c00000000

000000000007ffffc00000000

0000000000000fffc00000000

000000000000001fc00000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000
*/ 
