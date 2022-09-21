package myTemplate;

import java.util.Scanner;

public class D_正则表达式 {

  public static Boolean isUsed(String s) {
    if (s.charAt(0) == 'A' || s.charAt(0) == 'D' || s.charAt(0) == 'S' || s.charAt(0) == 'W') {
      Boolean flag = false;
      for (int i = 1; i < s.length(); i++) {
        if (s.charAt(i) >= '0' && s.charAt(i) <= '9') continue;
        flag = true;
      }
      return flag == false;
    }
    return false;
  }

  public static void main(String[] args) {
    Scanner sca = new Scanner(System.in);

    String input = sca.nextLine();
    String[] s = input.split(";");

    int left = 0, right = 0;

    for (String tem : s) {
      //if(!tem.equals("") && isUsed(tem)) {
      if (tem.matches("[ADSW][0-9]{1,2}")) { //正则表达式
        if (tem.charAt(0) == 'A') left -= Integer.parseInt(tem.substring(1));
        else if (tem.charAt(0) == 'D') left += Integer.parseInt(tem.substring(1));
        else if (tem.charAt(0) == 'S') right -= Integer.parseInt(tem.substring(1));
        else if (tem.charAt(0) == 'W') right += Integer.parseInt(tem.substring(1));
      }
    }
    System.out.print(left + "," + right);
  }
}

/**
 * https://www.nowcoder.com/practice/119bcca3befb405fbe58abe9c532eb29?tpId=37&tqId=21240&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3FtpId%3D37&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * 开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。从（0,0）点开始移动，从输入字符串里面读取一些坐标，并将最终输入结果输出到输出文件里面。
 * A10;S20;W10;D30;X;A1A;B10A11;;A10;
 * 10,-10
 *
 * 正则表达式，可用来检索、替换、分割
 *
 * !tem.equals("") //空字符串不能用 == 判等，要用equals
 * JAVA中String并非基本数据类型而是一个类, 变量名实际代表地址,而不是像C++一样理解为字符数组
 * == 只能够确定两个字符串是否放在同一个位置，放在同一位置必然相等，但相等的字符串并不一定在同一位置!
 */
