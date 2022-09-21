package myTemplateJava;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class D_哈希表_空间换时间 {

  public static void main(String[] args) {
    Scanner sca = new Scanner(System.in);

    while (sca.hasNextLine()) {
      String input = sca.nextLine();

      Map<Character, Integer> map = new HashMap<>();
      for (char c : input.toCharArray()) {
        map.put(c, map.getOrDefault(c, 0) + 1); //如果使用空间换时间，数组元素值默认为0
      }

      int min = Integer.MAX_VALUE;
      for (Integer in : map.values()) {
        min = Math.min(min, in);
      }

      StringBuilder sb = new StringBuilder();
      for (char ch : input.toCharArray()) {
        if (map.get(ch) != min) {
          sb.append(ch);
        }
      }

      System.out.println(sb.toString());
    }
  }
}
/**
 * https://www.nowcoder.com/practice/05182d328eb848dda7fdd5e029a56da9?tpId=37&tqId=21246&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3FtpId%3D37&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * 实现删除字符串中出现次数最少的字符，若出现次数最少的字符有多个，则把出现次数最少的字符都删除。输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。
 * aabcddd
 *
 * aaddd
 */

