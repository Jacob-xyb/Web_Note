from flask import Flask, render_template
import settings

app = Flask(__name__)
# app.config.from_object(settings)


@app.route('/')
def EoWeb():  # put application's code here
    return render_template('index.html')


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8888)
