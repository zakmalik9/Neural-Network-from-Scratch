import numpy as np
from PIL import Image as im
import matplotlib.pyplot as plt


with open("imgdata/bicycle/bicycle.txt") as f:
    lines = f.readlines()
    f.close()

data = np.array(list(map(int, lines[0].split())))
plt.figure()
plt.imshow(np.reshape(data, (28, 28)), cmap=plt.cm.binary)
plt.show()
print(data)
