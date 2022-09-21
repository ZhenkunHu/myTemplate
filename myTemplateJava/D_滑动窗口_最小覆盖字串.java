package myTemplateJava;

import java.util.HashMap;

public class D_滑动窗口_最小覆盖字串 {

  //HashMap中有 - 1，说明不满足要求
  public Boolean check1(HashMap<Character, Integer> hash) {
    for(Character c : hash.keySet()) {
      if(hash.get(c) < 0) return false;
    }
    return true;
  }

  public String minWindow1 (String S, String T) {
    HashMap<Character, Integer> map = new HashMap<>();

    //初始化
    for(int i = 0; i < T.length(); i++) {
      map.put(T.charAt(i), map.getOrDefault(T.charAt(i), 0) - 1);
    }

    int slow = 0, fast = 0;
    int cnt = S.length() + 1;
    int left = - 1, right = - 1;
    for(; fast < S.length(); fast++) {
      if(T.contains("" + S.charAt(fast))) map.put(S.charAt(fast), map.get(S.charAt(fast)) + 1);

      while(check1(map)) {
        if(cnt > fast - slow + 1) {
          cnt = fast - slow + 1;
          left = slow;
          right = fast;
        }
        if(T.contains("" + S.charAt(slow))) map.put(S.charAt(slow), map.get(S.charAt(slow)) - 1);
        slow++;
      }
    }

    if(left == -1) {
      return "";
    }
    return S.substring(left, right + 1);
  }


  //检查是否有小于0的
  boolean check2(int[] hash) {
    for (int i = 0; i < hash.length; i++) {
      if (hash[i] < 0)
        return false;
    }
    return true;
  };

  public String minWindow2 (String S, String T) {
    int cnt = S.length() + 1;
    //记录目标字符串T的字符个数
    int[] hash = new int[128];
    for(int i = 0; i < T.length(); i++)
      //初始化哈希表都为负数，找的时候再加为正
      hash[T.charAt(i)] -= 1;
    int slow = 0, fast = 0;
    //记录左右区间
    int left = -1, right = -1;
    for(; fast < S.length(); fast++){
      char c = S.charAt(fast);
      //目标字符匹配+1
      hash[c]++;
      //没有小于0的说明都覆盖了，缩小窗口
      while(check2(hash)){
        //取最优解
        if(cnt > fast - slow + 1){
          cnt = fast - slow + 1;
          left = slow;
          right = fast;
        }
        c = S.charAt(slow);
        //缩小窗口的时候减1
        hash[c]--;
        //窗口缩小
        slow++;
      }
    }
    //找不到的情况
    if(left == -1)
      return "";
    return S.substring(left, right + 1);
  }


  public static void main(String[] args) {

  }
}

/**
 * https://www.nowcoder.com/practice/c466d480d20c4c7c9d322d12ca7955ac?tpId=117&tqId=37732&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26pageSize%3D50%26search%3D28%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=28
 * 给出两个字符串 s 和 t，要求在 s 中找出最短的包含 t 中所有字符的连续子串。
 * "XDOYEZODEYXNZ","XYZ"
 *
 * "YXNZ"
 *
 * 知识点1：滑动窗口
 * 滑动窗口是指在数组、字符串、链表等线性结构上的一段，类似一个窗口，而这个窗口可以依次在上述线性结构上从头到尾滑动，且窗口的首尾可以收缩。我们在处理滑动窗口的时候，常用双指针来解决，左指针维护窗口左界，右指针维护窗口右界，二者同方向不同速率移动维持窗口。
 * 知识点2：哈希表
 * 哈希表是一种根据关键码（key）直接访问值（value）的一种数据结构。而这种直接访问意味着只要知道key就能在O(1)O(1)O(1)时间内得到value，因此哈希表常用来统计频率、快速检验某个元素是否出现过等。
 *
 */

