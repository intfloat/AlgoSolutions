package main

import "fmt"

func main() {
    var row, col, a int64
    fmt.Scanf("%d %d %d", &row, &col, &a)
    res := (row - 1) / a + 1
    res = res * ((col - 1) / a + 1)
    fmt.Println(res)    
}
