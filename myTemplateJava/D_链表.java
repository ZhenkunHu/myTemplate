package myTemplateJava;

import ABCDEF.A1;

import java.util.Scanner;

public class D_链表 {

  public static ListNode listHead;

  public static class ListNode {
    int val;
    ListNode next;

    public ListNode(int val) {
      this.val = val;
    }

    public ListNode(int val, ListNode next) {
      this.val = val;
      this.next = next;
    }
  }

  //n > 1，不用考虑空链表
  public static void insert(int val, int node) {
    ListNode p = listHead;
    while(p.val != node) {
      p = p.next;
    }
    ListNode listNode = new ListNode(val, p.next);
    p.next = listNode;
  }

  public static void delete(int node) {
    ListNode dummy = new ListNode(0, listHead);//1. 使for循环能处理表头 2. 处理删除表头结点的情况
    ListNode p = dummy;
    while(p.next != null && p.next.val != node) {
      p = p.next;
    }
    if(p.next != null) {//如果链表中有该结点
      p.next = p.next.next;
    }
    listHead = dummy.next;//处理删除表头结点的情况
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    while (scanner.hasNextInt()) {
      Integer n = scanner.nextInt();
      listHead = new ListNode(scanner.nextInt());

      for(int i = 1; i < n; i++) {
        int val = scanner.nextInt();
        int node = scanner.nextInt();
        insert(val, node);
      }

      int val = scanner.nextInt();
      delete(val);

      ListNode p = listHead;
      while(p != null) {
        System.out.print(p.val + " ");
        p = p.next;
      }
      System.out.println();
    }
  }

}

/**
 * https://www.nowcoder.com/practice/f96cd47e812842269058d483a11ced4f?tpId=37&tqId=21271&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26pageSize%3D50%26search%3D48%26tpId%3D37%26type%3D37&difficulty=undefined&judgeStatus=undefined&tags=&title=48
 * 输入一个单向链表和一个节点的值，从单向链表中删除等于该值的节点，删除后如果链表中无节点则返回空指针。链表的值不能重复。
 * 5 2 3 2 4 3 5 2 1 4 3
 *
 * 2 5 4 1
 *
 */

