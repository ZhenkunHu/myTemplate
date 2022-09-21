package myTemplateJava;

import java.util.Arrays;
import java.util.Scanner;

public class B_dp_01背包 {
  public int coinChange(int[] coins, int amount) {
    int[] dp = new int[amount + 1];
    Arrays.fill(dp, amount + 1);
    dp[0] = 0;

    for(int w = 1; w <= amount; w++) {
      for(int i = 0; i < coins.length; i++) {
        if(coins[i] <= w) { //选 or 不选
          dp[w] = Math.min(dp[w], dp[w - coins[i]] + 1);
        }
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }

  public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);
    int[] coins = new int[] {1, 2, 5};
    int amount = 11;
    B_dp_01背包 solution = new B_dp_01背包();
    System.out.println(solution.coinChange(coins, amount));
  }

}

/**
 * https://leetcode.cn/problems/coin-change/
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3
 * 解释：11 = 5 + 5 + 1
 *
 * https://zhuanlan.zhihu.com/p/30959069 //0-1背包 理论
 * 01背包问题可以求最优解，也可以求存在性
 * 一次变化不是 + 1 的参数（变量）
 */
