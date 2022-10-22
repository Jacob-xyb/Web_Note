from pymongo import MongoClient

client = MongoClient()
db1 = client.test_database
# 如果数据库名含有 '-' 连接符，可以采用 dictionary style
db2 = client["test-database"]
