#!/usr/bin/python3
"""
    Log parsing
"""
from sys import stdin


if __name__ == "__main__":

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

    try:
        for line in stdin:
            lineCount += 1
            line = line.split()
            status = int(line[7])
            size = int(line[8])
            totalSize += size
            statusCount[status] += 1
            if lineCount % 10 == 0:
                print_stat(totalSize, statusCount)

    except ValueError:
        pass

    except KeyboardInterrupt:
        print_stat(totalSize, statusCount)
        raise

    print_stat(totalSize, statusCount)
