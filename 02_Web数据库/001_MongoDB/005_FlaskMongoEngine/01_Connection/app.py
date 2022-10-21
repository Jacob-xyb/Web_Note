from flask import Flask
from model import *
import config

app = Flask(__name__)
app.config.from_object(config)
db.init_app(app)

u = User(email="xx", name="jx")
u.sub = {"key1": "v1", "key2": "v2"}
u.save()


@app.route('/')
def hello_world():  # put application's code here
    return 'Hello World!'


if __name__ == '__main__':
    app.run()
