package myTemplateJava;

import java.util.HashMap;
import java.util.Scanner;

public class A_贪心_最少兔子 {
  public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);
    while (scanner.hasNextInt()) {
      int n = scanner.nextInt();
      int[] answers = new int[n];
      for (int i = 0; i < n; i++) {
        answers[i] = scanner.nextInt();
      }

      if (answers.length == 0) {
        System.out.println(0);
        break;
      }

      HashMap<Integer, Integer> map = new HashMap<>();
      for (int i = 0; i < answers.length; i++) {
        map.put(answers[i], map.getOrDefault(answers[i], 0) + 1);
      }

      int ans = 0;
      for (Integer i : map.keySet()) {
        while (i + 1 < map.get(i)) {
          ans += i + 1;
          map.put(i, map.get(i) - i - 1);
        }
        ans += i + 1;
      }
      System.out.println(ans);
    }
  }
}

/**
 * 华为od一面
 * 森林中，每个兔子都有颜色。其中
 * -些兔子(可能是全部)告诉你
 * 还有多少其他的兔子和自己有相
 * 同的颜色。我们将这些回答放在
 * answers数组里。
 * 返回森林中兔子的最少数量。
 * 3
 * 1 1 2
 *
 * 5
 *
 * 3
 * 10 10 10
 *
 * 11
 *
 * 3
 * 1 1 1
 *
 * 4
 *
 * 贪心策略
 */
