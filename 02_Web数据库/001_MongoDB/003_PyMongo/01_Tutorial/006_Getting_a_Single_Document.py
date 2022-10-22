from pymongo import MongoClient
import pprint

client = MongoClient()
db = client.test
posts = db.posts

pprint.pprint(posts.find_one())
pprint.pprint(posts.find_one({"title": "xxx"}))  # None
