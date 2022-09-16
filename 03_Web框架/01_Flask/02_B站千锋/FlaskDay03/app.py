from apps import create_cpp


if __name__ == '__main__':
    app = create_cpp()
    # print(app.url_map)
    app.run()
