package myTemplate;

import java.util.Scanner;
import java.util.Stack;

public class D_栈_有效括号序列 {
  public boolean isValid1(String s) {
    //辅助栈
    Stack<Character> stack = new Stack<>();

    for(int i = 0; i < s.length(); i++) {
      if(s.charAt(i) == '(') stack.push(s.charAt(i));
      else if(s.charAt(i) == '[') stack.push(s.charAt(i));
      else if(s.charAt(i) == '{') stack.push((s.charAt(i)));
      else if(s.charAt(i) == ')') {
        if(stack.empty()) return false;
        else if(stack.peek() == '(') stack.pop();
        else return false;
      } else if(s.charAt(i) == ']') {
        if(stack.empty()) return false;
        else if(stack.peek() == '[') stack.pop();
        else return false;
      } else if(s.charAt(i) == '}') {
        if(stack.empty()) return false;
        else if(stack.peek() == '{') stack.pop();
        else return false;
      }
    }
    if(stack.empty()) return true;
    else return false;
  }

  public boolean isValid2(String s) {
    //辅助栈
    Stack<Character> st = new Stack<Character>();
    //遍历字符串
    for(int i = 0; i < s.length(); i++){
      //遇到左小括号
      if(s.charAt(i) == '(')
        //期待遇到右小括号
        st.push(')');
        //遇到左中括号
      else if(s.charAt(i) == '[')
        //期待遇到右中括号
        st.push(']');
        //遇到左大括号
      else if(s.charAt(i) == '{')
        //期待遇到右大括号
        st.push('}');
        //必须有左括号的情况下才能遇到右括号
      else if(st.isEmpty() || st.pop() != s.charAt(i))
        return false;
    }
    //栈中是否还有元素
    return st.isEmpty();
  }


  public static void main(String[] args) {

    Scanner sca = new Scanner(System.in);

    while (sca.hasNext()) {

    }
  }
}

/**
 * https://www.nowcoder.com/practice/37548e94a270412c8b9fb85643c8ccc2?tpId=117&tqId=37749&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26pageSize%3D50%26search%3DNC52%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=NC52
 * 给出一个仅包含字符'(',')','{','}','['和']',的字符串，判断给出的字符串是否是合法的括号序列
 * 括号必须以正确的顺序关闭，"()"和"()[]{}"都是合法的括号序列，但"(]"和"([)]"不合法。
 * "()[]{}"
 *
 * true
 *
 * step 1：创建辅助栈，遍历字符串。
 * step 2：每次遇到小括号的左括号、中括号的左括号、大括号的左括号，就将其对应的呦括号加入栈中，期待在后续遇到。
 * step 3：如果没有遇到左括号但是栈为空，说明直接遇到了右括号，不合法。
 * step 4：其他情况下，如果遇到右括号，刚好会与栈顶元素相同，弹出栈顶元素继续遍历。
 * step 5：理论上，只要括号是匹配的，栈中元素最后是为空的，因此检查栈是否为空即可最后判断是否合法。
 *
 *
 */

