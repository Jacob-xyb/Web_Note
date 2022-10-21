from model import *

ross = User(email='ross@example.com', first_name='Ross', last_name='Lawley').save()

john = User(email='john@example.com')
john.first_name = 'Jacob'
john.last_name = 'xyb'
john.gender = "male"  # 多出的属性并不会存储到数据库中
john.save()

post1 = TextPost(title='Fun with MongoEngine', author=john)
post1.content = 'Took a look at MongoEngine today, looks pretty cool.'
post1.tags = ['mongodb', 'mongoengine']
post1.save()

post2 = LinkPost(title='MongoEngine Documentation', author=ross)
post2.link_url = 'http://docs.mongoengine.com/'
post2.tags = ['mongoengine111']
post2.save()

post2.link_url = 'https://jacob-xyb.github.io/'
post2.save()
