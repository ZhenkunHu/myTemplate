package myTemplate;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Interval {
   int start;
   int end;
   Interval() { start = 0; end = 0; }
   Interval(int s, int e) { start = s; end = e; }
 }

public class A_贪心_模拟 {

  public ArrayList<Interval> merge(ArrayList<Interval> intervals) {
    Collections.sort(intervals, new Comparator<Interval>() {
      public int compare(Interval i, Interval j) {
        return i.start - j.start;
      }
    });

    ArrayList<Interval> intervalList = new ArrayList<>();
    //特殊情况，ArrayList.size() == 0;
    if(intervals.size() == 0) return intervalList;

    int left = 0, right = 0;
    left = intervals.get(0).start;
    right = intervals.get(0).end;
    for(int i = 0; i < intervals.size() - 1; i++) {
      if(right >= intervals.get(i +1).start) {
        right = Math.max(right, intervals.get(i +1).end);
      } else {
        Interval interval = new Interval(left, right);
        intervalList.add(interval);
        left = intervals.get(i + 1).start;
        right = intervals.get(i + 1).end;
      }
    }
    Interval interval = new Interval(left, right);
    intervalList.add(interval);
    return intervalList;
  }
}

/**
 * https://www.nowcoder.com/practice/69f4e5b7ad284a478777cb2a17fb5e6a?tpId=117&tqId=37737&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26pageSize%3D50%26search%3D%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * 给出一组区间，请合并所有重叠的区间。
 * 请保证合并后的区间按区间起点升序排列。
 * [[10,30],[20,60],[80,100],[150,180]]
 *
 * [[10,60],[80,100],[150,180]]
 *
 * 当 ArrayList.size() == 0; ArrayList.get(0) 报错
 * 预处理 循环（防止数组越界） 后处理
 *
 */