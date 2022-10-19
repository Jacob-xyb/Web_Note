from flask import Flask, render_template

app = Flask(__name__)


@app.route('/')
def hello_world():  # put application's code here
    return 'Hello World!'


# jinjia2 模板
@app.route("/about")
def about():
    return render_template("about.html")


# 模板 控制语句
@app.route("/control")
def control():
    data = {"name": "jx", "age": 27,
            "books": [{"id": 1, "name": "三国演义"},
                      {"id": 2, "name": "水浒传"},
                      {"id": 3, "name": "西游记"},
                      {"id": 4, "name": "红楼梦"}, ]}
    return render_template("control.html", **data)


if __name__ == '__main__':
    app.run(debug=True)
