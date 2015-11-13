package main
import "fmt"

func Reverse(s string) string {
    n := len(s)
    runes := make([]rune, n)
    for _, rune := range s {
        n--
        runes[n] = rune
    }    
    return string(runes)
}

func Abs(a int) int {
    if (a < 0) {
        return -a
    } 
    return a
}

func main() {
    var T int
    fmt.Scan(&T)
    for i := 0; i < T; i++ {
        var s string
        fmt.Scan(&s)
        rs := Reverse(s)        
        ok := true
        for j := 1; j < len(s); j++ {
            if (Abs(int(s[j]) - int(s[j - 1])) != Abs(int(rs[j]) - int(rs[j - 1]))) {
                ok = false
                break
            }
        }
        if (ok == true) {
            fmt.Println("Funny")
        } else {
            fmt.Println("Not Funny")
        }
    }
}
