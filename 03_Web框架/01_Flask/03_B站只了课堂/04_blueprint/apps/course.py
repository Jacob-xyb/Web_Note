from flask import Blueprint

# url_prefix: 设置 url 前缀
bp = Blueprint("course", __name__, url_prefix="/course")


@bp.route("/list")
def course_list():
    return "教程列表"



