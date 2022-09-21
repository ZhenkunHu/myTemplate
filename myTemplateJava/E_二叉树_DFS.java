package myTemplateJava;

public class E_二叉树_DFS {
  public static class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
  }

  public static void preOrder(TreeNode p) {
    if(p != null) {
      System.out.print(p.val + " ");
      preOrder(p.left);
      preOrder(p.right);
    }
  }

  public static void inOrder(TreeNode p) {
    if(p != null) {
      inOrder(p.left);
      System.out.print(p.val + " ");
      inOrder(p.right);
    }
  }

  public static void postOrder(TreeNode p) {
    if(p != null) {
      postOrder(p.left);
      postOrder(p.right);
      System.out.print(p.val + " ");
    }
  }

  public static void main(String[] args) {
    TreeNode treeNode0 = new TreeNode(0);
    TreeNode treeNode1 = new TreeNode(1);
    treeNode0.left = treeNode1;
    TreeNode treeNode2 = new TreeNode(2);
    treeNode0.right = treeNode2;
    TreeNode treeNode5 = new TreeNode(5);
    treeNode2.left = treeNode5;
    TreeNode treeNode6 = new TreeNode(6);
    treeNode2.right = treeNode6;

    preOrder(treeNode0);
    System.out.println();

    inOrder(treeNode0);
    System.out.println();

    postOrder(treeNode0);
    System.out.println();
  }
}

/**
 * [0,1,2,null,null,5,6]
 *
 * 0 1 2 5 6
 * 1 0 5 2 6
 * 1 5 6 2 0
 *
 * 深度优先遍历
 */

