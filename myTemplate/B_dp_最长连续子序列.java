package myTemplate;

public class B_dp_最长连续子序列 {
  public int findLengthOfLCIS(int[] nums) {

    //特殊情况，未覆盖的情况
    if(nums.length <= 1) return 1;

    int[] dp = new int[nums.length]; //下标为i的最长子序列
    //预处理 初始化
    for(int i = 0; i < nums.length; i++) {
      dp[i] = 1;
    }

    int max = 0;
    //状态转移
    for(int i = 1; i < nums.length ; i++) {
      if(nums[i - 1] < nums[i]) dp[i] = dp[i - 1] + 1;
      max = Math.max(max, dp[i]);
    }

    return max;
  }

  public static void main(String[] args) {

  }
}

/**
 * https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
 * 给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
 * 输入：nums = [1,3,5,4,7]
 *
 * 输出：3
 *
 * dp[i]下标为i的最长子序列
 *
 */

