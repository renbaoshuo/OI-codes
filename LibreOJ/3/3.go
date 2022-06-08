package main

import (
    "bufio"
    "os"
)

func main() {
    file, _ := os.Open("copycat.in")
    out, _ := os.OpenFile("copycat.out", os.O_WRONLY|os.O_CREATE, 0644)
    reader := bufio.NewReader(file)
    writer := bufio.NewWriter(out)

    x, e := reader.ReadString('\n')
    for e == nil {
        x, e = reader.ReadString('\n')
        writer.WriteString(x)
    }
    writer.Flush()
}
