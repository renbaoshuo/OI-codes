import json
import os
import requests

headers = { "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4331.0 Safari/537.36"}

def getProblem(pid):
    url = f"https://www.luogu.com.cn/problem/{pid}?_contentOnly=1"
    return json.loads(requests.get(url, headers=headers).text)

passedProblems = os.listdir('../problem')

for problem in passedProblems:
    if(os.path.isfile(os.path.join('../problem', problem))):
        passedProblems.remove(problem)

listContent = f'# 题目列表\n\n'

for problem in passedProblems:
    problemData = getProblem(problem)["currentData"]["problem"]
    listContent += f'+ [{problemData["pid"]} {problemData["title"]}](https://www.luogu.com.cn/problem/{problemData["pid"]})\n'
    problemContent = f'# [{problemData["pid"]}](https://www.luogu.com.cn/problem/{problemData["pid"]}) {problemData["title"]}\n\n'
    if problemData["background"]:
        problemContent += f'## 题目背景\n\n{problemData["background"]}\n\n'
    if problemData["description"]:
        problemContent += f'## 题目描述\n\n{problemData["description"]}\n\n'
    if problemData["inputFormat"]:
        problemContent += f'## 输入格式\n\n{problemData["inputFormat"]}\n\n'
    if problemData["outputFormat"]:
        problemContent += f'## 输出格式\n\n{problemData["outputFormat"]}\n\n'
    if len(problemData["samples"]) != 0:
        i = 0
        problemContent += f'## 输入输出样例\n\n'
        for sample in problemData["samples"]:
            i += 1
            problemContent += f'### 样例 #{i}\n\n**输入**\n```\n{sample[0]}```\n\n**输出**\n```\n{sample[1]}```\n\n'
    if problemData["hint"]:
        problemContent += f'## 说明/提示\n\n{problemData["hint"]}\n\n'
    problemContent += f'\n\n------\n\n[查看代码](https://github.com/renbaoshuo/Luogu/tree/master/problem/{problem}/{problem}.cpp)'
    f = open(f'../problem/{problem}/problem.md', 'w')
    f.write(problemContent)
    f.close()
    print(f'Successfully get {problem}.')

f = open("../problem/README.md", "w")
f.write(listContent)
f.close()
