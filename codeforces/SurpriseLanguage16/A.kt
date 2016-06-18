
fun main(args: Array<String>) {
    val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
    if (x > 0 && x < a && y > 0 && y < a) {
        println(0)
    }
    else if (x < 0 || x > a || y < 0 || y > a) {
        println(2)
    }
    else {
        println(1);
    }
}