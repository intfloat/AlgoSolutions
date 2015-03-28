package main

import "fmt"

func main() {
    var row, col int
    fmt.Scan(&row, &col)
    if row % 2 == 1 && col % 2 == 1 {
        fmt.Println((row * col - 1) / 2)
    } else {
        fmt.Println((row * col) / 2)
    }

}
