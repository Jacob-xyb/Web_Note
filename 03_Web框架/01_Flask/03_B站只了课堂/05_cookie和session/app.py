from flask import Flask, Response, request, session

app = Flask(__name__)
app.config["SECRET_KEY"] = "123"


@app.route("/set_session")
def set_session():
    session["username"] = "jx"
    return "session 设置成功"


@app.route("/get_session")
def get_session():
    username = session.get("username")
    return f"获取session: {username}"


@app.route("/set_cookie")
def set_cookie():
    response = Response("cookie 设置")
    response.set_cookie("user_id", "xxx")
    return response


@app.route("/get_cookie")
def get_cookie():
    user_id = request.cookies.get("user_id")
    return f"获取到的id: {user_id}"


@app.route('/')
def hello_world():  # put application's code here
    return 'Hello World!'


if __name__ == '__main__':
    app.run(debug=True)
