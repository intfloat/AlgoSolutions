package main
import "fmt"

func Abs(a int) int {
    if (a < 0) {
        return -a
    } else {
        return a
    }
}

func solve() {
    var s string
    fmt.Scan(&s)
    var i, j int
    sz := len(s)
    res := 0
    for i = 0; i < sz; i++ {
        j = sz - 1 - i
        if (i >= j) {
            fmt.Println(res)
            return
        } else {
            res += Abs(int(s[i]) - int(s[j]))
        }
    }
}

func main() {
    var T int
    fmt.Scan(&T)
    for i := 0; i < T; i++ {
        solve()
    }
}
