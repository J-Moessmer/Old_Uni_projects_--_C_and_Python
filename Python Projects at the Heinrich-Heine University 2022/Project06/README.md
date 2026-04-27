# PA06

### Task 1: Print Postal Codes of Schools
Write a programm that reads the given list containing 10 dictionaries of schools, print the postal codes of each school line by line.

#### Flowchart
```mermaid
flowchart TD
    A[List of Dictionaries] --> B[Loop through dictionaries]
    B --> C[Extract 'address' field]
    C --> D[Extract postal code from address string]
    D --> E[Print postal code]
```

#### Code Snippet
```python
schools = [{'address': 'Stolberger Str. 112, 50933'}, {'address': 'Walder Straße 15, 42781'}]

for school in schools:
    address = school.get('address', '')
    # The postal code is typically the last part of the address
    plz = address.split()[-1]
    print(plz)
```

---

### Task 2: Braille to ASCII Converter
Write a programm that reads `Braille.txt` and converts the braille text to ASCII fulltext.

#### Flowchart
```mermaid
flowchart TD
    A[Open 'Braille.txt'] --> B[Read file contents]
    B --> C[Define Translation Dictionary Mapping Braille to ASCII]
    C --> D[Loop through dictionary keys]
    D --> E[Replace Braille char with ASCII char in text]
    E --> F[Print full converted text]
```

#### Code Snippet
```python
with open("braille.txt", encoding="utf-8") as f:
    text = f.read()

char_to_replace = {
    '⠁': 'a', '⠃': 'b', '⠉': 'c', '⠙': 'd', '⠑': 'e',
    '⠋': 'f', '⠛': 'g', '⠓': 'h', '⠊': 'i', '⠚': 'j',
    # ... more mappings
}

for braille, ascii_char in char_to_replace.items():
    text = text.replace(braille, ascii_char)

print(text)
```

---

### Task 3: Character Frequency Counter
Write a programm that reads `grimm.txt` and counts how often each ASCII character is used.

#### Flowchart
```mermaid
flowchart TD
    A[Open 'grimm.txt'] --> B[Read file contents]
    B --> C[Create Dictionary / Counter for chars]
    C --> D[Count occurrences of each char in text]
    D --> E[Sort dictionary by values in descending order]
    E --> F[Print char and its count]
```

#### Code Snippet
```python
with open("grimm.txt", encoding="utf-8") as f:
    text = f.read()

# Using dictionary comprehension to count frequencies
char_counts = {char: text.count(char) for char in set(text)}

# Remove newline counts for cleaner output
if "\n" in char_counts:
    del char_counts["\n"]

# Sort by count (descending)
sorted_counts = sorted(char_counts.items(), key=lambda x: x[1], reverse=True)

for char, count in sorted_counts:
    print(repr(char), count)
```
