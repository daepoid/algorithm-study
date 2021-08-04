import java.util.*

fun main(){
    val N = readLine()!!.toInt()
    val numList = mutableListOf<Int>()
    val numSet = mutableSetOf<Int>()

    val input = Scanner(System.`in`)
    for(idx in 1..N){
        val num = input.nextInt()
        numList.add(num)
        numSet.add(num)
    }
    val numSortedList = numSet.toList()

}

class Q18870 {

}