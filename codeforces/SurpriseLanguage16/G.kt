
fun gcd(a: Long, b: Long): Long {
    if (b == 0L) {
        return a
    } else {
        return gcd(b, a % b)
    }
}

fun main(args: Array<String>) {
    val (c1, c2) = readLine()!!.split("(")
    var x1 = c1.substring(2, c1.length)
    var x2 = c2.substring(0, c2.length - 1)
    val a = x1.length
    val b = x2.length
    var pa = 1
    for (i in 1..a) pa *= 10
    var pb = 1
    for (i in 1..b) pb *= 10
    val num1 = if (x1.isEmpty()) 0L else x1.toLong();
    val num2 = x2.toLong()
    var num = num2 + num1 * (pb - 1L)
    var den = pa * (pb - 1L)
    val g = gcd(num, den * 1L)
    num = num / g
    den = den / g
    print(num)
    print("/")
    println(den)
}