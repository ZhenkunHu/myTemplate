package myTemplate;

import java.util.Scanner;

public class C_ipv4_int {
  public static String convert(String str) {
    //ipv4 -> int
    if(str.contains(".")) {
      String[] fields = str.split("\\.");
      long result = 0;
      for(int i = 0; i < 4; i++) {
        result = result * 256 + Long.parseLong(fields[i]);
      }
      return "" + result;
    }
    //int -> ipv4
    else {
      long ipv4 = Long.parseLong(str);
      String result = "";
      for(int i = 0; i < 4; i++) {
        result = ipv4 % 256 + "." + result;
        ipv4 /= 256;
      }
      return result.substring(0, result.length() - 1); //要么预处理，要么后处理
    }
  }

  public static void main(String[] args) {
    Scanner sca = new Scanner(System.in);
    while (sca.hasNextLine()) {
      System.out.println(convert(sca.next()));
    }
  }

}

/**
 * https://www.nowcoder.com/practice/66ca0e28f90c42a196afd78cc9c496ea?tpId=37&tqId=21256&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3FtpId%3D37&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * 原理：ip地址的每段可以看成是一个0-255的整数，把每段拆分成一个二进制形式组合起来，然后把这个二进制数转变成一个长整数。
 * 10.0.3.193
 * 167969729
 *
 * 167773121
 * 10.3.3.193
 *
 * 在 Java 中，\\ 表示：我要插入一个正则表达式的反斜线，所以其后的字符具有特殊的意义。
 */
