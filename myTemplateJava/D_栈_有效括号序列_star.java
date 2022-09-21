package myTemplateJava;

import java.util.Scanner;
import java.util.Stack;

public class D_栈_有效括号序列_star {
  public boolean isValid(String s) {

    Stack<Integer> left = new Stack<>();
    Stack<Integer> star = new Stack<>();

    for(int i = 0; i < s.length(); i++) {
      if(s.charAt(i) == '(') {
        left.push(i);
      } else if(s.charAt(i) == '*') {
        star.push(i);
      }

      else if(s.charAt(i) == ')') {
        if(!left.empty()) left.pop();
        else if(!star.empty()) star.pop();
        else return false;
      }
    }

    while(!left.empty() && !star.empty()) {
      int leftIndex = left.pop();
      int starIndex = star.pop();

      if(leftIndex > starIndex) return false;
    }
    if(left.empty()) return true;
    else return false;
  }

  public static void main(String[] args) {

    Scanner sca = new Scanner(System.in);

  }
}

/**
 * https://www.nowcoder.com/practice/eceb50e041ec40bd93240b8b3b62d221?tpId=117&tqId=39331&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26pageSize%3D50%26search%3D17%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=17
 * 给定一个字符串s，字符串s只包含以下三种字符: (，*，)，请你判断 s是不是一个合法的括号字符串
 * "(((*)"
 *
 * false
 *
 * 新建两个栈left、star，分别记录未匹配的左括号和'*'号对应下标
 * 遍历整个字符串，如果是左括号，则将下标入left栈。如果是'*'号，则将下标入star栈。如果是右括号，先拿left栈里元素抵消，再拿star栈的元素抵消，都没有，则返回false。
 * 接着通过循环，检查未匹配的左括号和'*'号。每一个左括号都必须有一个'*'号（视为右括号）与之匹配，如果匹配不上，则返回false。
 * 最后如果left栈为空，说明左括号全部匹配上，而之前也检查了所有的右括号。所以字符串合法。
 *
 * 当栈为空时，注意异常
 */

