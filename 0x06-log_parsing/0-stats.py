#!/usr/bin/python3
"""
    Log parsing
"""
from sys import stdin


if __name__ == "__main__":
    line_count = 0
    total_size = 0
    status_count = {
        200: 0,
        301: 0,
        400: 0,
        401: 0,
        403: 0,
        404: 0,
        405: 0,
        500: 0
    }


    def print_stat(total_size, status_count):
        """
            print stats
            args:
                total_size
                status_count
        """
        print(f"File size: {total_size}")
        for status in sorted(status_count.keys()):
            if status_count[status] > 0:
                print("{}: {}".format(status, status_count[status]))


    try:
        for line in stdin:
            line_count += 1

            line = line.split()
            status = int(line[7])
            size = int(line[8])

            total_size += size
            status_count[status] += 1

            if line_count % 10 == 0:
                print_stat(total_size, status_count)

    except ValueError:
        pass

    except KeyboardInterrupt:
        print_stat(total_size, status_count)
        raise

    print_stat(total_size, status_count)
