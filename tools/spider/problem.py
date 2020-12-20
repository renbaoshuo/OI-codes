#!/usr/bin/python3
# coding: utf-8

import json
import os
import time
import pymongo
import requests

dbclient = pymongo.MongoClient("mongodb://127.0.0.1:27017/")
luogudb = dbclient["luogu"]
dbcol = luogudb["problem"]

headers = { "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4331.0 Safari/537.36", }

def getProblem(pid) -> dict:
    url = f"https://www.luogu.com.cn/problem/{pid}?_contentOnly=1"
    redata = requests.get(url, headers=headers).text
    if len(redata) == 0:
        return { "code": 403 }
    else:
        return json.loads(redata)

def getProblemID(type, id, last="") -> str:
    return str(type)+str(id)+str(last)

for i in range(1000, 1001):
    pid = getProblemID("P", i)
    if list(dbcol.find({'pid': pid})) == []:
        tmpdict = {}
        tmpdict["pid"] = pid
        tmpdata = getProblem(pid)
        if tmpdata["code"] == 200:
            tmpdict["data"] = getProblem(pid)["currentData"]["problem"]
            dbcol.insert_one(tmpdict)
            print("Successfully get problem "+pid+".")
            time.sleep(0.8)
        else:
            print("Fail to get problem "+pid+".")
            time.sleep(0.5)
    else:
        print("Problem "+pid+" is already exists.")
