package myTemplateJava;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C_组合_dfs {
  ArrayList<Integer> temp = new ArrayList<>();
  List<List<Integer>> ans = new ArrayList<>();

  private void dfs(int cur, int[] num, int k) {
    // 剪枝：temp 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的 temp
    if(temp.size() + (num.length - cur) < k ) return;

    // 记录合法的答案
    if(temp.size() == k) {
      ans.add(new ArrayList<>(temp));
      return;
    }

    // 前两个if可以覆盖掉这个if
    //if(cur == num.length) return;

    // 考虑选择当前位置
    temp.add(num[cur]);
    dfs(cur + 1, num, k);
    // 考虑不选择当前位置
    temp.remove(temp.size() - 1);
    dfs(cur + 1, num, k);
  }

  public List<List<Integer>> combine(int n, int k) {
    int[] num = new int[n];
    for(int i = 0; i < n; i++)
      num[i] = i + 1;

    dfs(0, num, k);

    return ans;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    C_组合_dfs solution = new C_组合_dfs();
    List<List<Integer>> res = solution.combine(4, 2);
    for(int i = 0; i < res.size(); i++) {
      for(Integer num : res.get(i)) {
        System.out.print(num + " ");
      }
      System.out.println();
    }
  }
}

/**
 * https://leetcode.cn/problems/combinations/
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 * n = 4, k = 2
 *
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 *
 * 排列与组合
 *
 */

