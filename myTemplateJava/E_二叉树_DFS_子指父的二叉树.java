package myTemplateJava;

import java.util.Scanner;

public class E_二叉树_DFS_子指父的二叉树 {
  static class TreeNode {
    char val;
    TreeNode left;
    TreeNode right;
    TreeNode parent;

    public TreeNode() {
    }

    public TreeNode(char val) {
      this.val = val;
    }
  }

  public static void dfs(TreeNode node) {
    if(node != null) {
      dfs(node.left);
      System.out.print(node.val);
      dfs(node.right);
    }
  }

  public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);
    while (scanner.hasNextLine()) {
      String input = scanner.nextLine();
      TreeNode root = new TreeNode(input.charAt(0));
      TreeNode temp = new TreeNode();
      temp = root;

      //只有一个结点时
      if(input.length() == 1) {
        System.out.println(input);
        break;
      }

      for(int i = 1; i < input.length() - 1; i++) { //结点超过1的树，最后一个结点一定是'}'
        if(input.charAt(i) == '{') {
          if(input.charAt(i + 1) >= 'A' && input.charAt(i + 1) <= 'z') {
            TreeNode left = new TreeNode(input.charAt(i + 1));
            temp.left = left;
            left.parent = temp;
            temp = left;
            i++;
          } else { // 建立假结点，方便','的统一处理
            TreeNode left = new TreeNode('0');
            left.parent = temp;
            temp = left;
          }
        } else if(input.charAt(i) == ',') {
          if(input.charAt(i + 1) >= 'A' && input.charAt(i + 1) <= 'z') {
            TreeNode right = new TreeNode(input.charAt(i + 1));
            temp = temp.parent;
            temp.right = right;
            right.parent = temp;
            temp = right;
            i++;
          }
        } else if(input.charAt(i) == '}') {
          temp = temp.parent;
        }
      }
      dfs(root);
    }
  }

}

/**
 * 华为OD机试
 * 树的中序遍历
 * a{b{d,e{g,h{,i}}},c{f}}
 *
 * dbgehiafc
 *
 *
 */

