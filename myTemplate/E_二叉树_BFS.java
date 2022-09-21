package myTemplate;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class E_二叉树_BFS {
  public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
  }

  public int[] levelOrder(TreeNode root) {
    Queue<TreeNode> queue = new LinkedList<>();
    ArrayList<Integer> arrayList = new ArrayList<>();

    if(root == null) return new int[0];//树为空时，return new int[0]
    queue.add(root);
    while(!queue.isEmpty()) {
      TreeNode treeNode = queue.poll();
      arrayList.add(treeNode.val);
      if(treeNode.left != null) queue.add(treeNode.left);
      if(treeNode.right != null) queue.add(treeNode.right);
    }
    int[] ans = new int[arrayList.size()];
    for(int i = 0; i < arrayList.size(); i++)
      ans[i] = arrayList.get(i);

    return ans;
  }
}

/**
 * https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
 * [3,9,20,null,null,15,7]
 *
 * [3,9,20,15,7]
 *
 * BFS: 头 入队 出队
 *
 */
