#!/usr/bin/python3
"""
    Log parsing
"""
import sys

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

try:
    for line in sys.stdin:
        line_count += 1

        try:
            line = line.split()
            status = int(line[7])
            size = int(line[8])

            total_size += size
            status_count[status] += 1

        except ValueError:
            continue

        if line_count % 10 == 0:
            print(f"File size: {total_size}")
            for status in sorted(status_count.keys()):
                if status_count[status] > 0:
                    print(f"{status}: {status_count[status]}")

except KeyboardInterrupt:
    print(f"File size: {total_size}")
    for status in sorted(status_count.keys()):
        if status_count[status] > 0:
            print(f"{status}: {status_count[status]}")