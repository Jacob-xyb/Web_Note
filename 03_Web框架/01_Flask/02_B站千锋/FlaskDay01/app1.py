from flask import Flask, Response
import settings

app = Flask(__name__)
app.config.from_object(settings)


@app.route('/')
def hello_world():      # 返回一个 json 格式
    return {'a': '上海', 'b': '北京', 'c': '深圳'}


@app.route('/index')
def hello_world():      # 返回一个 tuple 格式
    return 'hello tuple', 200


@app.route('/index1')
def hello_world():      # 返回一个 Response 对象，只返回 html 格式
    return Response('<p>Hello World!<p>')


if __name__ == '__main__':
    app.run(host='0.0.0.0')
