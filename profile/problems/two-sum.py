# Two Sum
# Given an array and a target, return indices of two numbers that add up to target.

def two_sum(nums, target):
    seen = {}
    for i, num in enumerate(nums):
        if target - num in seen:
            return [seen[target - num], i]
        seen[num] = i
    return []

if __name__ == "__main__":
    print(two_sum([2, 7, 11, 15], 9))  # [0, 1]
