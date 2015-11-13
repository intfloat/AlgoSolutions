package main

import "fmt"

func main() {
    var T int
    fmt.Scan(&T)
    var N int64
    for i := 0; i < T; i++ {
        fmt.Scan(&N)
        prev, cur, ok := int64(1), int64(1), false
        for {
            if N == cur {
                ok = true
                break
            } else if N < cur {
                break
            } else {
                t := cur
                cur = prev + cur
                prev = t
            }
        }
        if ok {
            fmt.Println("IsFibo")
        } else {
            fmt.Println("IsNotFibo")
        }
    }
}
