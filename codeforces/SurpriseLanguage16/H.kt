import java.util.*

fun main(args: Array<String>) {
    val (n, k) = readLine()!!.split(" ").map(String::toLong)
    val arr = readLine()!!.split(" ").map(String::toInt).map { e -> e - 1 }
    var visited: MutableList<Int> = (1..n).map { e -> -1 }.toMutableList()

    for (i in 0..n.toInt() - 1) {
        if (visited[i] >= 0) {
            continue
        }
        var ptr = i
        var cur = ArrayList<Int>()
        while (visited[ptr] < 0) {
            visited[ptr] = 0
            cur.add(ptr)
            ptr = arr[ptr]
        }
        val rem = k % cur.size
        for (j in 0..cur.size - 1) {
            visited[cur[j]] = cur[(j - rem.toInt() + cur.size) % cur.size]
        }
    }
    for (rr in visited) {
        print(rr + 1)
        print(" ")
    }
    println()
}