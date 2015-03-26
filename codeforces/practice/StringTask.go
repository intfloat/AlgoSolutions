package main

import "fmt"
import "strings"

func main() {
    var s string
    fmt.Scan(&s)
    s = strings.ToLower(s)
    for i, c := range s {
        if c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i' {
            continue
        } else {
            fmt.Print("." + s[i : i + 1])
        }
    }
    fmt.Println()
}
