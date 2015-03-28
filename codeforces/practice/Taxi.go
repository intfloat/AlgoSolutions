package main

import "fmt"

func main() {
    var N int
    fmt.Scan(&N)
    var cnt [4]int    
    for i := 0; i < N; i++ {
        var tmp int
        fmt.Scan(&tmp)
        cnt[tmp - 1]++
    }
    res := cnt[3] + cnt[2]
    cnt[0] = cnt[0] - cnt[2]
    if cnt[0] < 0 {
        cnt[0] = 0
    }
    if cnt[1] > 0 || cnt[0] > 0 {
        res = res + (cnt[1] * 2 + cnt[0] - 1) / 4 + 1
    }
    fmt.Println(res)
}
