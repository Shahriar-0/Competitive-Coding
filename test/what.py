with open("out") as f1, open("ans") as f2:
    for numLine, (line1, line2) in enumerate(zip(f1, f2), 1):
        if line1 != line2:
            print(f"Line {numLine} is wrong")
            for i, (char1, char2) in enumerate(zip(line1, line2)):
                if char1 != char2:
                    print(f"Char {i} is wrong")
                    print(f"in line1 is {char1}")
                    print(f"in line2 is {char2}")
