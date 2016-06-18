
fun main(args: Array<String>) {
    var s: String = readLine()!!.trim()
    var r = ""
    for (i in 0..s.length - 1) {
        // remove consecutive spaces
        if (s.get(i) == ' ' && r.length > 0 && r.last() == ' ') {
            continue
        }
        // add space after comma or period
        else if (s.get(i) != ' ' && r.length > 0 && (r.last() == ',' || r.last() == '.')) {
            r += " "
            r += s.get(i)
        }
        else {
            r += s.get(i)
        }
    }
    var res = ""
    for (i in 0..r.length - 1) {
        // remove space before any comma or period
        if (r.get(i) == ' ' && (i + 1) < r.length && (r.get(i + 1) == ',' || r.get(i + 1) == '.')) {
            continue
        }
        else if (i == 0 || (i - 2 >= 0 && r.get(i - 2) == '.')) {
            res += r.get(i).toUpperCase()
        }
        else {
            res += r.get(i).toLowerCase()
        }
    }
    println(res)
}