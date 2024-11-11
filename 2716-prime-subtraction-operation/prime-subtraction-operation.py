from math import isqrt

class Solution:
    def primeSubOperation(self, nums):
        max_element = max(nums)

        # Create sieve array for prime checking
        sieve = [1] * (max_element + 1)
        sieve[1] = 0
        for i in range(2, isqrt(max_element) + 1):
            if sieve[i] == 1:
                for j in range(i * i, max_element + 1, i):
                    sieve[j] = 0

        # Initialize curr_value to 1 and index to 0
        curr_value = 1
        i = 0

        while i < len(nums):
            # Calculate the difference needed to make nums[i] equal to curr_value
            difference = nums[i] - curr_value

            # If difference is less than 0, nums[i] is already less than curr_value
            if difference < 0:
                return False

            # If the difference is prime or zero, we can make nums[i] equal to curr_value
            if sieve[difference] == 1 or difference == 0:
                i += 1
                curr_value += 1
            else:
                # Otherwise, try for the next curr_value
                curr_value += 1

        return True
