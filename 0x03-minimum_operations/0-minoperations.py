#!/usr/bin/python3

"""0x03. Minimum Operations
    """


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

    for i in range(2, n + 1):
        while n % i == 0:
            ans += i
            # smaller problem
            n = n / i

    return ans
