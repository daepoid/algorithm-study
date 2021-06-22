import java.util.*
import kotlin.math.*

class Q1977 {}

fun main() {
    val input: Scanner = Scanner(System.`in`)
    var M: Int = input.nextInt()
    var N: Int = input.nextInt()
    var sum: Int = 0
    var min_num: Int = 20000

    if (M > N){
        M = N.also {N = M}
    }

    val numList: MutableList<Int> = mutableListOf<Int>()

    for(i: Int in 0..100){
        numList.add(i * i)
    }

    for(i: Int in 0..100){
        if(numList[i] in M..N){
            sum += numList[i]
            min_num = min(min_num, numList[i])
        }
    }

    if(sum == 0) {
        println(-1)
    } else {
        println("$sum\n$min_num")
    }
}