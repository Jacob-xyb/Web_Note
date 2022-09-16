from flask import Blueprint, request, render_template, url_for, redirect

from apps.user.model import User

user_bp = Blueprint('user', __name__)

# 列表保存一个一个的用户对象
users = []


@user_bp.route('/')
def user_center():
    return render_template('user/show.html', users=users)


@user_bp.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        repassword = request.form.get("repassword")
        phone = request.form.get("phone")
        if password == repassword:
            # 用户名唯一：
            for user in users:
                if user.name == username:
                    return render_template("user/register.html", msg="用户已存在")
            # 创建 user 对象
            user = User(username, password, phone)
            # 添加到用户列表
            users.append(user)
            return redirect('/')
    return render_template("user/register.html")


@user_bp.route("/login", methods=["GET", "POST"])
def login():
    return "用户登录"


@user_bp.route("/logout", methods=["GET", "POST"])
def logout():
    return "用户退出"


@user_bp.route('/del')
def delete():
    # 获取传递的 username
    name = request.args.get('username')
    # 根据 username 找到列表中的 user 对象
    for user in users:
        if user.name == name:
            # 删除对象
            users.remove(user)
            return redirect('/')
    return "删除失败"


