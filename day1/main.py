number_map = { 'one' : 1, 'two': 2, 'three': 3, 'four': 4, 'five': 5, 'six': 6, 'seven': 7, 'eight': 8, 'nine': 9}

def replace_words_with_numbers(line: str) -> str:
    for word, number in number_map.items():
        line = line.replace(word, (word[0] + str(number) + word[-1]))
    return line

def getvalues(word: str) -> int:
    filtered = list(filter(lambda x: x.isdigit(), word))
    return int(f"{filtered[0]}{filtered[-1]}")

def part1(input_file):
    count = 0
    for line in input_file:
        count += getvalues(line)
    return count

def part2(input_file):
    count = 0
    for line in input_file:
        newline = replace_words_with_numbers(line)
        count += getvalues(newline)
    return count

with open("input", "r") as f:
    input_file = f.readlines()
    #removing newline at end of string
    input_file = [v.strip() for v in input_file]

print("Part 1: {}".format(part1(input_file)))
print("Part 2: {}".format(part2(input_file)))