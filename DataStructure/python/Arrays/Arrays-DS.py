#!/bin/python3

import math
import os
import random
import re
import sys

def reverseArray(arr):
    result = arr[::-1]
    return result


arrСount = int(input())
arr = list(map(int, input().rstrip().split()))
result = reverseArray(arr)
print(*result)
