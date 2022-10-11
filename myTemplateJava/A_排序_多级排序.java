package myTemplateJava;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class A_排序_多级排序 {
  static class Node {
    char c;
    int[] grade;

    public Node(char c, int[] grade) {
      this.c = c;
      this.grade = grade;
    }
  }

  public static String getFinalRanking(String[] rankings) {
    // 初始化
    Node[] nodes = new Node[rankings[0].length()];
    for (int i = 0; i < rankings[0].length(); i++) {
      int[] grade = new int[rankings[0].length()];
      // 默认值为0
      Node node = new Node(rankings[0].charAt(i), grade);
      nodes[i] = node;
    }

    // 赋值
    for (int i = 0; i < rankings.length; i++) {
      for (int j = 0; j < rankings[i].length(); j++) {
        for (int k = 0; k < rankings[i].length(); k++) {
          if (nodes[k].c == rankings[i].charAt(j)) {
            nodes[k].grade[j]++;
          }
        }
      }
    }

    // 多级比较
    Arrays.sort(nodes, new Comparator<Node>() {
      @Override
      public int compare(Node o1, Node o2) {
        for (int i = 0; i < o2.grade.length; i++) {
          if(o1.grade[i] != o2.grade[i]) {
            return o2.grade[i] - o1.grade[i];
          }
        }
        return o1.c - o2.c;
      }
    });

    StringBuilder sb = new StringBuilder();
    for (int k = 0; k < nodes.length; k++) {
      sb.append(nodes[k].c);
    }

    return new String(sb);
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    String[] rankings = {"XFV", "XVF", "XFV", "XVF", "XVF"};
    System.out.println(getFinalRanking(rankings));
  }
}
