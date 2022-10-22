from pymongo import MongoClient

# 1.connect on the default host and port
client1 = MongoClient()

# 2.specify the host and port explicitly
client2 = MongoClient('localhost', 27017)

# 3.use the MongoDB URI format
client3 = MongoClient('mongodb://localhost:27017/')
