from flask import Flask, request, render_template

import settings

app = Flask(__name__)
app.config.from_object(settings)


@app.route('/base')
def show_base():
    return render_template('base.html')


@app.route('/')
def show_index():
    return render_template('call_base.html')


if __name__ == '__main__':
    app.run()
