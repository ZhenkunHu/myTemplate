package myTemplateJava;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class C_排列_dfs_剪枝去重复字符串 {
  //法一：剪枝
  StringBuffer path = new StringBuffer();
  boolean[] used = new boolean[10];
  ArrayList<String> list = new ArrayList<>();

  private void dfs(char[] s) {
    if(path.length() == s.length) { //边界
      list.add(path.toString());
      return;
    }
    for(int i = 0; i < s.length; i++) { //下步
      if(!used[i]) {
        path.append(s[i]);
        used[i] = true;
        dfs(s);
        used[i] = false;
        path.deleteCharAt(path.length() - 1);
        while(i + 1 < s.length && s[i] == s[i + 1]) i++; //剪枝
      }
    }
    //返回
  }

  public String[] permutation(String S) {
    char[] chars = S.toCharArray();
    Arrays.sort(chars);
    dfs(chars);
    return list.toArray(new String[list.size()]);
  }


  /*
  //法二：使用 set 去重
  StringBuffer path = new StringBuffer();
  boolean[] used = new boolean[10];
  TreeSet<String> set = new TreeSet<>();

  private void dfs(String s) {
    if(path.length() == s.length()) {
      set.add(path.toString());
      return;
    }
    for(int i = 0; i < s.length(); i++) {
      if(!used[i]) {
        path.append(s.charAt(i));
        used[i] = true;
        dfs(s);
        used[i] = false;
        path.deleteCharAt(path.length() - 1);
      }
    }
  }

  public String[] permutation(String S) {
    dfs(S);
    String[] res = new String[set.size()];
    int tem = 0;
    for(String s : set) {
      res[tem++] = s;
    }
    return res;
  }
  */


  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    while(scanner.hasNext()) {
      String s = scanner.next();
      C_排列_dfs_剪枝去重复字符串 solution = new C_排列_dfs_剪枝去重复字符串();
      String[] res = solution.permutation(s);
      for(int i = 0; i < res.length; i++) {
        System.out.print(res[i] + " ");
      }
    }
  }
}

/**
 * https://leetcode.cn/problems/permutation-ii-lcci/
 * 排列 剪枝去重复字符串
 * qqe
 *
 * eqq qeq qqe
 *
 * 法一：剪枝
 * 法二：set去重
 *
 */

