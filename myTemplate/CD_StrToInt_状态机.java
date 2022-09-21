package myTemplate;

public class CD_StrToInt_状态机 {

  //法一：遍历法
  public int StrToInt1 (String s) {
    //空串
    if(s.isEmpty())
      return 0;

    int res = 0;
    int index = 0;
    int n = s.length();

    //去掉前导空格，如果有
    while(index < n){
      if(s.charAt(index) == ' ')
        index++;
      else
        break;
    }
    //去掉空格就什么都没有了
    if(index == n)
      return 0;
    int sign = 1;

    //处理第一个符号是正负号的情况
    if(s.charAt(index) == '+')
      index++;
    else if(s.charAt(index) == '-'){
      index++;
      sign = -1;
    }
    //去掉符号就什么都没有了
    if(index == n)
      return 0;

    while(index < n){
      char c = s.charAt(index);
      //后续非法字符，截断
      if(c < '0' || c > '9')
        break;
      //处理越界
      if(res > Integer.MAX_VALUE / 10 || (res == Integer.MAX_VALUE / 10 && (c - '0') > Integer.MAX_VALUE % 10))
        return Integer.MAX_VALUE;
      if(res < Integer.MIN_VALUE / 10 || (res == Integer.MIN_VALUE / 10 && (c - '0') > -(Integer.MIN_VALUE % 10))) //注意这里的负号，负数取模为负数
        return Integer.MIN_VALUE;
      res = res * 10 + sign * (c - '0');
      index++;
    }
    return res;
  }


  //法2：状态机
  public int StrToInt2 (String s) {
    //状态转移矩阵
    int[][] states = {
            {0,1,2,3,1},
            {3,1,2,3,3},
            {3,2,2,3,3},
    };
    long res = 0;
    //与int边界比较
    long top = Integer.MAX_VALUE;
    long bottom = Integer.MIN_VALUE;
    int n = s.length();
    int sign = 1;
    //状态从“ ”开始
    int state = 0;
    for(int i = 0; i < n; i++){
      char c = s.charAt(i);
      if(c == ' ')
        //空格
        state = states[state][0];
      else if(c == '0')
        //前导0或者中间的0
        state = states[state][1];
      else if(c >= '1' && c <= '9')
        //数字
        state = states[state][2];
      else if(c == '-' || c == '+'){
        //正负号
        state = states[state][4];
        if(state == 1)
          sign = (c == '-') ? -1 : 1;
        else
          break;
      }else
        //非法字符
        state = states[state][3];

      if(state == 2){
        //数字相加
        res = res * 10 + (c - '0');
        //越界处理
        res = (sign == 1) ? Math.min(res, top) : Math.min(res, -bottom);
      }
      if(state == 3)
        break;
    }
    return (int)(sign * res);
  }
}

/**
 * https://www.nowcoder.com/practice/d11471c3bf2d40f38b66bb12785df47f?tpId=117&tqId=37754&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26pageSize%3D50%26search%3D100%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=100
 * 把字符串转换成整数(atoi)
 * "4396 clearlove"
 *
 * 4396
 *
 * 遍历法与状态机
 * 状态机：状态 状态转移矩阵与set
 *
 * 动态规划：状态 状态转移方程
 */