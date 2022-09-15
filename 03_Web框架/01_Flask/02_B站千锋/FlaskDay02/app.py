from flask import Flask, render_template, request, redirect, url_for
import json
import settings

app = Flask(__name__)
app.config.from_object(settings)

users = []


@app.route('/', endpoint='index')
def index():  # put application's code here
    return render_template('index.html')


@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        username = request.form.get('username')
        password = request.form.get('password')
        repassword = request.form.get('repassword')
        if password == repassword:
            user = {'username': username, 'password': password}
            users.append(user)
            # print(users)
            # return '注册成功！<a herf="/">返回首页</a>'
            # return redirect('/')
            return redirect(url_for('index'))
        else:
            return '两次密码不一致'
    else:
        # 否则返回一个 html 页面
        return render_template('index_day02.html')


@app.route('/show')
def show():
    return json.dumps(users)


@app.route('/test')
def test():
    url = url_for('index')    # 路径反向解析
    print(url)
    return 'test'


if __name__ == '__main__':
    app.run(host='0.0.0.0')
