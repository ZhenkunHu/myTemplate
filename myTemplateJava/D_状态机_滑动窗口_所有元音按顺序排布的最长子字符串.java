package myTemplateJava;

import java.util.*;

public class D_状态机_滑动窗口_所有元音按顺序排布的最长子字符串 {

  //法一：状态机
  public static int longestBeautifulSubstring(String word) {
    TreeSet<String> set = new TreeSet<>();
    set.add("ae");
    set.add("ei");
    set.add("io");
    set.add("ou");
    set.add("aa");
    set.add("ee");
    set.add("ii");
    set.add("oo");
    set.add("uu");
    set.add("xa");
    set.add("ea");
    set.add("ia");
    set.add("oa");
    set.add("ua");

    int cur = 0, max = 0;

    char status = 'x';
    for(char c : word.toCharArray()) {
      if(set.contains("" + status + c)) {
        if(status != 'a' && c == 'a') {
          cur = 1;
          status = c;
        } else {
          cur++;
          status = c;
        }
      } else {
        cur = 0;
        status = 'x';
      }

      if(c == 'u') {
        max = Math.max(max, cur);
      }
    }
    return max;
  }

  //法二：滑动窗口
  public int longestBeautifulSubstring2(String word) {
    List<Character> window=new ArrayList<Character>();
    Set<Character> set = new HashSet<Character>();
    int left=0;
    int res = 0;
    int right=0;
    while(right<word.length()) {
      if (window.isEmpty() || word.charAt(right)>=window.get(window.size()-1)) {
        window.add(word.charAt(right));
        set.add(word.charAt(right));
        if (set.size()==5) {
          res=Math.max(res, window.size());
        }
      }else {
        window.clear();
        set.clear();
        left=right;
        window.add(word.charAt(left));
        set.add(word.charAt(left));
      }
      right++;
    }
    return res;
  }

  public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);

    while (scanner.hasNext()) {
      String str = scanner.next();
      System.out.println(longestBeautifulSubstring(str));
    }
  }
}

/**
 * https://leetcode.cn/problems/longest-substring-of-all-vowels-in-order/
 * 所有元音按顺序排布的最长子字符串
 * aeeeiiiioooauuuaeiou
 *
 * 5
 *
 * https://leetcode.cn/problems/longest-substring-of-all-vowels-in-order/solution/suo-you-yuan-yin-an-shun-xu-pai-bu-de-zu-9wqg/
 * 状态机
 */
