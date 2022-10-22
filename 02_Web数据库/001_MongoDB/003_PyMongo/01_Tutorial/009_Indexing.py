import pprint
import pymongo
from pymongo import MongoClient
import datetime

client = MongoClient()
db = client.test

result = db.profiles.create_index(
    [('user_id', pymongo.ASCENDING)], unique=True)
# 等效写法
result = db.profiles.create_index(
    [('user_id', 1)], unique=True)

print(sorted(list(db.profiles.index_information())))
print(result)   # user_id_1
