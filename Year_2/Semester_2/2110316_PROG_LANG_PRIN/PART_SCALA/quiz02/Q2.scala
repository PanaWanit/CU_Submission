package quiz02

import scala.annotation.tailrec

object Q2 {

  @tailrec
  def member(x:Any, l: List[Any]): Boolean = {
    if(l.isEmpty) return false
    if(x == l.head) return true
    member(x, l.tail)
  }

  @tailrec
  def difference(l1: List[Any], l2: List[Any], ans: List[Any]=Nil): List[Any] = {
    if(l1.isEmpty) return ans
    if(! member(l1.head, l2) )
      difference(l1.tail, l2, ans ++ List(l1.head) )
    else difference(l1.tail, l2, ans)
  }

  def test01(): Unit = {
    var score = 0;
    val l1 = List(6, 2, 4, 3, 1, 7)
    val l2 = List(10, 2, 6, 3, 8, 4)
    val l3 = List("a", "b", "c")
    val l4 = List("c", "d", "b", "e")

    if (difference(List(), l2) == List()) score += 1;
    if (difference(l1, List()) == List(6, 2, 4, 3, 1, 7)) score += 1;
    if (difference(l1, l2) == List(1, 7)) score += 2
    if (difference(l3, l4) == List("a")) score += 2
    if (difference(l2, l1) == List(10, 8)) score += 2
    if (difference(l4, l3) == List("d", "e")) score += 2

    println("Score = " + score)

  }

  def main(args: Array[String]): Unit = {
    test01();
  }
}
