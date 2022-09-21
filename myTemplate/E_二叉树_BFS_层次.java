package myTemplate;

import java.util.*;

public class E_二叉树_BFS_层次 {
  public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
  }

  /**
   * 法一：
   * 层次遍历
   * 每次开始遍历取k = queue.size()，遍历的k个元素都是同一层
   */
  public List<List<Integer>> levelOrder(TreeNode root) {
    Queue<TreeNode> queue = new LinkedList<>();
    List<List<Integer>> lists = new ArrayList<>();

    if(root == null) return lists; //树为空时，返回的是引用

    queue.add(root);

    while(!queue.isEmpty()) {
      int size = queue.size();

      List<Integer> list = new ArrayList<>();
      for(int i = 0; i < size; i++) {
        TreeNode treeNode = queue.poll();
        list.add(treeNode.val);
        if(treeNode.left != null) queue.add(treeNode.left);
        if(treeNode.right != null) queue.add(treeNode.right);
      }
      lists.add(list);
    }
    return lists;
  }

  /**
   * 法二：
   * 利用一个指针记录一层遍历的最后一个结点
   */
  public List<List<Integer>> levelOrder2(TreeNode root) {
    List<List<Integer>> res = new ArrayList<>();
    if(root == null){
      return res;
    }
    Deque<TreeNode> queue = new LinkedList<>();
    List<Integer> list = new ArrayList<>();
    queue.add(root);
    TreeNode lastNode = root;
    while(!queue.isEmpty()){
      TreeNode cur = queue.poll();
      list.add(cur.val);
      if(cur.left != null){
        queue.add(cur.left);
      }
      if(cur.right != null){
        queue.add(cur.right);
      }
      //已经遍历完一层的最后一个节点
      if(lastNode == cur){
        res.add(list);
        lastNode = queue.peekLast(); //队尾元素
        list = new ArrayList<>(); //可重复使用list这个引用
      }
    }
    return res;
  }

}

/**
 * https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
 * [3,9,20,null,null,15,7]
 *
 * [3,9,20,15,7]
 *
 * 层次遍历
 * 利用一个指针记录一层遍历的最后一个结点
 */

