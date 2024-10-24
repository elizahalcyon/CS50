text = "In the great green room"
words = text.split()

# Round 1
print("Round 1")
for word in words:
    print(word)  # or print(word, end=" ")
print()

# Round 2
print("Round 2")
for word in words:
    for c in word:
        print(c)
print()

# Round 3
print("Round 3")
for word in words[2:]:
    if 'g' in word:
        print(word)
print()

# Round 4
print("Round 4")
for word in words[2:]:
    print(word)
print()

# Round 5
print("Round 5")
for _ in words: # will loop 5 times
    print("Goodnight Moon")
print()
