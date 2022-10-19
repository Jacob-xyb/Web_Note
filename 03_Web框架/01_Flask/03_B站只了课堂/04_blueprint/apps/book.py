from flask import Blueprint

# url_prefix: 设置 url 前缀
bp = Blueprint("book", __name__, url_prefix="/book")

@bp.route("/list")
def book_list():
    return 图书列表



