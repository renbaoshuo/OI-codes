## 思路

- 算法：记忆化搜索

设 $F_{i,j,0}$ 表示从一个格子上方走到该格子的路径最大和，$F_{i,j,1}$ 表示从一个格子下方走到该格子的路径最大和。

若搜到以前搜过的状态则直接返回搜过的最大和（也就是 $F$ 中的值），否则继续搜索到达该格时的最大和。

## 代码

见 `P7074.cpp` 。
