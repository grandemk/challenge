import os
for i in range(1, 255):
    os.system("./vulnerable 1 {}".format(chr(i)))
