package myTemplateJava;

import java.util.HashMap;
import java.util.Scanner;

public class D_哈希表 {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int[] numbers = new int[10000];
    int target;
    while (scanner.hasNextLine()) {
      String s = scanner.nextLine();
      String[] numAndTar = s.split("],");
      String[] numbersString = numAndTar[0].substring(1).split(",");
      for (int i = 0; i < numbersString.length; i++) {
        numbers[i] = Integer.parseInt(numbersString[i]);
      }
      target = Integer.parseInt(numAndTar[1]);

      int[] ans = twoSum(numbers, target);
      for (int i = 0; i < ans.length; i++)
        System.out.print(ans[i] + " ");
    }
  }

  /**
   * @param numbers int整型一维数组
   * @param target  int整型
   * @return int整型一维数组
   */
  public static int[] twoSum(int[] numbers, int target) {
    // write code here
    HashMap<Integer, Integer> map = new HashMap<>();
    //遍历数组
    for (int i = 0; i < numbers.length; i++) {
      //将不包含target - numbers[i]，装入map中，包含的话直接返回下标
      if (map.containsKey(target - numbers[i]))
        return new int[]{map.get(target - numbers[i]) + 1, i + 1};
      else
        map.put(numbers[i], i);
    }
    throw new IllegalArgumentException("No solution");
  }

}

/**
 * https://www.nowcoder.com/practice/20ef0972485e41019e39543e8e895b7f?tpId=117&tqId=37756&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * 给出一个整型数组 numbers 和一个目标值 target，请在数组中找出两个加起来等于目标值的数的下标，返回的下标按升序排列。
 * （注：返回的数组下标从1开始算起，保证target一定可以由数组里面2个数字相加得到）
 * [3,2,4],6
 * [2,3]
 *
 * 哈希表加快查找速度
 * https://blog.csdn.net/w605283073/article/details/80708943 //遍历HashMap的五种方式
 */
