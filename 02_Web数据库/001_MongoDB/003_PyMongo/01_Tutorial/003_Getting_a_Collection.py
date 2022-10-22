from pymongo import MongoClient

client = MongoClient()
db = client.test

collection1 = db.test_collection

collection2 = db['test-collection']
