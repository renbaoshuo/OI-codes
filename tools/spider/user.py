#!/usr/bin/python3
# coding: utf-8

import json
import os
import time
import pymongo
import requests

dbclient = pymongo.MongoClient("mongodb://127.0.0.1:27017/")
luogudb = dbclient["luogu"]
dbcol = luogudb["user"]

headers = { "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4331.0 Safari/537.36", }

def getUser(uid):
    url = f"https://www.luogu.com.cn/user/{uid}?_contentOnly=1"
    redata = requests.get(url, headers=headers).text
    return json.loads(redata)

for uid in range(1, 459200):
    if list(dbcol.find({'uid': uid})) == []:
        tmpdict = {}
        tmpdict["_id"] = uid
        tmpdict["uid"] = uid
        tmpdata = getUser(uid)
        if tmpdata["code"] == 200:
            tmpdict["data"] = tmpdata["currentData"]["user"]
            dbcol.insert_one(tmpdict)
            print(f"Successfully get user {uid}.")
            # time.sleep(0.2)
        else:
            print(f"Fail to get user {uid}.")
            # time.sleep(0.2)
    else:
        print(f"User {uid} is already exists.")
