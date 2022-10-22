import datetime

# In PyMongo we use dictionaries to represent documents
post = {"author": "Mike",
        "text": "My first blog post!",
        "tags": ["mongodb", "python", "pymongo"],
        "date": datetime.datetime.now()}

print(post)
