from flask import Flask
from apps import book, course, user


app = Flask(__name__)
app.register_blueprint(book.bp)
app.register_blueprint(course.bp)
app.register_blueprint(user.bp)


@app.route('/')
def hello_world():  # put application's code here
    return 'Hello World!'


if __name__ == '__main__':
    app.run()
