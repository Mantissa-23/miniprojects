#!/bin/python3

import sys
from collections import defaultdict
from skimage import io, util
import numpy as np
import math
import random


def distance(pixel1, pixel2):
    return math.sqrt((float(pixel1[0]) - float(pixel2[0]))**2 +
                     (float(pixel1[1]) - float(pixel2[1]))**2 +
                     (float(pixel1[2]) - float(pixel2[2]))**2)


MAX_DISTANCE = distance((0, 0, 0), (255, 255, 255))


def norm_distance(pixel1, pixel2):
    return distance(pixel1, pixel2) / MAX_DISTANCE


def simplify(image, iterations):
    ret = np.array(image)

    all_migrations = defaultdict(list)

    for i in range(0, iterations):
        for x in range(0, image.shape[0]):
            for y in range(0, image.shape[1]):
                for nx, ny in migrate(image, (x, y)):
                    all_migrations[(nx, ny)].append(image[x, y])

        for coord, colors in all_migrations.items():
            ret[coord[0], coord[1]] = colors[random.randint(0, len(colors) - 1)]

    return ret


def migrate(image, idx):
    offsets = ((-1, -1), (-1, 0), (-1, 1),
               (0, -1), (0, 1),
               (1, -1), (1, 0), (1, 1))

    migrations = []
    for dx, dy in offsets:
        if 0 <= idx[0] + dx < image.shape[0] and 0 <= idx[1] + dy < image.shape[1]:
            dist = norm_distance(image[idx[0] + dx, idx[1] + dy], image[idx[0], idx[1]])
            if random.random() >= dist:
                migrations.append((idx[0] + dx, idx[1] + dy))

    return migrations


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: Enter name of a single image and the # of iterations to apply.")
        sys.exit()

    random.seed()

    imname = sys.argv[1]
    iterations = int(sys.argv[2])

    image = io.imread(imname)

    image_transformed = simplify(image, iterations)

    io.imsave(imname + "_simplified", image_transformed)
