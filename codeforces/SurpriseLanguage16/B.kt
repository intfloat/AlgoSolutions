
class Pupil(val name : String, val height : Int) : Comparable<Pupil> {
    override fun compareTo(other: Pupil): Int {
        return height - other.height
    }
}

fun main(args: Array<String>) {
    val n: Int = readLine()!!.toInt()
    var arr: List<Pupil> = java.util.ArrayList<Pupil>()
    for (i in 1..n) {
        val (name, h) = readLine()!!.split(" ")
        val height = h.toInt()
        arr = arr.plus(Pupil(name, height))
    }
    val res = arr.sorted()
    for (pupil in res) {
        println(pupil.name)
    }
}

