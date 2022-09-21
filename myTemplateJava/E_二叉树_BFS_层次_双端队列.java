package myTemplateJava;

import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class E_二叉树_BFS_层次_双端队列 {
  public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
  }

  public List<List<Integer>> levelOrder(TreeNode root) {
    Queue<TreeNode> queue = new LinkedList<>(); //ArrayDeque<>(); 也行
    List<List<Integer>> lists = new LinkedList<>();

    if(root == null) return lists; //树为空时，返回的是引用


    queue.add(root);
    Boolean isOrderLeft = true;

    while(!queue.isEmpty()) {
      int size = queue.size();
      Deque<Integer> list = new LinkedList<>();
      for(int i = 0; i < size; i++) {
        TreeNode treeNode = queue.poll();
        if(isOrderLeft) list.addLast(treeNode.val);
        else list.addFirst(treeNode.val);

        if(treeNode.left != null) queue.add(treeNode.left);
        if(treeNode.right != null) queue.add(treeNode.right);
      }
      lists.add(new LinkedList<Integer>(list)); //双端队列强制类型转换为链表
      isOrderLeft = !isOrderLeft;
    }
    return lists;
  }
}

/**
 * https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
 * [3,9,20,null,null,15,7]
 *
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 *
 * 层次遍历
 * 使用双端队列存储遍历的结点
 */

