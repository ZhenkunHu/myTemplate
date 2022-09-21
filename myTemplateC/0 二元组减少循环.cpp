/*
UVA1592
�Զ����£����󾫡�һ��һ��Ĺ���
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<sstream>
using namespace std;
typedef pair<int,int> PII;//����ṹ���ǿ����Ԫ��
const int maxr = 10000 + 5;
const int maxc = 10 + 5;
int m, n, db[maxr][maxc], cnt;

map<string, int> id;//ת��˼�롣Ԥ������ÿ���ַ���������֣�����ÿ����Ԫ�񶼱�������֡�
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
        PII p = make_pair(db[i][c1], db[i][c2]);//�����п���һ�����塣��Ԫ�顣make_pair()
        if(d.count(p)) {//����˼�롣���p
          printf("NO\n");
          printf("%d %d\n", d[p]+1, i+1);//��ǰ�У���һ�� //��Ϊ��0����
          printf("%d %d\n", c1+1, c2+1);//��ǰ�У���һ��
          return;
        }
        d[p] = i;
      }
    }
  printf("YES\n");//���û�ҵ������YES��
}

int main() {
  string s;
  while(getline(cin, s)) {
    stringstream ss(s);
    if(!(ss >> n >> m)) break;//����ѭ��
    cnt = 0;
    id.clear();//id.clear()
    for(int i = 0; i < n; i++) {
      getline(cin, s);//����cin>>s;
      int lastpos = -1;//��ʼ����int
      for(int j = 0; j < m; j++) {
        int p = s.find(',', lastpos+1);//find()��ʹ��find ',' form (lastpos+1)//��Ӣ��Ĺ۵���⺯���Ĳ���˳��
        if(p == string::npos) p = s.length();//�ҵ��������
        db[i][j] = ID(s.substr(lastpos+1, p - lastpos - 1));//substr()��ʹ�ã�����java
        lastpos = p;//���¸�ֵ��
      }
    }
    find();
  }
  return 0;
}
