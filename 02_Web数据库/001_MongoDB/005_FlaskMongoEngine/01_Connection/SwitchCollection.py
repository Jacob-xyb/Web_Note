from flask import Flask
from mongoengine import connection
from mongoengine.context_managers import switch_collection

from model import *
import config

app = Flask(__name__)
app.config.from_object(config)
db.init_app(app)

u = User(email="xx", name="jx")
u.sub = {"key1": "v1", "key2": "v2"}


with switch_collection(User, 'test') as User:
    u = User(email="xx", name="jx")
    u.sub = {"key1": "v1", "key2": "v2"}
    u.save()
    # u.save()  # Saves the 'archive-user-db'
    data = User.objects[0]


print(data.name)
data.save()


@app.route('/')
def hello_world():  # put application's code here
    return 'Hello World!'


if __name__ == '__main__':
    pass
    # app.run()
