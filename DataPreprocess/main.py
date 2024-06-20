import numpy as np
from PIL import Image as im
import random

names = ["bicycle", "cat", "cruiseship", "helicopter", "houseplant",
         "lollipop", "octopus", "tractor", "umbrella", "windmill"]
size = 2100
train_size = 100
# Saving All Data
all_data = []
for name in names:
    data = np.load("rawimgdata/" + name + ".npy")
    all_data.append(data[:size])
# Saving Training Data in txt File
data_strings = []
for category_num, data in enumerate(all_data):
    for img_num in range(size-train_size):
        pixels = data[img_num]
        data_string = str(category_num) + " "
        for pixel in pixels:
            data_string += str(pixel) + " "
        data_string += "\n"
        data_strings.append(data_string)
random.shuffle(data_strings)
train_data_string = ""
for s in data_strings:
    train_data_string += s
with open("imgdata/traindata.txt", 'w') as f:
    f.write(train_data_string)
    f.close()
# Saving Test Data in txt file and Saving Test Image Files
test_data = []
for category_num, data in enumerate(all_data):
    for img_num in range(size-train_size, size):
        pixels = data[img_num]
        data_string = str(category_num) + " "
        for pixel in pixels:
            data_string += str(pixel) + " "
        data_string += "\n"
        img_pixels = np.reshape(pixels, (28, 28))
        test_data.append([data_string, img_pixels])
random.shuffle(test_data)
test_data_string = ""
for i, data in enumerate(test_data):
    test_data_string += data[0]
    img_pixels = data[1]
    img = im.fromarray(img_pixels)
    img.save("imgdata/testimages/" + str(i) + ".png")
with open("imgdata/testdata.txt", 'w') as f:
    f.write(test_data_string)
    f.close()
