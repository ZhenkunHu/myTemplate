package myTemplateJava;

import java.util.Scanner;
import java.util.Stack;

public class D_栈_矩阵运算 {
  public static void main(String[] args) {

    Scanner sca = new Scanner(System.in);
    while(sca.hasNextInt()) {
      int n = sca.nextInt();
      int[][] matrices = new int[n][2];
      for(int i = 0; i < n; i++) {
        matrices[i][0] = sca.nextInt();
        matrices[i][1] = sca.nextInt();
      }

      String way = sca.next();
      Stack<Integer> stack = new Stack<>();

      int count = 0;

      for(Character c : way.toCharArray()) {
        if(c == '(') continue;
        else if(c == ')') {
          int clo2 = stack.pop();
          int row2 = stack.pop();
          int clo1 = stack.pop();
          int row1 = stack.pop();
          count += row1 * clo1 * clo2;
          stack.push(row1);
          stack.push(clo2);
        } else {
          stack.push(matrices[c - 'A'][0]);
          stack.push(matrices[c - 'A'][1]);
        }
      }
      System.out.println(count);
    }
  }
}

/**
 * https://www.nowcoder.com/practice/15e41630514445719a942e004edc0a5b?tpId=37&tqId=21293&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D2%26tpId%3D37%26type%3D37&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * 矩阵乘法的运算量与矩阵乘法的顺序强相关。
 * 3
 * 50 10
 * 10 20
 * 20 5
 * (A(BC))
 *
 * 3500
 *
 * 保证给出的字符串表示的计算顺序唯一，所以不存在ABC这种序列
 *
 */

