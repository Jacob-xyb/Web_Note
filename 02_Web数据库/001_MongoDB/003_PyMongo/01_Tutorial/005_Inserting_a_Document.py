from pymongo import MongoClient
import datetime

client = MongoClient()
db = client.test
posts = db.posts

post = {"author": "Mike",
        "text": "My first blog post!",
        "tags": ["mongodb", "python", "pymongo"],
        "date": datetime.datetime.now()}

return_post = posts.insert_one(post)

print(return_post.inserted_id)
print(db.list_collection_names())
