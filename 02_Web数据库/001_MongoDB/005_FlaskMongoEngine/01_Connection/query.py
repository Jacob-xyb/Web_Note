from flask import Flask
from model import *
import config

app = Flask(__name__)
app.config.from_object(config)
db.init_app(app)

print(len(User.objects))


print(User.objects[1].sub.keys())


# User.objects[1].sub["key1"] = "33"
# User.objects[1].name = "222"
# User.objects[1].save()

obj = User.objects[1]
obj.name = "222"
obj.sub["key1"] = "33"
obj.save()

# User.objects[1].update()
