from flask_mongoengine import MongoEngine
import mongoengine.fields as fields

db = MongoEngine()


class User(db.Document):
    email = fields.StringField(required=True)
    name = fields.StringField(required=True, max_length=128)
    sub = fields.DictField()

    meta = {
        'ordering': ['-create_at'],
        'strict': False,
    }

    # def __repr__(self):
    #     return 'User(email="{}", username="{}")'.format(self.username, self.password)


class Person(db.Document):
    email = fields.StringField(required=True)
    name = fields.StringField(required=True, max_length=128)

    meta = {
        'ordering': ['-create_at'],
        'strict': False,
    }

    def __repr__(self):
        return 'User(email="{}", username="{}")'.format(self.username, self.password)
