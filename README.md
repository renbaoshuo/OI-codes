# OI Codes

[![Author](https://img.shields.io/badge/Author-Baoshuo-b68469.svg?style=flat-square)](https://baoshuo.ren) [![Stars](https://img.shields.io/github/stars/renbaoshuo/OI-codes?style=flat-square)](https://github.com/renbaoshuo/OI-codes/stargazers) [![GPL-3.0 License](https://img.shields.io/github/license/renbaoshuo/OI-codes?style=flat-square)](/LICENSE)

本仓库的主仓库位于 [GitSB](https://git.sb/baoshuo/OI-codes) 上，并在 [GitHub](https://github.com/renbaoshuo/OI-codes)、[GitLab](https://gitlab.com/baoshuo/OI-codes) 和 [GitMac](https://git.m.ac/baoshuo/OI-codes) 上设立了镜像。

## 说明

本仓库存放与 **OI** 有关的代码。

- 部分代码的思路借鉴了题解。
- 部分题目文件夹下会有 `solution.md` 给出做题思路，也会有部分题目会在 [博客](https://oi.baoshuo.ren/) 中给出题解。
- 部分题目的 `data` 文件夹下会存放该题的部分测试数据，这部分内容使用 Git LFS 存储，请参阅下方的「测试数据」一节。

做题时间请参考 `Author Date` ，或根据题目对应提交中注明的提交记录编号查找。

## 仓库使用指南

![](https://arina.loli.net/2022/05/29/zVmpsoQ34KiYDGc.png)

▲ 点击「Commits」按钮可以查看历史提交记录。

![](https://arina.loli.net/2022/05/29/bcQpPV1d7843nDX.png)

▲ 在每个提交记录的说明中都会注明提交记录的链接/编号。

![](https://arina.loli.net/2022/05/29/N6A2kDgCnu8Jc9r.png)

![](https://arina.loli.net/2022/05/29/3IyAo9KdtQgslhL.png)

▲ 可以在提交历史中找到每份代码的不同版本。

## 测试数据

本仓库使用了 [Git LFS](https://git-lfs.github.com) 来存储题目的测试数据。

![](https://arina.loli.net/2022/07/12/Dv8t2bcr1G9fyBT.png)

▲ 在 [GitSB](https://git.sb/baoshuo/OI-codes) 上可以使用「Download this directory」选项下载某道题的所有测试数据。

![](https://arina.loli.net/2022/07/12/9gN2tKMqUVIO5iY.png)

▲ 在 [GitMac](https://git.m.ac/baoshuo/OI-codes) 上可以直接预览存储在 LFS 中的文件内容。

---

在克隆仓库前请先安装 Git LFS，并使用如下命令以获得更快的克隆速度：

```bash
git lfs clone https://git.sb/baoshuo/OI-codes.git --recursive
```

如果克隆仓库时不需要拉取测试数据，可以使用以下命令：

```bash
GIT_LFS_SKIP_SMUDGE=1 git clone https://git.sb/baoshuo/OI-codes.git --recursive
```

后期如果希望再次拉取测试数据，可以使用以下命令：

```bash
git lfs pull
```

## 文件目录结构

| 文件夹                                | 测评系统                                                                                                                                              | 账号                                                               | 说明                                |
| ------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------ | ----------------------------------- |
| [`AcWing`](./AcWing/)                 | [![AcWing](https://arina.loli.net/2022/05/29/P2bn7gmuZKvAqIV.png/250/50)](https://www.acwing.com/problem/)                                            | [宝硕](https://www.acwing.com/user/myspace/index/32848/)           | 部分题目为权限题，需购买对应课程。  |
| [`AtCoder`](./AtCoder/)               | [![AtCoder](https://arina.loli.net/2022/05/29/wZ2Ge4uRt7S9Qxz.png/1000/75)](https://atcoder.jp/contests/archive)                                      | [baoshuo](https://atcoder.jp/users/baoshuo)                        | 题目为比赛题。                      |
| [`BZOJ`](./BZOJ/)                     | [Hydro BZOJ 域](https://hydro.ac/d/bzoj/)、[DarkBZOJ](https://darkbzoj.tk/problems)                                                                   | -                                                                  | 原 BZOJ 已经停止运营。              |
| [`Codeforces`](./Codeforces/)         | [![Codeforces](https://arina.loli.net/2022/05/29/34Lz8cShuaVDEZI.png/250/50)](https://codeforces.com/problemset)                                      | [baoshuo](https://codeforces.com/profile/baoshuo)                  |                                     |
| [`Gym`](./Gym/)                       | [![Codeforces::Gym](https://arina.loli.net/2022/05/29/34Lz8cShuaVDEZI.png/250/50)](https://codeforces.com/gyms)                                       | [baoshuo](https://codeforces.com/profile/baoshuo)                  |                                     |
| [`HDU`](./HDU/)                       | [Hangzhou Dianzi University Online Judge](http://acm.hdu.edu.cn/listproblem.php?vol=1)                                                                | [renbaoshuo](http://acm.hdu.edu.cn/userstatus.php?user=renbaoshuo) | 需要实名认证。                      |
| [`LibreOJ`](./LibreOJ/)               | [![LibreOJ](https://arina.loli.net/2022/05/29/bSj28sOMdiJc9Lp.png/250/50)](https://loj.ac/p)                                                          | [baoshuo](https://loj.ac/u/baoshuo)                                |                                     |
| [`Luogu`](./Luogu/)                   | [![洛谷](https://arina.loli.net/2022/05/29/hUrC3Ky4n6XiSx2.png/250/50)](https://www.luogu.com.cn/problem/list)                                        | [宝硕](https://www.luogu.com.cn/user/168214)                       |                                     |
| [`NowCoder`](./NowCoder/)             | ![牛客竞赛](https://arina.loli.net/2022/05/29/K24iPrRsmF6CGBT.png/250/50)                                                                             | [宝硕](https://ac.nowcoder.com/acm/contest/profile/742234351)      |                                     |
| [`POJ`](./POJ/)                       | [Peking University JudgeOnline](http://poj.org/problemlist)                                                                                           | [renbaoshuo](http://poj.org/userstatus?user_id=renbaoshuo)         |                                     |
| [`S2OJ`](./S2OJ/)                     | [![石家庄二中在线评测系统](https://arina.loli.net/2022/05/29/RdHeuitDCTGgNcQ.png/300/50)](https://www.sjzezoj.com/problems)                           | [baoshuo](https://www.sjzezoj.com/user/profile/baoshuo)            | 校内 OJ，需要访问权限。存在登录墙。 |
| [`tk.hustoj.com`](./tk.hustoj.com/)   | [HUSTOJ TK 题库](http://tk.hustoj.com/problemset.php)                                                                                                 | [renbaoshuo](http://tk.hustoj.com/userinfo.php?user=renbaoshuo)    |                                     |
| [`USACO`](./USACO/)                   | [USACO](https://www.usaco.org)                                                                                                                        | -                                                                  |                                     |
| [`USACO-Training`](./USACO-Training/) | [USACO Training](https://train.usaco.org/)                                                                                                            | -                                                                  |                                     |
| [`Vijos`](./Vijos/)                   | [Vijos](https://vijos.org/p)                                                                                                                          | [renbaoshuo](https://vijos.org/user/145797)                        |                                     |
| [`XJOI`](./XJOI/)                     | [XJOI](https://xjoi.net/problemlist)                                                                                                                  | [renbaoshuo](https://xjoi.net/user/profile/renbaoshuo)             | 存在登录墙。                        |
| [`ybt`](./ybt/)                       | [![信息学奥赛一本通（C++ 版）在线测评系统](https://arina.loli.net/2022/05/29/k92iPQR1ZLabzmB.jpg/250/50)](http://ybt.ssoier.cn:8088/problem_list.php) | baoshuo                                                            |                                     |

## 语言环境信息

本仓库中代码本地编译环境如下：

|   语言 | 编译器版本                                                  | 编译命令                                  |
| -----: | ----------------------------------------------------------- | ----------------------------------------- |
|      C | `gcc (Ubuntu 10.3.0-1ubuntu1~20.04) 10.3.0`                 | `gcc code.c -o code -std=c11 -O2 -lm`     |
|    C++ | `g++ (Ubuntu 10.3.0-1ubuntu1~20.04) 10.3.0`                 | `g++ code.cpp -o code -std=c++14 -O2 -lm` |
| Python | `Python 3.9.5 (default, May 19 2021, 11:32:47) [GCC 9.3.0]` | `python code.py`                          |
| NodeJS | `v14.18.1`                                                  | `node code.js`                            |
|    PHP | `PHP 7.4.3 (cli) (built: Aug 13 2021 05:39:12) ( NTS )`     | `php code.php`                            |

运行环境如下：

|          |                                           |
| -------: | :---------------------------------------- |
|      CPU | `Intel(R) Core(TM) i7-9750H @ 2.60GHz`    |
|     内存 | 32GiB                                     |
| 系统版本 | `Ubuntu 20.04.4 LTS on Windows 10 x86_64` |
| 内核版本 | `5.10.102.1-microsoft-standard-WSL2`      |

代码运行时长均以此环境为准。

## Author

**OI Codes** © [Baoshuo](https://github.com/renbaoshuo), Released under the [GPL-3.0](./LICENSE) License.<br>
Authored and maintained by Baoshuo.

> [Personal Website](https://baoshuo.ren) · [Blog](https://blog.baoshuo.ren) · GitHub [@renbaoshuo](https://github.com/renbaoshuo) · Twitter [@renbaoshuo](https://twitter.com/renbaoshuo)
