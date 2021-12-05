import calendar

if __name__ == "__main__":
    n = int(input())

    if calendar.isleap(n):
        print("Wonderful")
    else:
        print("Orz")
