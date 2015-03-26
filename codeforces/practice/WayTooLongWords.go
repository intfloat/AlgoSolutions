package main

import "fmt"

func main() {
    var str string
    var total int
    fmt.Scan(&total)
    for i := 0; i < total; i++ {
        fmt.Scan(&str)
        if len(str) <= 10 {
            fmt.Println(str)
        } else {            
            fmt.Print(str[0:1])
            fmt.Print(len(str) - 2)
            fmt.Println(str[len(str) - 1:len(str)])
        }
    }    
}
