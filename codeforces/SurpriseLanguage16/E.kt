import java.util.*

fun main(args: Array<String>) {
    var n = readLine()!!.toInt()
    val num = readLine()!!.split(" ").map(String::toInt)
    var res: ArrayList<Int> = ArrayList<Int>()
    --n
    while (n >= 0) {
        res.add(num.get(n), n + 1)
        --n
    }
    for (i in res) {
        print(i)
        print(" ")
    }
    println()
}