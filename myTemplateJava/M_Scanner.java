package myTemplateJava;

import java.util.*;

public class M_Scanner {

  public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);
    String str1 = cin.next();//cin.nextInt();

    String[] split = str1.split("],");

    String s = split[0].substring(1);
    String[] split1 = s.split(",");
    int[] num = new int[split1.length];
    for (int i = 0; i < split1.length; i++) {
      num[i] = Integer.valueOf(split1[i]);
      System.out.print(num[i] + " ");
    }

    int num2 = Integer.valueOf(split[1]);
    System.out.println(num2);

    Integer i = num2;
    System.out.println(i.toString());
  }
}

/**
 * https://blog.csdn.net/qq_34826261/article/details/97616358 //Scanner 多行输入，近似cin，只是需要自己判定nextInt()、nextLine()
 * https://blog.csdn.net/jerry11112/article/details/107003036 //Integer.valueOf()和Integer.parseInt()的区别
 * Integer.parseInt(String s)将会返回int常量。
 * Integer.valueOf(String s)将会返回Integer类型，如果存在缓存将会返回缓存中已有的对象。
 * toString() 所有类都有的方法
 * <p>
 * [1,2,3],11
 */
