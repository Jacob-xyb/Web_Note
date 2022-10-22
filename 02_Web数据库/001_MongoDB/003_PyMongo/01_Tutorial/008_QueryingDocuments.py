import pprint
from pymongo import MongoClient

client = MongoClient()
db = client.test
posts = db.posts

for post in posts.find():
    pprint.pprint(post)

res = posts.find()  # object of type 'Cursor'  # 是一个迭代类型
print(len(list(res)))
print(posts.count_documents({}))    # int

for post in posts.find({'author': 'Eliot'}):
    pprint.pprint(post)
