package main

import "fmt"

func main() {
    var n, k int
    fmt.Scan(&n, &k)
    var arr [105]int
    for i := 0; i < n; i++ {
        var number int
        fmt.Scan(&number)
        arr[i] = number
        // fmt.Println(i, arr[i])
    }
    res := 0
    if arr[k - 1] > 0 {
        res = k
        for i := k; i < n; i++ {
            if arr[i] == arr[k - 1] {
                res = res + 1
            } else {
                fmt.Println(res)
                return
            }
        }
    } else {
        for i := 0; i < n; i++ {
            if arr[i] == 0 {
                fmt.Println(res)
                return
            } else {
                res = res + 1
            }
        }
    }
    fmt.Println(res)
}
