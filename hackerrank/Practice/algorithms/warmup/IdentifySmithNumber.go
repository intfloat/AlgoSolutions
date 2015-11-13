package main
import "fmt"

func Count(n int) int {
    ret := 0
    for {
        if (n == 0) {
            return ret
        } else {
            ret += n % 10
            n = n / 10
        }
    }
}

func main() {
    var number int
    fmt.Scan(&number)
    t1 := Count(number)
    t2 := 0
    for i := 2; i * i <= number; i++ {
        for {
            if (number % i != 0) {
                break
            } else {
                t2 += Count(i)
                number = number / i                
            }
        }
    }
    if (number > 1) {
        t2 += Count(number)
    }
    if (t1 == t2) {
        fmt.Println(1)
    } else {
        fmt.Println(0)
    }
}
