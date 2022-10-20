import wtforms
from wtforms import validators


class LoginForm(wtforms.Form):
    email = wtforms.StringField(validators=[validators.length(min=5, max=20), validators.email()])
    password = wtforms.StringField(validators=[validators.length(min=6, max=20)])
