from flask import Flask, request, render_template

import settings

app = Flask(__name__)
app.config.from_object(settings)


@app.route('/show')
def show():
    name = "Jacob-xyb"
    friends = ['aa', 'bb', 'cc', 'dd']
    return render_template('show.html', name=name, friends=friends)


if __name__ == '__main__':
    app.run()
