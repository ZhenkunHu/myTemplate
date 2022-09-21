package myTemplateJava;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class A_Arrays_sort {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    while (scanner.hasNextInt()) {
      Integer n = scanner.nextInt();
      Integer[] num = new Integer[n];
      for(int i = 0; i < n; i++) {
        num[i] = scanner.nextInt();
      }
      int flag = scanner.nextInt();

      Arrays.sort(num, new Comparator<Integer>() {
        public int compare(Integer i, Integer j) {
          return i - j;
        }
      });

      if(flag == 0) {
        System.out.print(num[0]);
        for(int i = 1; i < n; i++) {
          System.out.print(" " + num[i]);
        }
      } else if(flag == 1){
        System.out.print(num[n-1]);
        for(int i = n - 2; i >= 0; i--) {
          System.out.print(" " + num[i]);
        }
      }

    }
  }
}

/**
 * https://www.nowcoder.com/practice/dd0c6b26c9e541f5b935047ff4156309?tpId=37&tqId=21324&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D2%26tpId%3D37%26type%3D37&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * 输入整型数组和排序标识，对其元素按照升序或降序进行排序
 * 8
 * 1 2 4 9 3 55 64 25
 * 0
 *
 * 1 2 3 4 9 25 55 64
 *
 * Integer[] num = new Integer[n] //这里Java可以用n
 * Arrays.sort(num, new Comparator<T>() {}) //注意比较器的使用，前者 - 后者 代表 升序
 */

