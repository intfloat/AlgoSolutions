import java.util.*

fun main(args: Array<String>) {
    var arr1: List<Int> = readLine()!!.split(" ").map(String::toInt)
    var arr2: List<Int> = readLine()!!.split(" ").map(String::toInt)
    arr1 = arr1.subList(1, arr1.size)
    arr2 = arr2.subList(1, arr2.size)
    var res: List<Int> = ArrayList<Int>()
    for (i in 0..arr1.size - 1) {
        if (arr2.indexOf(arr1.get(i)) < 0) {
            res = res.plus(arr1.get(i))
        }
    }
    for (i in 0..arr2.size - 1) {
        if (arr1.indexOf(arr2.get(i)) < 0) {
            res = res.plus(arr2.get(i))
        }
    }
    print(res.size)
    for (num in res) {
        print(" ")
        print(num)
    }
    println()
}