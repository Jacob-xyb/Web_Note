from flask import Flask
import settings
from apps.user.view import user_bp


def create_cpp():
    app = Flask(__name__)  # 核心对象
    app.config.from_object(settings)
    # 蓝图
    app.register_blueprint(user_bp)     # 将蓝图对象绑定到 app 上
    print(app.url_map)
    return app
