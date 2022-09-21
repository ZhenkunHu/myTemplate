package myTemplate;

public class D_最长回文子串 {
  public int getLongestPalindrome (String A) {
    int max = 0;
    for(int i = 0; i < A.length(); i++) {
      int left = i - 1, right = i + 1;
      while(right < A.length() && A.charAt(right) == A.charAt(i)) right++; //"baab" 考虑相邻两个字符相同的情况
      while(left >= 0 && right < A.length()) {
        if(A.charAt(left) == A.charAt(right)) {
          left--;
          right++;
        } else break;
      }
      max = Math.max(max, right - left - 1);
    }
    return max;
  }

  public static void main(String[] args) {

  }
}

/**
 * https://www.nowcoder.com/practice/b4525d1d84934cf280439aeecc36f4af?tpId=117&tqId=37789&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26pageSize%3D50%26search%3D17%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=17
 * 对于长度为n的一个字符串A（仅包含数字，大小写英文字母），请设计一个高效算法，计算其中最长回文子串的长度。
 * "ababc"
 *
 * 3
 *
 * 边界 left >= 0 && right < A.length()
 */

