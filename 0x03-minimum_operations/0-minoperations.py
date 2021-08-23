#!/usr/bin/python3

"""0x03. Minimum Operations
    """


def gcd(num):
    """Calc the greatest common divisor
    Returns:
        [int]: greatest common divisor
    """
    if not isinstance(num, int) or num <= 1:
        return 0
    if num == 2:
        return 1
    for divisor in range(num // 2 + 1, 0, -1):
        if num % divisor == 0:
            return divisor


def minOperations(n):
    """Given a number n, write a method that calculates the fewest number
    of operations needed to result in exactly n H characters in the file

    Args:
        n (int): represents the number of 'H'

    Returns:
        int: minimum copy and paste operations
    """

    if n <= 1:
        return 0

    ans = 0
    gcds = []

    while n > 1:
        gcds.append(int(gcd(n)))
        n = gcds[-1]

    for i in range(len(gcds)):
        if i == len(gcds) - 1:
            break
        ans += gcds[i] // gcds[i + 1]

    return ans
