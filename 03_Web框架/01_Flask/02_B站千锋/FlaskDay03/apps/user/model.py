class User:
    def __init__(self, name, password, phone=None):
        self.name = name
        self.password = password
        self.phone = phone

    def __str__(self):
        return self.name