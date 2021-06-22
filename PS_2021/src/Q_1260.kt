import java.util.*

class Q_1260 {
}

fun createBoard(row: Int, col: Int):Array<Array<Boolean>> = Array<Array<Boolean>>(row, {Array<Boolean>(col, {i -> false})})

fun main() {
    val input: Scanner = Scanner(System.`in`)
    val N: Int = input.nextInt()
    val M: Int = input.nextInt()
    val V: Int = input.nextInt()

    var graph: Array<Array<Boolean>> = createBoard(1001, 1001)
    var check: Array<Boolean> = Array<Boolean>(1001) { it -> false }

    for(T: Int in 0..M){
        val a: Int = input.nextInt()
        val b: Int = input.nextInt()

        graph[a][b] = true
        graph[b][a] = true
    }

    fun dfs(num: Int, N: Int){
        println("$num ")
        check[num] = true

        for(i: Int in 1..N){
            if(graph[num][i] && !check[i]){
                dfs(i, N)
            }
        }
    }

    fun bfs(start: Int, N: Int){
        var queue: Queue<Int> = LinkedList<Int>()
        check[start] = true
        while(!queue.isEmpty()) {
            val temp: Int = queue.peek()
            println("$temp ")
            queue.poll()
            for(i: Int in 1..N){
                if(graph[temp][i] && !check[i]) {
                    queue.add(i)
                    check[i] = true
                }
            }
        }
    }

    dfs(V, N)
    bfs(V, N)
}