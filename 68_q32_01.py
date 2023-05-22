height = 4
width = 7
str = ""
tatami = [[0] * (width + 2) for _ in range(height + 2)]

def printTatami():
    global str
    for i in range(1, height + 1):
        for j in range(1, width + 1):
            if tatami[i][j] == tatami[i][j + 1] or tatami[i][j] == tatami[i][j - 1]:
                str += "-"
            if tatami[i][j] == tatami[i + 1][j] or tatami[i][j] == tatami[i - 1][j]:
                str += "|"
        str += "\n"
    str += "\n"

def setTatami(h, w, id):
    if h == height + 1:
        printTatami()
    elif w == width + 1:
        setTatami(h + 1, 1, id)
    elif tatami[h][w] > 0:
        setTatami(h, w + 1, id)
    else:
        if tatami[h - 1][w - 1] == tatami[h - 1][w] or tatami[h - 1][w - 1] == tatami[h][w - 1]:
            if tatami[h][w + 1] == 0:
                tatami[h][w] = tatami[h][w + 1] = id
                setTatami(h, w + 2, id + 1)
                tatami[h][w] = tatami[h][w + 1] = 0
            if tatami[h + 1][w] == 0:
                tatami[h][w] = tatami[h + 1][w] = id
                setTatami(h, w + 1, id + 1)
                tatami[h][w] = tatami[h + 1][w] = 0

setTatami(1, 1, 1)
print(str)