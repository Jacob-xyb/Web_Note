from flask import Blueprint

# url_prefix: 设置 url 前缀
bp = Blueprint("user", __name__, url_prefix="/user")


@bp.route("/list")
def user_list():
    return "用户列表"



