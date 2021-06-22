import java.util.*
import kotlin.math.*

fun main() {
    val input: Scanner = Scanner(System.`in`)
    var M: Int = input.nextInt()
    var N: Int = input.nextInt()
    var sum: Int = 0
    var min_num: Int = 20000

    if (M > N){
        M = N.also {N = M}
    }

    var numList: MutableList<Int> = mutableListOf<Int>()
    
    for(i: Int in 0..100){
        numList.add(i * i)
    }

    for(i: Int in 0..100){
        if(M <= numList[i] && numList[i] <= N){
            sum += numList[i]
            min_num = min(min_num, numList[i])
        }
    }

    if(sum == 0) {
        println(-1)
    } else {
        println("$sum $min_num")
    }
}