
fun main(args: Array<String>) {
    val q = readLine()!!.toInt()
    for (i in 1..q) {
        val (n, m, p) = readLine()!!.split(" ").map(String::toInt)
        var ok = false
        for (j in 1..n) {
            if (p % j == 0 && p / j <= m) {
                ok = true
                break
            }
        }
        if (ok) {
            println("Yes")
        }
        else {
            println("No")
        }
    }
}