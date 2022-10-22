# PyMongo 和 MongoEngine

   PyMongo是一个低级的MongoDB的Python驱动器（我一般称为客户端），它封装了 MongoDB API，并通过JSON与MongoDB通信，PyMongo将MongoDB的数据映射成Python的内置类型。

   MongoEngine 是一个Document-Object Mapper (想一下ORM, 但它是针对文档型数据库)，Python通过它与MongoDB交互。你可能会说那PyMongo也是ORM啊，在Python中一切都是对象，但我们所说的ORM中的Object在指Python中的自定义类，而不是内置类型。MongoEngine或MongoKit将MongoDB的数据映射成自定义类实例，它们都是基于PyMongo的。

   我们可以跟关系型数据库的Python客户端MySQLdb，以及ORM SQLAlchemy/Django ORM比较一下，PyMongo相当于MySQLdb，MongoEngine相当于SQLAlchemy，SQLAlchemy是基于MySQLdb之上的，MongoEngine是基于PyMongo的。

# PyMongo

## Quick Start

### [Making a Connection with MongoClient](https://pymongo.readthedocs.io/en/stable/tutorial.html#making-a-connection-with-mongoclient)

```py
from pymongo import MongoClient

# 1.connect on the default host and port
client1 = MongoClient()

# 2.specify the host and port explicitly
client2 = MongoClient('localhost', 27017)

# 3.use the MongoDB URI format
client3 = MongoClient('mongodb://localhost:27017/')
```

### [Getting a Database](https://pymongo.readthedocs.io/en/stable/tutorial.html#making-a-connection-with-mongoclient)

MongoDB的一个实例可以支持多个独立的数据库。

使用PyMongo时，您可以在MongoClient实例上使用属性样式访问数据库:

```py
from pymongo import MongoClient

client = MongoClient()
db1 = client.test_database
# 如果数据库名含有 '-' 连接符，可以采用 dictionary style
db2 = client["test-database"]
```

### [Getting a Collection](https://pymongo.readthedocs.io/en/stable/tutorial.html#getting-a-collection)

 Getting a collection in PyMongo works the same as getting a database:

```py
from pymongo import MongoClient

client = MongoClient()
db = client.test

collection1 = db.test_collection

collection2 = db['test-collection']
```

An important note about collections (and databases) in MongoDB is that they are created lazily - none of the above commands have actually performed any operations on the MongoDB server. Collections and databases are created when the first document is inserted into them.

### [Documents](https://pymongo.readthedocs.io/en/stable/tutorial.html#documents)

 In PyMongo we use dictionaries to represent documents.

```py
import datetime

# In PyMongo we use dictionaries to represent documents
post = {"author": "Mike",
        "text": "My first blog post!",
        "tags": ["mongodb", "python", "pymongo"],
        "date": datetime.datetime.now()}
```

#### [Inserting a Document](https://pymongo.readthedocs.io/en/stable/tutorial.html#inserting-a-document)

```python
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
```

#### [Getting a Single Document](https://pymongo.readthedocs.io/en/stable/tutorial.html#getting-a-single-document-with-find-one)

```py
from pymongo import MongoClient
import pprint

client = MongoClient()
db = client.test
posts = db.posts

pprint.pprint(posts.find_one())
pprint.pprint(posts.find_one({"title": "xxx"}))  # None
```

A common task in web applications is to get an ObjectId from the request URL and find the matching document. It’s necessary in this case to **convert the ObjectId from a string** before passing it to `find_one`:

```py
from bson.objectid import ObjectId

# The web framework gets post_id from the URL and passes it as a string
def get(post_id):
    # Convert from string to ObjectId:
    document = client.db.collection.find_one({'_id': ObjectId(post_id)})
```

#### [Bulk Inserts](https://pymongo.readthedocs.io/en/stable/tutorial.html#bulk-inserts)

```py
import datetime
from pymongo import MongoClient

client = MongoClient()
db = client.test
posts = db.posts

new_posts = [{"author": "Mike",
              "text": "Another post!",
              "tags": ["bulk", "insert"],
              "date": datetime.datetime(2009, 11, 12, 11, 14)},
             {"author": "Eliot",
              "title": "MongoDB is fun",
              "text": "and pretty easy too!",
              "date": datetime.datetime(2009, 11, 10, 10, 45)}]
result = posts.insert_many(new_posts)
print(result.inserted_ids)
```

#### [Querying for More Than One Document](https://pymongo.readthedocs.io/en/stable/tutorial.html#querying-for-more-than-one-document)

```py
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
```

#### [Range Queries](https://pymongo.readthedocs.io/en/stable/tutorial.html#range-queries)

```py
import pprint
from pymongo import MongoClient
import datetime

client = MongoClient()
db = client.test
posts = db.posts

d = datetime.datetime(2009, 11, 12, 12)
for post in posts.find({"date": {"$lt": d}}).sort("author"):    # 没有 data 属性的会被忽略
    pprint.pprint(post)
```

#### [Indexing](https://pymongo.readthedocs.io/en/stable/tutorial.html#indexing)



# MongoEngine

## Download

```py
$ python -m pip install mongoengine -i https://pypi.tuna.tsinghua.edu.cn/simple
```

## Quick Start

### [Quick Connection](http://docs.mongoengine.org/tutorial.html#getting-started)

如果是在本地运行，执行 `connect()` 直接提供 MongoDB database 的名字即可。

```py
from mongoengine import *
connect("test")		# 本地运行 直接提供 MongoDB database 的名字即可
```

### [Defining our documents](http://docs.mongoengine.org/tutorial.html#defining-our-documents)

必须定义一个 Document 来继承抽象类，**类名** 即 **collection名** 。

```py
class User(Document):
    email = StringField(required=True)
    first_name = StringField(max_length=50)
    last_name = StringField(max_length=50)
```

创建一个类的实例，`.save()` 即保存到数据库中。

```py
ross = User(email='ross@example.com', first_name='Ross', last_name='Lawley').save()
```

>  test: database -> user: collection -> ross: document

## Fields

[classmongoengine.base.fields.BaseField(db_field=None, required=False, default=None, unique=False, unique_with=None, primary_key=False, validation=None, choices=None, null=False, sparse=False, **kwargs)](http://docs.mongoengine.org/apireference.html#mongoengine.base.fields.BaseField)

**Parameters:**

- **required** : If the field is required. Whether it has to have a value or not. Defaults to False.
- **unique** – Is the field value unique or not. Defaults to False.

# Flask MongoDB

## Flask-MongoEngine

在Flask中使用MongoEngine，需要通过Flask-MongoEngine包来对MongoEngine进行配置。Flask-MongoEngine是MongoEngine的Flask封装，针对Flask对MongoEngine做出了一些拓展，而MongoEngine则是在PyMongo的基础上构建的一个类似于SQLAlchemy的对象文档映射器（Object-Document Mapper, ODM），为用户提供基本的数据模型以及类型约束，并对PyMongo的数据查询做了进一步的封装，避免直接书写MongoDB查询语句，简化数据查询。

PyMongo是MongoDB官方提供的Python库，将MongoDB CLI中JS风格的查询语句在Python中进行了封装，用户仍然可以在Python中采用和MongoDB CLI中相同的方法操作MongoDB数据库。但PyMongo本身缺乏类型约束、值校验、数据模型等特性支持，每一次的查询操作都需要直接和字典进行交互。

Flask-MongoEngine对MongoEngine做了以下拓展：

1. 从`MONGODB_XXX`格式变量中读取MongoEngine的配置信息，并自动建立连接。
2. 对MongoEngine的查询`QuerySet`进行了拓展，以支持`get_or_404`，`first_or_404`，`paginate`，`paginate_field`。
3. 支持直接从MongoEngine模型中生成WTForms表单。
4. 支持将MongoEngine作为session存储后端。
5. 为`flask_debugtoolbar`提供MongoEngine查询跟踪。
6. 通过`app.json_encoder`对Flask默认的JSON编码器进行拓展，添加了`BaseDocument`和`QuerySet`两个类型的序列化支持。

## Download

```py
pip install flask-mongoengine -i https://pypi.tuna.tsinghua.edu.cn/simple
```

## Flask configuration

Flask-mongoengine 不提供任何的默认配置。

## Recommended: List of dictionaries settings

建议设置连接的方法是在应用程序配置中设置 `MONGODB_SETTINGS`。`MONGODB_SETTINGS` 是一个字典列表，其中每个字典都是针对单个数据库(对于具有多数据库的系统)使用的配置。

```py
import flask
from flask_mongoengine import MongoEngine

db = MongoEngine()
app = flask.Flask("example_app")
app.config["MONGODB_SETTINGS"] = [
    {
        "db": "test",
        "host": "localhost",
        "port": 27017,
        "alias": "default",
    }
]
db.init_app(app)
```

- `alias` 建立的数据库连接的别名，默认为`default`，通过alias机制可以同时访问多个MongoDB数据库。
- `db` 将要访问的数据库名称，默认为`test`
- `host` MongoDB服务器地址，默认为`localhost`
- `port` MongoDB服务器端口，默认为`27017`
- `username` 用户名
- `password` 用户密码
- `authentication_source` 认证源，创建该用户的数据库
- `authentication_mechanism` 认证机制，不需要设置
- `is_mock` 是否使用 mongomock
- `connect` 是否直接连接服务器，如果为false，则直到第一次操作时才会连接服务器
- `tz_aware` 是否自动识别时区，如果为false，则直接使用本地时间，忽略datetime的时区配置

完整的参数列表参考`pymongo.mongo_client.MongoClient`。

# Q&A

## 编辑器/pylint提示“Instance of 'MongoEngine' has no 'StringField' member”

Flask-MongoEngine在初始化时，为MongoEngine类通过`_include_mongoengine`方法动态注入`mongoengine`和`mongoengine.fields`的所有属性，但pylint在进行静态检测时，无法处理动态注入的属性。

```py
def _include_mongoengine(obj):
    """
    Copy all of the attributes from mongoengine and mongoengine.fields
    onto obj (which should be an instance of the MongoEngine class).
    """
    for module in (mongoengine, mongoengine.fields):
        for attr_name in module.__all__:
            if not hasattr(obj, attr_name):
                setattr(obj, attr_name, getattr(module, attr_name))

                # patch BaseField if available
                _patch_base_field(obj, attr_name)

class MongoEngine(object):
    """Main class used for initialization of Flask-MongoEngine."""

    def __init__(self, app=None, config=None):
        _include_mongoengine(self)
        ...
```

解决方法1：直接通过`mongoengine.fields.XXXField`引用。

```py
import mongoengine.fields as fields
class User(db.Document):
    email = fields.StringField(required=True)
    username = fields.StringField(required=True, max_length=128, unique=True)
    password = fields.StringField(max_length=256)
```

解决方法2：禁用pylint错误报告。

```py
# pylint: disable=no-member
value = db.StringField(max_length=200) # no error
```

