from math import sqrt
px, py, vx, vy, a, b, c, d = map(float, raw_input().split())
def normalize(x, y):
    tot = sqrt(x * x + y * y)
    return x / tot, y / tot
vx, vy = normalize(vx, vy)
ux, uy = -vy, vx

print px + b * vx, py + b * vy
print px + a / 2 * ux, py + a / 2 * uy
print px + c / 2 * ux, py + c / 2 * uy
print px + c / 2 * ux - d * vx, py + c / 2 * uy - d * vy
print px - c / 2 * ux - d * vx, py - c / 2 * uy - d * vy
print px - c / 2 * ux, py - c / 2 * uy
print px - a / 2 * ux, py - a / 2 * uy
