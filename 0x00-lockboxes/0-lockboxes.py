#!/usr/bin/python3

"Lockboxes problem"


def canUnlockAll(boxes):
    """
    You have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1 and
    each box may contain keys to the other boxes.

    Write a method that determines if all the boxes can be opened.

    Prototype: def canUnlockAll(boxes)
    boxes is a list of lists
    A key with the same number as a box opens that box
    You can assume all keys will be positive integers
    There can be keys that do not have boxes
    The first box boxes[0] is unlocked
    Return True if all boxes can be opened, else return False
    """

    n_boxes = len(boxes)
    if not boxes or n_boxes <= 0:
        return False

    initial_keys = [0]

    for key in initial_keys:
        for k_box in boxes[key]:
            if 0 < k_box < n_boxes and k_box not in initial_keys:
                initial_keys.append(k_box)

    if len(initial_keys) == n_boxes:
        return True

    return False
