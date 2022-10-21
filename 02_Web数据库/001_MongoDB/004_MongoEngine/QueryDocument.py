from model import *


print(len(User.objects))

for user in User.objects:
    print(user.first_name)



