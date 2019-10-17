print("Wie spät ist es?")
h = int(input("Stunden: "))
min = int(input("Minuten: "))
while h >= 12:
    h -= 12
min = min * 6
h = (h * 30) + (min / 12)
if (min - h) < 0:
    if -(min-h) > 180:
        print(360+(min-h))
    else:
        print(-(min-h))
else:
    if (min - h) > 180:
        print(360 - (min - h))
    else:
        print(min - h)
input()