package main
import "fmt"

func main() {
    var N int
    fmt.Scan(&N)
    arr := make([]int, N)
    res := 0
    for i := 0; i < N; i++ {
        fmt.Scan(&arr[i])
        res = res ^ arr[i]
    }
    fmt.Println(res)
}
