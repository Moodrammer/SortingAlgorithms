import sys
import os
import random


def is_int(x):
    try:
        int(x)
        return True
    except ValueError:
        return False


data_count = int(sys.argv[1])
out_file = sys.argv[2]
data = []
with open(out_file, "w") as file:
    for i in range(data_count):
        randint = random.randint(1, 1000000)
        data.append(randint)
        line = str(randint) + '\n'
        file.write(line)
