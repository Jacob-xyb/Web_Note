import pprint
from pymongo import MongoClient

client = MongoClient()
db = client.get_database('test')
posts = db.get_collection('posts')

query = {'author': 'Mike'}
data = posts.find_one(query)    # '_id': ObjectId('6352a737c3131cc40b13066a')

data['author'] = 'Jacob'
data['author1'] = 'Jx'

posts.find_one_and_replace(query, data)     # 这样的方式不会改变 '_id'
# posts.find_one_and_update(query, data)  # ValueError: update only works with $ operators







