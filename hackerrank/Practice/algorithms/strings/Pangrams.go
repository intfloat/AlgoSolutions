package main
import "fmt"
import "bufio"
import "os"

func main() {    
    bio := bufio.NewReader(os.Stdin)
    s, _, _ := bio.ReadLine()    
    visited := make([]bool, 26)
    for i := 0; i < 26; i++ {
        visited[i] = false
    }
    for i := 0; i < len(s); i++ {
        if (s[i] != ' ') {
            c := s[i]
            var pos int
            if (c >= 'A' && c <= 'Z') {
                pos = int(c - 'A')
            } else {
                pos = int(c - 'a')
            }
            visited[pos] = true
        }
    }
    for i := 0; i < 26; i++ {
        if (!visited[i]) {
            fmt.Println("not pangram")
            return
        }
    }
    fmt.Println("pangram")
}
