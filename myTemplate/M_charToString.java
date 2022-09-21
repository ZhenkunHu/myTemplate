package myTemplate;

import java.io.IOException;

public class M_charToString {

  public static void main(String[] args) throws IOException {

    //char类型转为String
    char ch = 'c';
    String ch2Str = String.valueOf(ch);
    System.out.println(ch2Str);


    //String转为char，可以使用String类中的toCharArray()方法进行转换
    String str1 = "hello";
    char[] Str2ch1 = str1.toCharArray();//C++中的str1.c_str()
    for (char c : Str2ch1) {
      System.out.print(c + " ");
    }
    //String转化为char，法2
    String str = "abcd";
    System.out.println(str.charAt(0));
  }
}
