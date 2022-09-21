package myTemplate;

import java.util.ArrayList;
import java.util.Scanner;

public class C_排列_dfs {
  StringBuffer path = new StringBuffer();
  boolean[] used = new boolean[10];
  ArrayList<String> list = new ArrayList<>();

  private void dfs(String s) {
    if(path.length() == s.length()) { //边界
      list.add(path.toString());
      return;
    }
    for(int i = 0; i < s.length(); i++) { //下步
      if(!used[i]) {
        path.append(s.charAt(i));
        used[i] = true;
        dfs(s);
        used[i] = false;
        path.deleteCharAt(path.length() - 1);
      }
    }
    //返回
  }

  public String[] permutation(String S) {
    dfs(S);
    String[] res = new String[list.size()];
    for(int i = 0; i < list.size(); i++) {
      res[i] = list.get(i);
    }
    return res;
  }


  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    while(scanner.hasNext()) {
      String s = scanner.next();
      C_排列_dfs solution = new C_排列_dfs();
      String[] res = solution.permutation(s);
      for(int i = 0; i < res.length; i++) {
        System.out.print(res[i] + " ");
      }
    }
  }
}

/**
 * https://leetcode.cn/problems/permutation-i-lcci/
 * 排列
 * qwe
 *
 * qwe qew wqe weq eqw ewq
 *
 * 深度优先搜索，从逻辑（数学归纳法、循环不变式）、物理（调用栈、解答树）角度理解
 */

