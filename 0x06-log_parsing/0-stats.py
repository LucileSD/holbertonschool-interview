#!/usr/bin/python3
"""
    Log parsing
"""
from sys import stdin


lineCount = 0
totalSize = 0
statusCount = {
    200: 0,
    301: 0,
    400: 0,
    401: 0,
    403: 0,
    404: 0,
    405: 0,
    500: 0
}


def print_stat(totalSize, statusCount):
    """
        print stats
        args:
            total_size
            status_count
    """
    print(f"File size: {totalSize}")
    for status in sorted(statusCount.keys()):
        if statusCount[status] > 0:
            print("{}: {}".format(status, statusCount[status]))

    if __name__ == "__main__":
        try:
            for line in stdin:
                lineCount += 1
                try:
                    line = line.split()
                    size = int(line[-1])
                    totalSize += size
                    status = int(line[-2])
                    if status in statusCount.keys():
                        statusCount[status] += 1
                except ValueError:
                    pass
                if lineCount % 10 == 0:
                    print_stat(totalSize, statusCount)

        except KeyboardInterrupt:
            print_stat(totalSize, statusCount)

    print_stat(totalSize, statusCount)
