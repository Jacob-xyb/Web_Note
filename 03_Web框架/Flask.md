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

## 配置文件 settings.py

**以模块对象的形式加载**

`settings.py`

```python
# 配置文件

ENV = 'development'
DEBUG = True
```

```python
from flask import Flask
import settings

app = Flask(__name__)
app.config.from_object(settings)	# 以模块对象载入即可

# 等价于
app.config.from_pyfile('setting.py')
```

## 路由

Flask 是自上而下的匹配第一个搜索到的路由

```python
@app.route('/index')
def index():
    pass

# 其实等效于

def index():
    pass
app.add_url_rule('/index', view_func=index)
```

### 路由的变量规则

注意：视图返回值绝对不能是 int 类型。

```python
form flask import Flask

app = Flask(__name__)

@app.route('/')
def index():
    return 'index page'

# 路由变量规则：变量名默认为 str 类型
data = {'a': 'beijing', 'b': 'shanghai'. 'c': 'shenzhen'}
@app.route('/getcity/<key>')
def index(key):
    return data.get(key)


if __name__ == '__main__':
    app.run()
```

路由变量规则可传类型:

```python
@app.route('/<key>')	# 默认为字符串，显示<str:key>会报错
@app.route('/<int:num>')	# 正整型
@app.route('/<float:num>')	# 正浮点数，不常使用
@app.route('/<path:p>')		# 路径，不常使用
```

### 路由唯一性

路由中定义了 `/`，无论请求的 URL 是否带有 `/` ，都可以执行成功。 

所以以下写法是不被允许的：

```python
@app.route('/project')
@app.route('/project/')
```

并且推荐不带 `/` 的写法，不要产生重定向

```python
@app.route('/project')
```

## 请求与响应

**http协议 包含 请求 与 响应**

**request:**

请求行：请求地址：`http://127.0.0.1:5000/`  请求方法：method: GET

请求头：键值对

请求体：GET请求一般没有请求体，POST才有。

**response：**

响应行：状态码  200 OK 、404 not found 、500、302

响应头：键值对

响应体：就是返回的内容

### 响应

`Response()` 和`make_response(content)` 都可以返回一个响应对象，可定制响应头

```python
response = make_response(content)
response.headers['key'] = 'value'
# 还可以一次声明
response = Response(content, headers={key:value})
# 类属性
respones.content_type
respones.headers
respones.status_code	# 200
respones.status			# 200 OK
```

**视图函数的返回值：**

- str: 自动转成 response 对象
- dict: json
- response：Response 对象
- make_response(): Response 对象
- redirect()：重定向 302 状态码
- render_template()：模板渲染 + 模板

### 请求

```python
from flask import request

request.full_path	# /register?username=zhangsan&address=Beijing
request.path		# /register
# args 只能获取 GET 请求
request.args		# 封装的dict (key, value)
request.args.get('username')	# 'zhangsan'
# POST 请求的表单内容在 请求体中，用 form 获取
request.form
request.form.get('username')

request.method		# 获取请求类型
```

## 重定向

```python
from flask import redirect

def redirect(
    location: str, code: int = 302, Response: t.Optional[t.Type["BaseResponse"]] = None
) -> "BaseResponse":
```

## 模板

Jinjia2 模板引擎

`render_template(path)` : 默认去 `templates` 文件夹寻找 html 文件。 其实返回的就是 html 的字符串。

模板遵守模板的语法，就可以在 html 模板中写 Python 语法，所以 html 不再称之为 `网页`， 而是 `模板`。

### 字符串

```python
render_template('show.html', name=name)

# html 获取方式
{{ name }}
```

### 列表

可以和Python语句相通

```python
l = ['aa', 'bb', 'cc', 'dd']

# html
{{ l }}		# 直接输出 l 的字符串
{{ l[0] }}、 {{ l[:2] }}  # 均支持
{{ l.0 }}	# 这种获取下标的方式很奇怪
```

### 字典

```python
d = {"a": "aaa", "b": "bbb", "c": "ccc"}

# html
{{ d.a }}  || {{ d.get('a') }}   # 感觉前面的方式会简单许多
```

### 对象

```python
class Girl:
    def __init__(self, name):
        self.name = name

obj = Girl('mm')

render_template('show.html', obj=obj)
# html
{{ obj.name }}
```

### 控制块

`{%  %}`

### for + loop

for 循环自带 loop 变量:

 `loop.index` 序号从 1 开始；`loop.index0` 序号从 0 开始；

`loop.revindex` 序号倒序，结束是 1；`loop.revindex0` 序号倒序，结束是 0；

`loop.first` 、`loop.last` 返回 True/False，判断

### 过滤器

语法：`{{ 变量名 | 过滤器(*args) }}` 

**常见的过滤器：**

- **字符串操作：**

1. safe: 禁用转义 例如 `<p>hello</p>` 使用过滤器 p标签 就可以生效
2. capitalize：首字母大写
3. lower:  全部小写
4. upper: 全部大写
5. tltle: 每个单词的首字母大写
6. reverse: 逆序
7. format: 格式化输出  `{{ '%s is %d years old' | format('Bob', 18) }}` 
8. truncate: 截断  `{{ 'hello world' | truncate(5) }}`

- **列表操作：**

1. first 、last 、length
2. sort:  排序 常用于 整型列表

- **字典操作：**

1. d.values()、d.keys()、d.items()

### 自定义过滤器

第一种方式：

```python
def replace_hello(value):
    return value.replace('hello', '').strip()

app.add_template_filter('replace', replace_hello)

# html
{{ str | replace }}
```

第二种方式：装饰器

```python
@app.template_filter('list_reverse')
def reverse_list(li):
    temp_li = list(li)
    temp_li.reverse()
    return temp_li
```

### 复用

#### 模板继承 *

需要模板继承的情况：

1. 多个模板具有完全相同的顶部和底部
2. 多个模板具有相同的模板内容，但是内容中部分不一样

标签：

```python
# 填坑
{% block 名字 %}

{% endblock %}

# 继承这个坑 html 文件开头继承模板
{% extends 'base.html' %}
# 然后自定义内容
{% block title %}
继承模板
{% endblock %}
```

#### include

include 路径均基于 `templates`

```python
{% include 'common/header.html' %}
```

#### 宏：macro

目的：代码可以复用，避免代码冗余

```python
# 定义宏
{% macro form(action, value='登录', method='post') %}
	<form action="{{ action }}" method="{{ method }}">
    ...
    </form>
{% endmacro %}

# 调用宏
{{ form('/') }}

# 其他文件调用
{% import 'macro/macro.html' as f %}
{{ f.form('/') }}
```

### url_for()

### 声明变量

`{% set x = [0, 1, 2] %}`

## 蓝图

### 问题1

**Question：**路由外拆后 `render_template()` 不再默认在 templates 文件夹下寻找文件。 因为会默认去创建 `Flask 对象` 的所在目录寻找 templates 文件夹

**Solution：**

1. 将 `template` 和 `static` 文件夹移动到当前 `__init__.py`  所在文件夹

2. 在创建对象时，进行设置  

    `app = Flask(__name__, template_folder='../templates', static_folder='../static')  # 核心对象`

   

