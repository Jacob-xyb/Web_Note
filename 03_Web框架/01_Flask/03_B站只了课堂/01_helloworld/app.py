from flask import Flask, jsonify, url_for, request, redirect
import config

app = Flask(__name__)
app.config.from_object(config)

books = [{"id": 1, "name": "三国演义"},
         {"id": 2, "name": "水浒传"},
         {"id": 3, "name": "西游记"},
         {"id": 4, "name": "红楼梦"}, ]


@app.route("/book/<int:num>")
def book_detail(num):
    for book in books:
        if num == book["id"]:
            return jsonify(book)
    return f"id为： {num} 的图书没有找到！"


@app.route("/book/list")
def book_list():
    for book in books:
        book['url'] = url_for("book_detail", num=book["id"])
    return jsonify(books)


@app.route("/profile")
def profile():
    return redirect(url_for("hello_world"))


@app.route('/')
def hello_world():  # put application's code here
    return 'Hello World!'


if __name__ == '__main__':
    app.run()
