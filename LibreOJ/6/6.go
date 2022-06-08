package main

import "fmt"

func main() {
    var n int
    var ans [105]int

    fmt.Println("get_num")
    fmt.Scan(&n)

    for i := 0; i < n; i++ {
        l, r := 1, 1000000

        for l <= r {
            mid := (l + r) >> 1
            fmt.Println("guess", i, mid)

            var res int
            fmt.Scan(&res)

            if res == 0 {
                ans[i] = mid
                break
            } else if res > 0 {
                r = mid - 1
            } else { // res < 0
                l = mid + 1
            }
        }
    }

    fmt.Print("submit ")
    for i := 0; i < n; i++ {
        fmt.Printf("%d ", ans[i])
    }
    fmt.Printf("\n")
}
