nums = [1,2,3,4]
target = 7
def test(nums, target):
    for i1, num1 in enumerate(nums):
        for i2, num2 in enumerate(nums[(i1+1):]):
            print(num1, num2)
            if (num1 + num2) == target and i1 != i2:
                return [i1, i2]


result = test(nums, target)
print("The result", result)
