package quiz01

import scala.annotation.tailrec

object Q1 {

  @tailrec
  def split(l: List[Int], leftSize:Int, isLeft:Boolean=true, lst:List[Int]=Nil): List[Int] = {
    if(leftSize == 0) {
      if(isLeft) lst
      else l
    }
    else if(isLeft)
       split(l.tail, leftSize-1, isLeft, lst ++ List(l.head) )
    else split(l.tail, leftSize-1, isLeft, lst)
  }

  @tailrec
  def merge(left:List[Int], right:List[Int], ans:List[Int] = Nil): List[Int] = {
      if(left.isEmpty || right.isEmpty)  ans ++ right ++ left
      else if(left.head < right.head) merge(left.tail, right, ans ++ List(left.head))
      else merge(left, right.tail, ans ++ List(right.head))
  }

  def mergeSort(l:List[Int]): List[Int] = {
    if(l.isEmpty) return Nil
    if(l.length == 1) return l

    val size = l.length / 2
    val left = split(l, size)
    val right = split(l, size, false)

    val sortedLeft = mergeSort(left)
    val sortedRight = mergeSort(right)

    merge(sortedLeft, sortedRight)
  }

  def sortTwoLists(l1:List[Int],l2:List[Int]): (List[Int],List[Int]) = {
    val sortedList = mergeSort(l1 ++ l2);
    (split(sortedList, l1.length), split(sortedList, l1.length, false))
  }

  def main(args: Array[String]): Unit = {
    val l1= List(9,1,6,4,3)
    val l2 = List(0,8,7,2,5)
    println(Q1.sortTwoLists(l1,l2) == (List(0,1,2,3,4),List(5,6,7,8,9)))

    val l3 = List()
    val l4 = List(5,2,8,1,3,6)
    println(Q1.sortTwoLists(l3,l4) == (List(),List(1,2,3,5,6,8)))

    val l5 = List(5,2,4)
    val l6 = List(7,8,9,1,2,3,5)
    println(Q1.sortTwoLists(l5,l6) == (List(1,2,2),List(3,4,5,5,7,8,9)))

    val l7 = List(7, 8, 7, 1, 4, 3, 5, 2)
    val l8 = List(5, 1, 8, 6)
    println(Q1.sortTwoLists(l7, l8) == (List(1,1,2,3,4,5,5,6), List(7,7,8,8)))

    val l9 = List()
    val l10 = List()
    println(Q1.sortTwoLists(l9, l10) == (Nil, Nil))
  }
}
