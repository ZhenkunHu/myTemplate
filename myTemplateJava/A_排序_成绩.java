package myTemplateJava;

import ABCDEF.E5;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class A_排序_成绩 {
  static class Student {
    String name;
    Integer grade;

    public String getName() {
      return name;
    }

    public void setName(String name) {
      this.name = name;
    }

    public Integer getGrade() {
      return grade;
    }

    public void setGrade(Integer grade) {
      this.grade = grade;
    }
  }

  public static void mySort(Student[] students, int way) {
    if(way == 1) {
      Arrays.sort(students, new Comparator<Student>() {
        public int compare(Student student1, Student student2) {
          return student1.getGrade() - student2.getGrade();
        }
      });
    } else if(way == 0) {
      Arrays.sort(students, new Comparator<Student>() {
        public int compare(Student student1, Student student2) {
          return student2.getGrade() - student1.getGrade();
        }
      });
    }
  }

  public static void main(String[] args) {

    Scanner sca = new Scanner(System.in);

    while (sca.hasNext()) {
      int n = sca.nextInt();
      int way = sca.nextInt();

      Student[] student = new Student[n];

      for(int i = 0; i < n; i++) {
        Student stu = new Student();
        stu.setName(sca.next());
        stu.setGrade(Integer.valueOf(sca.next()));
        student[i] = stu;
      }

      mySort(student, way);

      for(int i = 0; i < n; i++) {
        System.out.println(student[i].getName() + " " + student[i].getGrade());
      }
    }
  }
}

/**
 * https://www.nowcoder.com/practice/8e400fd9905747e4acc2aeed7240978b?tpId=37&tqId=21291&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D2%26tpId%3D37%26type%3D37&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * 给定一些同学的信息（名字，成绩）序列，请你将他们的信息按照成绩从高到低或从低到高的排列,相同成绩都按先录入排列在前的规则处理。
 * 3
 * 0
 * fang 90
 * yang 50
 * ning 70
 *
 * fang 90
 * ning 70
 * yang 50
 *
 * 输入输出框架：有n时用next，无n时用nextLine，混合使用时注意吃掉\n，尽量不要混合使用
 * Arrays.sort 和 Collections.sort应该都是稳定的
 *
 */

