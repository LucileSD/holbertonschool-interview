#!/usr/bin/python3
"""determine if all the boxes can be opened"""


def canUnlockAll(boxes):
    """function if we can open all boxes
        boxes: a list of lists
        Return True if all boxes can be opened, else return False
    """
    unlocked = [0]
    for box_idx, box in enumerate(boxes):
        for key in box:
            if key < len(boxes) and key not in unlocked and key != box_idx:
                unlocked.append(key)
    return len(unlocked) == len(boxes)
