from flask import Flask, request, render_template

import settings

app = Flask(__name__)
app.config.from_object(settings)


@app.route('/show1')
def show1():
    friends = ['aaa', 'bb', 'cc', 'dd']
    return render_template('show_1.html', friends=friends)


if __name__ == '__main__':
    app.run()
