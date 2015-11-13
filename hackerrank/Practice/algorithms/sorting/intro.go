package main
import "fmt"

func main() {
    var value, N int
    fmt.Scan(&value, &N)    
    arr := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Scan(&arr[i])
    }
    for idx, v := range arr {
        if (v == value) {
            fmt.Println(idx)
            return
        }
    }
}
