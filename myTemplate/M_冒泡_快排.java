package myTemplate;

import java.io.IOException;
import java.util.Scanner;

public class M_冒泡_快排 {

  public static void bubleSort(int[] num, int n) {
    for (int i = 0; i < n - 1; i++) {
      Boolean flag = false;
      for (int j = n - 1; j > i; j--) {
        if (num[j - 1] > num[j]) {
          int tem = num[j - 1];
          num[j - 1] = num[j];
          num[j] = tem;
          flag = true;
        }
      }
      if (flag == false) break;
    }
  }

  public static void main(String[] args) throws IOException {
    int[] a = new int[10]; //Java中数组是对象
    Scanner cin = new Scanner(System.in);
    for (int i = 0; i < 10; i++) {
      a[i] = cin.nextInt();
    }

    sort(a, 0, 9);

    for (int i = 0; i < 10; i++)
      System.out.print(a[i] + " ");
  }

  public static int partition(int[] num, int left, int right) {
    int pivot = num[left];
    while (left < right) {
      while (left < right && num[right] >= pivot) right--;
      num[left] = num[right];

      while (left < right && num[left] <= pivot) left++;
      num[right] = num[left];
    }
    num[left] = pivot; //交换完成
    return left;
  }

  public static void sort(int[] num, int left, int right) {
    if (left < right) {
      int pivotPos = partition(num, left, right); //先排一次，返回新基准
      sort(num, left, pivotPos - 1);
      sort(num, pivotPos + 1, right);
    }
  }
}
