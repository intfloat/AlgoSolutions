package main

import "fmt"

func main() {
    var N, t int
    fmt.Scan(&N)
    res := 0
    for i := 0; i < N; i++ {
        val := 0
        for friend := 0; friend < 3; friend++ {            
            fmt.Scan(&t)
            val += t
        }
        if val >= 2 {
            res += 1
        }
    }    
    fmt.Println(res)
}
