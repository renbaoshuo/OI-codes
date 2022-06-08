package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)

    var ans int64 = 0

    for scanner.Scan() {
        x, _ := strconv.ParseInt(scanner.Text(), 10, 64)

        ans ^= x
    }

    fmt.Println(ans)
}
