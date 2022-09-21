package myTemplate;

import java.util.Iterator;
import java.util.Scanner;
import java.util.TreeSet;

public class D_TreeSet {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n;

    while (scanner.hasNextInt()) {
      TreeSet<Integer> treeSet = new TreeSet<>();
      n = Integer.parseInt(scanner.nextLine());
      for (int i = 0; i < n; i++) {
        treeSet.add(scanner.nextInt());
      }

      //TreeSet的ForEach遍历
      for (Integer i : treeSet) {
        System.out.println(i);
      }

      //TreeSet的迭代器遍历
      Iterator iterator = treeSet.iterator();
      while (iterator.hasNext()) {
        System.out.println(iterator.next());
      }

      //TreeSet的Lambda遍历
      treeSet.forEach((i) -> System.out.println(i));
    }
  }
}

/**
 * https://www.nowcoder.com/practice/3245215fffb84b7b81285493eae92ff0?tpId=37&tqId=21226&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3FtpId%3D37&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * 明明生成了NN个1到500之间的随机整数。请你删去其中重复的数字，即相同的数字只保留一个，把其余相同的数去掉，然后再把这些数从小到大排序，按照排好的顺序输出。
 * 3
 * 2
 * 2
 * 1
 * <p>
 * 1
 * 2
 * <p>
 * 本题因为对输入有明确的限制，因此可以使用 空间换时间 的方法
 */
