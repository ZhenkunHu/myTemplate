package myTemplateJava;

import java.util.Scanner;
import java.util.TreeMap;

public class D_TreeMap_模拟内存分配 {
  public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);
    while (scanner.hasNextLine()) {
      String[] input1 = scanner.nextLine().split(",");
      TreeMap<Integer, Integer> map = new TreeMap<>();
      for (int i = 0; i < input1.length; i++) {
        String[] str = input1[i].split(":");
        map.put(Integer.valueOf(str[0]), Integer.valueOf(str[1]));
      }

      String ans = new String();
      String[] inp = scanner.nextLine().split(",");

      for (int i = 0; i < inp.length; i++) {
        if(inp[i].equals("")) { //如果所需内存为空，不处理
          continue;
        }

        boolean flag = false;
        for (Integer integer : map.keySet()) {
          if (integer >= Integer.valueOf(inp[i]) && map.get(integer) > 0) {
            ans = ans + "true" + ",";
            map.put(integer, map.get(integer) - 1);
            flag = true;
            break;
          }
        }
        if (flag == false) ans = ans + "false" + ",";
      }
      System.out.println(ans.substring(0, ans.length() - 1));
    }
  }
}

/**
 * 华为OD机试
 * 模拟内存分配
 * 64:2,128:1,32:4,1:128
 * 50,36,64,128,127
 *
 * true,true,true,false,false
 */

