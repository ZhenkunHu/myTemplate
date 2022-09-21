package myTemplate;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;

public class A_暴力枚举_称砝码 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    while(scanner.hasNextInt()) {
      int n = scanner.nextInt();
      int[][] map = new int[n][2];
      for(int i = 0; i < n; i++) {
        map[i][0] = scanner.nextInt();
      }
      for(int i = 0; i < n; i++) {
        map[i][1] = scanner.nextInt();
      }

      TreeSet<Integer> set = new TreeSet<>();
      set.add(0); //称重重量包括 0
      for(int i = 0; i < map.length; i++) { //遍历砝码
        ArrayList<Integer> list = new ArrayList<>(set); //取当前所有的结果
        for(int j = 0; j < map[i][1]; j++) { //遍历个数
          for(int k = 0; k < list.size(); k++) { //遍历当前所有结果
            set.add(list.get(k) + map[i][0] * (j + 1));
          }
        }
      }
      System.out.println(set.size());
    }
  }
}

/**
 * https://www.nowcoder.com/practice/f9a4c19050fc477e9e27eb75f3bfd49c?tpId=37&tqId=21264&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26pageSize%3D50%26search%3D41%26tpId%3D37%26type%3D37&difficulty=undefined&judgeStatus=undefined&tags=&title=41
 * 现有n种砝码，重量互不相等，分别为 m1,m2,m3…mn ；每种砝码对应的数量为 x1,x2,x3...xn 。现在要用这些砝码去称物体的重量(放在同一侧)，问能称出多少种不同的重量。
 * 2
 * 1 2
 * 2 1
 *
 * 5
 *
 * 结果只需要重量，不需要组合，所以不枚举组合
 * HashMap<Integer, Integer> 的keySet有时不按key出现的顺序排列
 */

