package myTemplate;

import ABCDEF.A1;

public class D_链表_合并两个有序链表 {
  public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
      this.val = val;
    }
  }

  public ListNode Merge(ListNode list1, ListNode list2) {
    ListNode dummy = new ListNode(-1);
    ListNode p = dummy;
    // 必须保证两个list都不为空
    while(list1 != null & list2 != null) {
      if(list1.val > list2.val) {
        p.next = list2;
        list2 = list2.next;
      } else if(list1.val <= list2.val) {
        p.next = list1;
        list1 = list1.next;
      }
      p = p.next;
    }
    // list1后面还有，就把剩下的全部拿走
    if(list1 != null) {
      p.next = list1;
    }
    if(list2 != null) {
      p.next = list2;
    }
    return dummy.next;
  }
}

/**
 * https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=23267&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 * 输入两个递增的链表，单个链表的长度为n，合并这两个链表并使新链表中的节点仍然是递增排序的。
 * {1,3,5},{2,4,6}
 *
 * {1,2,3,4,5,6}
 *
 * 虚拟结点，哨兵结点
 */

