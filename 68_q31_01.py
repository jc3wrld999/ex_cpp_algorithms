square = 6
count = 0
is_used = [[[False, False] for _ in range(square + 1)] for _ in range(square + 1)]

def route(x, y, is_first_time):
    global count
    if x == square and y == square:
        if is_first_time:
            route(0, 0, False)
        else:
            count += 1
    if x < square:
        if not is_used[x][y][0]:
            is_used[x][y][0] = True
            route(x + 1, y, is_first_time)
            is_used[x][y][0] = False
    if y < square:
        if not is_used[x][y][1]:
            is_used[x][y][1] = True
            route(x, y + 1, is_first_time)
            is_used[x][y][1] = False

route(0, 0, True)
print(count)