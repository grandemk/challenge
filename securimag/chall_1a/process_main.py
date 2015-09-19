def main():
    main_file = "main.c"
    main_outfile = "main2.c"
    with open(main_file, "r") as infile, open(main_outfile, "w") as outfile:
        for line in infile:
            if line.find("%del%") != -1:
                continue
            index = line.find("%uncomment%")
            if index != -1:
                line = line[(index + len("%uncomment%")):]

            outfile.write(line)


if __name__ == "__main__":
    main()
