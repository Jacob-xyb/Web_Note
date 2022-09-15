from flask import Blueprint

user_bp = Blueprint('user', __name__)

# 列表保存一个一个的用户对象
users = []


@user_bp.route('/')
def user_center():
    return "用户中心"


@user_bp.route("/register", methods=["GET", "POST"])
def register():
    return "用户注册"


@user_bp.route("/login", methods=["GET", "POST"])
def register():
    return "用户登录"


@user_bp.route("/logout", methods=["GET", "POST"])
def register():
    return "用户退出"
