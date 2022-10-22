import pprint
from pymongo import MongoClient

client = MongoClient()
db = client.test
posts = db.posts

for post in posts.find():
    pprint.pprint(post)
    x = post    # 返回的是一个 dict 对象



