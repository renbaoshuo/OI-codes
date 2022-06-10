package main

import (
    "fmt"
    "sort"
)

const N int = 1e5 + 5
const K int = 2e5 + 5

type node struct {
    a, b, c, cnt, res int
}

var (
    q      []node
    w      [N]node
    c, ans [K]int
)

func lowbit(x int) int {
    return x & -x
}

func add(x, y int) {
    for ; x <= 2e5; x += lowbit(x) {
        c[x] += y
    }
}

func sum(x int) int {
    var res int = 0

    for ; x > 0; x -= lowbit(x) {
        res += c[x]
    }

    return res
}

func mergeSort(l, r int) {
    if l >= r {
        return
    }

    var mid = (l + r) / 2

    mergeSort(l, mid)
    mergeSort(mid+1, r)

    var i, j, k = l, mid + 1, 0

    for i <= mid && j <= r {
        if q[i].b <= q[j].b {
            add(q[i].c, q[i].cnt)
            k++
            w[k] = q[i]
            i++
        } else {
            q[j].res += sum(q[j].c)
            k++
            w[k] = q[j]
            j++
        }
    }

    for i <= mid {
        add(q[i].c, q[i].cnt)
        k++
        w[k] = q[i]
        i++
    }

    for j <= r {
        q[j].res += sum(q[j].c)
        k++
        w[k] = q[j]
        j++
    }

    for i = l; i <= mid; i++ {
        add(q[i].c, -q[i].cnt)
    }

    for i, j := l, 1; j <= k; j++ {
        q[i] = w[j]
        i++
    }
}

func main() {
    var n, k int

    fmt.Scan(&n, &k)

    q = append(q, node{})

    for i := 1; i <= n; i++ {
        var a, b, c int

        fmt.Scan(&a, &b, &c)

        q = append(q, node{a, b, c, 1, 0})
    }

    sort.Slice(q, func(x, y int) bool {
        if q[x].a != q[y].a {
            return q[x].a < q[y].a
        }

        if q[x].b != q[y].b {
            return q[x].b < q[y].b
        }

        return q[x].c < q[y].c
    })

    k = 1
    for i := 2; i <= n; i++ {
        if q[i].a == q[k].a && q[i].b == q[k].b && q[i].c == q[k].c {
            q[k].cnt++
        } else {
            k++
            q[k] = q[i]
        }
    }

    mergeSort(1, k)

    for i := 1; i <= k; i++ {
        ans[q[i].res+q[i].cnt-1] += q[i].cnt
    }

    for i := 0; i < n; i++ {
        fmt.Println(ans[i])
    }
}
