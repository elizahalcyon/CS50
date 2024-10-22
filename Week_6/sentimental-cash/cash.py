from cs50 import get_float
import math


change, coins = 0, 0

while True:
    change = get_float("Change owed: ")
    if change > 0:
        break
    else:
        print("Enter a positive number")

coins = math.floor(change / 0.25)
change = round((change % 0.25), 2)

coins += math.floor(change / 0.1)
change = change % 0.1

coins += math.floor(change / 0.05)
coins += math.ceil(change % 0.05)

print(coins)
