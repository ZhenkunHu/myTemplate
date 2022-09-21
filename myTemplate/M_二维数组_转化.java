package myTemplate;

import java.util.Scanner;

public class M_二维数组_转化 {
  //暴力
  public boolean find1(int target, int [][] array) {
    for(int i = 0; i < array.length; i++) {
      for(int j = 0; j < array[i].length; j++) {
        if(array[i][j] == target) {
          return true;
        }
      }
    }
    return false;
  }

  //利用有序这个前提
  public boolean find2(int target, int [][] array) {
    //优先 判断特殊
    if(array.length == 0) return false;
    int n = array.length;
    if(array[0].length == 0) return false;
    int m = array[0].length;

    //从最左下角的元素开始往左或往上
    for(int i = n - 1, j = 0; i >= 0 && j < m; ) {
      //元素较大，往上走
      if(array[i][j] > target)
        i--;
        //元素较小，往右走
      else if(array[i][j] <target)
        j++;
      else
        return true;
    }
    return false;
  }

  public static void main(String[] args) {

    Scanner sca = new Scanner(System.in);

    while (sca.hasNext()) {

    }
  }
}

/**
 * https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=265&tqId=39208&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26pageSize%3D50%26search%3D%26tpId%3D13%26type%3D265&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * 在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 * 7,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
 *
 * true
 *
 * 利用该二维数组的性质：
 * 每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序
 * 转化，即对于左下角的值 m，m 是该行最小的数，是该列最大的数
 * 每次将 m 和目标值 target 比较：
 * 当 m < target，由于 m 已经是该行最大的元素，想要更大只有从列考虑，取值右移一位
 * 当 m > target，由于 m 已经是该列最小的元素，想要更小只有从行考虑，取值上移一位
 * 当 m = target，找到该值，返回 true
 * 用某行最小或某列最大与 target 比较，每次可剔除一整行或一整列
 *
 * 尝试用dfs
 */

