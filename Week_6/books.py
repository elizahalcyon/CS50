books = []

# Add three books to your shelf
for i in range(3):
    book = dict()
    book["title"] = input("Title: ").strip().capitalize()
    book["author"] = input("Author: ")

    books.append(book)

for book in books:
    print(book["title"])

# print(books) would print entire list

