# 初识

## 第一次运行 Flask

一个最小的 Flask 应用如下：

```python
from flask import Flask

app = Flask(__name__)


@app.route("/")
def hello_world():
    return "<p>Hello, World!</p>"
```

可以使用 **flask** 命令或者 python 的 `-m` 开关来运行这个应 用。在运行应用之前，需要在终端里导出 `FLASK_APP` 环境变量：

Bash、CMD、Powershell

```python
$ export FLASK_APP=hello
$ flask run 
* Running on http://127.0.0.1:5000/

> set FLASK_APP=hello
> flask run 
* Running on http://127.0.0.1:5000/
 
> $env:FLASK_APP = "hello"
> flask run
* Running on http://127.0.0.1:5000/
```

## Warning

调试器允许执行来自浏览器的任意 Python 代码。虽然它由一个 pin 保护， 但仍然存在巨大安全风险。不要在生产环境中运行开发服务器或调试器。

如果需要打开所有开发功能，那么需要在运行 `flask run` 之前设置 `FLASK_ENV` 环境变量为 `development` 。

Bash CMD Powershell

```python
$ export FLASK_ENV=development
$ flask run

> set FLASK_ENV=development
> flask run

> $env:FLASK_ENV = "development"
> flask run
```

# 教程

## 布局

教程项目包含如下内容:

- `flaskr/` ，一个包含应用代码和文件的 Python 包。
- `tests/` ，一个包含测试模块的文件夹。
- `venv/` ，一个 Python 虚拟环境，用于安装 Flask 和其他依赖的包。
- 告诉 Python 如何安装项目的安装文件。
- 版本控制配置，如 [git](https://git-scm.com/) 。不管项目大小，应当养成使用版本控制的习惯。
- 项目需要的其他文件。

```python
/home/user/Projects/flask-tutorial
├── flaskr/
│   ├── __init__.py
│   ├── db.py
│   ├── schema.sql
│   ├── auth.py
│   ├── blog.py
│   ├── templates/
│   │   ├── base.html
│   │   ├── auth/
│   │   │   ├── login.html
│   │   │   └── register.html
│   │   └── blog/
│   │       ├── create.html
│   │       ├── index.html
│   │       └── update.html
│   └── static/
│       └── style.css
├── tests/
│   ├── conftest.py
│   ├── data.sql
│   ├── test_factory.py
│   ├── test_db.py
│   ├── test_auth.py
│   └── test_blog.py
├── venv/
├── setup.py
└── MANIFEST.in
```

## 应用设置

一个 Flask 应用是一个 [Flask](https://www.bookstack.cn/read/Flask-2.0-zh/8f10a8dae4f4a37e.md#flask.Flask) 类的实例。应用的所有东西（例如配置 和 URL ）都会和这个实例一起注册。

创建一个 Flask 应用最粗暴直接的方法是在代码的最开始创建一个全局 [Flask](https://www.bookstack.cn/read/Flask-2.0-zh/8f10a8dae4f4a37e.md#flask.Flask) 实例。前面的 “Hello, World!” 示例就是这样做的。有的情况 下这样做是简单和有效的，但是当项目越来越大的时候就会有些力不从心了。

可以在一个函数内部创建 [Flask](https://www.bookstack.cn/read/Flask-2.0-zh/8f10a8dae4f4a37e.md#flask.Flask) 实例来代替创建全局实例。这个函数被 称为 *应用工厂* 。所有应用相关的配置、注册和其他设置都会在函数内部完成， 然后返回这个应用。

### 应用工厂

创建 `flaskr` 文件夹并且文件夹内添加 `__init__.py` 文件。

 `__init__.py` 有两个作用：一是包含应用工厂；二 是告诉 Python `flaskr` 文件夹应当视作为一个包。

`flaskr/__init__.py`

```python
import os
from flask import Flask
def create_app(test_config=None):
    # create and configure the app
    app = Flask(__name__, instance_relative_config=True)
    app.config.from_mapping(
        SECRET_KEY='dev',
        DATABASE=os.path.join(app.instance_path, 'flaskr.sqlite'),
    )
    if test_config is None:
        # load the instance config, if it exists, when not testing
        app.config.from_pyfile('config.py', silent=True)
    else:
        # load the test config if passed in
        app.config.from_mapping(test_config)
    # ensure the instance folder exists
    try:
        os.makedirs(app.instance_path)
    except OSError:
        pass
    # a simple page that says hello
    @app.route('/hello')
    def hello():
        return 'Hello, World!'
    return app
```

`create_app` 是一个应用工厂函数，后面的教程中会用到。这个看似简单的函 数其实已经做了许多事情。

1. `app = Flask(__name__, instance_relative_config=True)` 创建 [Flask](https://www.bookstack.cn/read/Flask-2.0-zh/8f10a8dae4f4a37e.md#flask.Flask) 实例。
   - `__name__` 是当前 Python 模块的名称。应用需要知道在哪里设置路径，使用 `__name__` 是一个方便的方法。
   - `instance_relative_config=True` 告诉应用配置文件是相对于 [instance folder](https://www.bookstack.cn/read/Flask-2.0-zh/62c834b02dae9a1c.md#instance-folders) 的相对路径。实例文件夹在 `flaskr` 包的外面，用于存放本地数据（例如配置密钥和数据库），不应当提交到版本控制系统。
2. [app.config.from_mapping()](https://www.bookstack.cn/read/Flask-2.0-zh/8f10a8dae4f4a37e.md#flask.Config.from_mapping) 设置一个应用的缺省配置：
   - [SECRET_KEY](https://www.bookstack.cn/read/Flask-2.0-zh/62c834b02dae9a1c.md#SECRET_KEY) 是被 Flask 和扩展用于保证数据安全的。在开发过程中，为了方便可以设置为 `'dev'` ，但是在发布的时候应当使用 一个随机值来重载它。
   - `DATABASE` SQLite 数据库文件存放在路径。它位于 Flask 用于存放 实例的 [app.instance_path](https://www.bookstack.cn/read/Flask-2.0-zh/8f10a8dae4f4a37e.md#flask.Flask.instance_path) 之内。下一节会更详细地学习数据库的东西。
3. [app.config.from_pyfile()](https://www.bookstack.cn/read/Flask-2.0-zh/8f10a8dae4f4a37e.md#flask.Config.from_pyfile) 使用 `config.py` 中的值来重载缺省配置，如果 `config.py` 存在的话。 例如，当正式部署的时候，用于设置一个正式的 `SECRET_KEY` 。
   - `test_config` 也会被传递给工厂，并且会替代实例配置。这样可以实现测试和开发的配置分离，相互独立。
4. [os.makedirs()](https://docs.python.org/3/library/os.html#os.makedirs) 可以确保 [app.instance_path](https://www.bookstack.cn/read/Flask-2.0-zh/8f10a8dae4f4a37e.md#flask.Flask.instance_path) 存在。 Flask 不会自动创建实例文件夹，但是必须确保创建这个文件夹，因为 SQLite 数据库文 件会被保存在里面。
5. [@app.route()](https://www.bookstack.cn/read/Flask-2.0-zh/8f10a8dae4f4a37e.md#flask.Flask.route) 创建一个简单的路由，这样在继续教程下面的内容前你可以先看看应用如何运行的。它创建了 URL `/hello` 和一个函数之间的关联。这个函数会返回一个响应，即一个 `'Hello, World!'` 字符串。

### 运行应用

```python
> $env:FLASK_APP = "flaskr"
> $env:FLASK_ENV = "development"
> flask run

# 新版软件
> $env:FLASK_APP = "flaskr"
> flask --debug run
```

# Flask入门

## 最简单的 Flask 应用

```python
from flask import Flask

app = Flask(__name__)


@app.route('/')
def hello_world():  # put application's code here
    return 'Hello World!'


if __name__ == '__main__':
    app.run()
```

**run参数：** 

run(host='ip地址', port='端口号', debug=False/True)

如果需要外网可以访问就将 `host='0.0.0.0'` ，记住 port 不要重复，以免引起意外。

`debug=True` 时开启调试模式，只要代码改变，服务器就会重新加载

**环境：** production、development、testing
