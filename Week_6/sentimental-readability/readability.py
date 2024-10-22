from cs50 import get_string

text = get_string("Text: ")
text_length = len(text)

letter = 0
word = 1
sentence = 0

for i in range(text_length):
    if text[i].isalpha():
        letter += 1

for i in range(text_length):
    if text[i] == " ":
        word += 1

for i in range(text_length):
    if text[i] == "." or text[i] == "?" or text[i] == "!":
        sentence += 1

# 0.0588 * L - 0.296 * S - 15.8

L = float(letter / word * 100)
S = float(sentence / word * 100)

index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade ", index)
