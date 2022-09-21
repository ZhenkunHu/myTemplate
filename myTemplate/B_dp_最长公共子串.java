package myTemplate;

import java.util.Scanner;

public class B_dp_最长公共子串 {
  public static void main(String[] args) {

    Scanner sca = new Scanner(System.in);

    while (sca.hasNext()) {
      String s1 = sca.next();
      String s2 = sca.next();

      //令s1为较短串
      if(s1.length() > s2.length()) {
        String tem = s1;
        s1 = s2;
        s2 = tem;
      }

      int[][] dp = new int[s1.length() + 1][s2.length() + 1];

      //状态转移1，动态数组dp[i][j]表示在较短字符串str1以第i个字符结尾，str2中以第j个字符结尾时的公共子串长度
      for(int i = 1; i < s1.length() + 1; i++) {
        for(int j = 1; j < s2.length() + 1; j++) {
          if(s1.charAt(i - 1) == s2.charAt(j - 1))
            dp[i][j] = dp[i - 1][j - 1] + 1;
        }
      }

      int index1 = 1, index2 = 1;
      int max = Integer.MIN_VALUE;
      for(int i = 1; i < s1.length() + 1; i++) {
        for(int j = 1; j < s2.length() + 1; j++) {
          if(dp[i][j] > max) { //第一次出现
            max = dp[i][j];
            index1 = i;
            index2 = j;
          }
        }
      }
      System.out.println(s1.substring(index1 - dp[index1][index2], index1));


//      //状态转移2，动态数组dp[i][j]表示在较短字符串str1下标为i的字符结尾，str2下标为j的字符结尾时的公共子串长度
//      for(int j = 0; j < s2.length(); j++) {
//        if(s1.charAt(0) == s2.charAt(j)) dp[0][j] = 1;
//      }
//      for(int i = 0; i < s1.length(); i++) {
//        if(s1.charAt(i) == s2.charAt(0)) dp[i][0] = 1;
//      }
//
//      for(int i = 0; i < s1.length() - 1; i++) {
//        for(int j = 0; j < s2.length() - 1; j++) {
//          if(s1.charAt(i + 1) == s2.charAt(j + 1))
//            dp[i + 1][j + 1] = dp[i][j] + 1;
//        }
//      }
//
//      int index1 = 0, index2 = 0;
//      int m = Integer.MIN_VALUE;
//      for(int i = 0; i < s1.length(); i++) {
//        for(int j = 0; j < s2.length(); j++) {
//          if(dp[i][j] > m) { //第一次出现
//            m = dp[i][j];
//            index1 = i;
//            index2 = j;
//          }
//        }
//      }
//      System.out.println(s1.substring(index1 + 1 - dp[index1][index2], index1 + 1));
    }
  }
}

/**
 * https://www.nowcoder.com/practice/181a1a71c7574266ad07f9739f791506?tpId=37&tqId=21288&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D2%26tpId%3D37%26type%3D37&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * 查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
 * 注：子串的定义：将一个字符串删去前缀和后缀（也可以不删）形成的字符串。请和“子序列”的概念分开！
 * abcdefghijklmnop
 * abcsafjklmnopqrstuvw
 *
 * jklmnop
 *
 * 维护动态数组dp[i][j]表示在较短字符串str1以第i个字符结尾，str2中以第j个字符结尾时的公共子串长度。
 * 从左向右递推，i为短字符串str1的结尾索引，j为str2的结尾索引
 * 相等则计数，并不断更新最长公共子串的长度和结尾索引
 */

