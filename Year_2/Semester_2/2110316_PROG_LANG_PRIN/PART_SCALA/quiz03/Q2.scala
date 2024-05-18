package quiz03

import scala.annotation.tailrec

object Q2 {
  var score = 0;
  
  def replaceData(l:List[Int], pos:Int, data:Int):List[Int] = {
    //Assume the list l is never empty
    //pos is assumed to indicate correct position in the list (never go outside possible values)
    if(pos == 0) return data :: l.tail
    List(l.head) ++ replaceData(l.tail, pos-1, data)
  }

  def getMember(l:List[Int], pos:Int): Int = {
    if(pos == 0) l.head
    else getMember(l.tail, pos-1)
  }

  def updateFreq(l: List[Int], freqList:List[Int]):List[Int] ={
    if(l.isEmpty) return freqList
    val cur = l.head
    val newFreqList = replaceData(freqList, cur, getMember(freqList, cur)+1)
    updateFreq(l.tail, newFreqList)
  }



  def testReplace01(): Unit = {
    val l1 = List(6)
    val result = replaceData(l1,0,2)
    if(result.head == 2) score = score +1;
  }

  def testReplace02(): Unit = {
    val l1 = List(1,2,3,4,5)
    var result = replaceData(l1,1,9)
    result = replaceData(result,3,11)
    result = replaceData(result,4,15)

    if(result(0) == 1 && result(1) == 9 && result(2) ==3) score = score +1;
    if(result(3) == 11 && result(4) == 15 ) score = score +1;
  }

  def testUpdateFreq01():Unit ={
    val freqList = List(0,0,0,0,0)
    var l = List()
    if(updateFreq(l,freqList) == freqList) score = score +1
  }

  def testUpdateFreq02():Unit ={
    val freqList = List(0,0,0,0,0)
    var l = List(4,3,2,3,4,0,3)
    var result = updateFreq(l,freqList)
    if(result(0) == 1) score = score +1;
    if(result(1) == 0) score = score +1;
    if(result(2) == 1) score = score +1;
    if(result(3) == 3) score = score +1;
    if(result(4) == 2) score = score +1;
  }

  def testUpdateFreq03():Unit ={
    val freqList = List(1,0,0,2)
    var l = List(3,3,0,3)
    var result = updateFreq(l,freqList)
    if(result(0) == 2 && result(3) == 5 ) score = score +1;
  }

  def main(args: Array[String]): Unit = {
    testReplace01();
    testReplace02();
    testUpdateFreq01();
    testUpdateFreq02();
    testUpdateFreq03();

     print(score)
  }
}
