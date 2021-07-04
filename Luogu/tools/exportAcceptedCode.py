import json
import os
import time
import requests
import sys

'''
洛谷 AC 记录导出工具
======
请谨慎使用此脚本
======
参数[1]: uid
参数[2]: clientid
======
仅支持导出 C++ 语言的提交记录
'''

if not os.path.exists('data'):
    os.makedirs('data')

if len(sys.argv) < 3:
    print("Invaild parameter.")
    exit(0)

uid = sys.argv[1]
clientid = sys.argv[2]

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4331.0 Safari/537.36",
    "Cookie": f"__client_id={clientid}; _uid={uid};"
}


def getUser(uid):
    url = f"https://www.luogu.com.cn/user/{uid}?_contentOnly=1"
    return json.loads(requests.get(url, headers=headers).text)


def getProblem(pid):
    url = f"https://www.luogu.com.cn/problem/{pid}?_contentOnly=1"
    return json.loads(requests.get(url, headers=headers).text)


def getRecord(rid):
    url = f"https://www.luogu.com.cn/record/{rid}?_contentOnly=1"
    return json.loads(requests.get(url, headers=headers).text)


def getAcceptedProblemRecord(pid, page=1):
    url = f"https://www.luogu.com.cn/record/list?_contentOnly=1&pid={pid}&user={uid}&page={page}&status=12"
    result = json.loads(requests.get(url, headers=headers).text)
    for record in result["currentData"]["records"]["result"]:
        # 3 -> C++ ; 4 -> C++11 ; 11 -> C++14 ; 12 -> C++17
        if record["language"] == 3 or record["language"] == 4 or record["language"] == 11 or record["language"] == 12:
            return record["id"]
    return -1


passedProblems = getUser(uid)["currentData"]["passedProblems"]

for problem in passedProblems:
    if os.path.isfile(f'data/{problem["pid"]}.md') == False:
        problemData = getProblem(problem["pid"])["currentData"]["problem"]
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
        f = open(f'data/{problem["pid"]}.md', 'w')
        f.write(problemContent)
        f.close()
        # Export C++ Code
        rid = getAcceptedProblemRecord(problem["pid"])
        if not rid == -1:
            data = getRecord(rid)
            f = open(f'data/{problem["pid"]}.cpp', 'w')
            f.write(data["currentData"]["record"]["sourceCode"])
            f.close()
        print(f'Successfully get {problem["pid"]}.')
    else:
        print(f'Problem {problem["pid"]} is already exists.')
