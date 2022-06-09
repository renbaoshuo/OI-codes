package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

const mod = 998244353

var fa [4000005]int

func main() {
    scanner := bufio.NewScanner(os.Stdin)

    scanner.Scan()
    raw := strings.Split(scanner.Text(), " ")
    n, _ := strconv.Atoi(raw[0])
    m, _ := strconv.Atoi(raw[1])

    for i := 1; i <= n; i++ {
        fa[i] = i
    }

    ans := 0

    for i := 1; i <= m; i++ {
        scanner.Scan()
        raw := strings.Split(scanner.Text(), " ")
        op, _ := strconv.Atoi(raw[0])
        u, _ := strconv.Atoi(raw[1])
        v, _ := strconv.Atoi(raw[2])

        if op == 0 {
            merge(u, v)
        } else { // op == 1
            ans <<= 1
            ans |= bool2int(find(u) == find(v))
            ans %= mod
        }
    }

    fmt.Println(ans)
}

func find(x int) int {
    if fa[x] == x {
        return x
    }

    fa[x] = find(fa[x])

    return fa[x]
}

func merge(x int, y int) {
    fa[find(x)] = find(y)
}

func bool2int(x bool) int {
    if x {
        return 1
    }

    return 0
}
