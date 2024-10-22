# Prompt for greeting, force to lowercase
greeting = input("Greeting: ")
g = greeting.lower().lstrip()

# Access first word in greeting, check if it's 'hello'
var = g.split(' ')[0]
if var[0:5] == 'hello':
    print("$0")
elif var[0] == 'h':
    print("$20")
else:
    print("$100")
