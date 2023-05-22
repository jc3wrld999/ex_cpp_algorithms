def route(width, height, back_y):
    if width == 1:
        return back_y if back_y == height else back_y + 2
    if height == 1:
        return 2 if back_y == 0 else 1
    total = 0
    if back_y == 0:
        for i in range(height):
            total += 2 * route(width - 1, height, i + 1)
    else:
        for i in range(back_y, height + 1):
            total += route(width - 1, height, i)
        total += route(width, height - 1, back_y - 1)
    return total

print(route(6, 6, 0))