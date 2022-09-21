package myTemplateJava;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class D_兄弟单词 {
  //判断是否为兄弟单词
  public static Boolean isBrother(String s, String word) {
    if (!s.equals(word)) {
      HashMap<Character, Integer> map1 = new HashMap<>();
      HashMap<Character, Integer> map2 = new HashMap<>();
      for (char c : s.toCharArray()) {
        map1.put(c, map1.getOrDefault(c, 0) + 1);
      }
      for (char c : word.toCharArray()) {
        map2.put(c, map2.getOrDefault(c, 0) + 1);
      }
      if (map1.keySet().equals(map2.keySet())) {
        Boolean flag = false;
        for (Character ch : map1.keySet()) {
          if (!map1.get(ch).equals(map2.get(ch))) {
            flag = true;
            break;
          }
        }
        return flag == false;
      }
    }
    return false;
  }

  //判断是否为兄弟单词
  public static boolean isBrother2(String x,String y){
    if (x.length()!=y.length()||y.equals(x)){
      return false;
    }
    char[] s = x.toCharArray();
    char[] j= y.toCharArray();
    Arrays.sort(s);
    Arrays.sort(j);
    return new String(s).equals(new String(j));


  }
  public static void main(String[] args) {
    Scanner sca = new Scanner(System.in);

    while (sca.hasNext()) {
      int n = sca.nextInt();
      String[] input = new String[n];

      for (int i = 0; i < n; i++) {
        input[i] = sca.next();
      }

      String word = sca.next();
      int k = sca.nextInt();

      int tem = 0;
      for (int i = 0; i < n; i++) {
        if (isBrother(input[i], word)) input[tem++] = input[i];
      }

      Arrays.sort(input, 0, tem); //自己写的快排和规范快排的 toIndex 的差别

      System.out.println(tem);
      if(k <= tem) {
        System.out.println(input[k - 1]);
      }

    }
  }

}


/**
 * https://www.nowcoder.com/practice/03ba8aeeef73400ca7a37a5f3370fe68?tpId=37&tqId=21250&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3FtpId%3D37&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * 定义一个单词的“兄弟单词”为：交换该单词字母顺序（注：可以交换任意次），而不添加、删除、修改原有的字母就能生成的单词。
 * 兄弟单词要求和原来的单词不同。例如： ab 和 ba 是兄弟单词。 ab 和 ab 则不是兄弟单词。
 * 现在给定你 n 个单词，另外再给你一个单词 x ，让你寻找 x 的兄弟单词里，按字典序排列后的第 k 个单词是什么？
 * 注意：字典中可能有重复单词。
 * 3 abc bca cab abc 1
 *
 * 2
 * bca
 *
 * Set 可以作为 Map 的 key
 * 自己写的快排和规范快排的 toIndex 的差别
 *  Collections.sort(list); //对于ArrayList的sort
 * 是否有序 是否重复
 * 两种等价的兄弟单词判断方法
 */

