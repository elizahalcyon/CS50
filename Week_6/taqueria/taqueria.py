import sys

# Create menu dictionary
menu = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}
# Set total amount, variable used to keep track of amount of order
total_amount = 0
# Loop forever
while True:
    try:
        # Get user input - (.title makes it capitalized/title cased)
        item = input("Item: ").title()
        # Check if item is already in the dictionary
        if item in menu:
            # Add the item price to the total amount
            total_amount += menu[item]
            # Print the current total amount
            print("Total: $", end="")
            # Get two decimal places
            print("{:.2f}".format(total_amount))
    except EOFError:
        #Print a new line and stop the loop
        print()
        break
