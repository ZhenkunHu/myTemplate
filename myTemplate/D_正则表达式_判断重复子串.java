package myTemplate;

import java.util.Scanner;
import java.util.regex.Pattern;

public class D_正则表达式_判断重复子串 {
  //正则表达式
  public static Boolean getMatch(String s) {
    int count = 0;
    Pattern pattern1 = Pattern.compile("[a-z]");
    if (pattern1.matcher(s).find())
      count++;

    Pattern pattern2 = Pattern.compile("[A-Z]");
    if (pattern2.matcher(s).find())
      count++;

    Pattern pattern3 = Pattern.compile("[0-9]");
    if (pattern3.matcher(s).find())
      count++;

    Pattern pattern4 = Pattern.compile("[^a-zA-Z0-9]");
    if (pattern4.matcher(s).find())
      count++;

    return count >= 3;
  }

  //判断是否有重复子串
  public static Boolean getString(String s, int left, int right) {
    if (right > s.length()) return false;
    else if (s.substring(right).contains(s.substring(left, right))) return true;
    return getString(s, left + 1, right + 1);
  }

  public static void main(String[] args) {
    Scanner sca = new Scanner(System.in);

    String s = sca.next();
    if (s.length() > 8) {
      if (getMatch(s)) {
        if (!getString(s, 0, 3))
          System.out.println("OK");
        else System.out.println("NG");
      } else
        System.out.println("OK");
    } else
      System.out.println("NG");
  }
}
/**
 * https://www.nowcoder.com/practice/184edec193864f0985ad2684fbc86841?tpId=37&tqId=21243&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3FtpId%3D37&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * 密码要求:
 * 1.长度超过8位
 * 2.包括大小写字母.数字.其它符号,以上四种至少三种
 * 3.不能有长度大于2的包含公共元素的子串重复 （注：其他符号不含空格或换行）
 * 021Abc9000
 * 021Abc9Abc1
 * 021ABC9000
 * 021$bc9000
 * <p>
 * OK
 * NG
 * NG
 * OK
 * <p>
 * 正则表达式 与 判断重复子串
 * 为了易读性，可以if else语句都加{ }
 */

