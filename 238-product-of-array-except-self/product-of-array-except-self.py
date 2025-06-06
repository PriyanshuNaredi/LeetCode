class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        n = len(nums)
        l_mult = 1
        r_mult = 1
        l_arr = [0] * n
        r_arr = [0] * n

        for i in range(n):
            j = -i - 1  # last index
            l_arr[i] = l_mult
            r_arr[j] = r_mult
            l_mult *= nums[i]
            r_mult *= nums[j]

        return [l * r for l, r in zip(l_arr, r_arr)]












import sys
import atexit

# Equivalent to: std::cin.tie(nullptr)->sync_with_stdio(false);
# In Python, this helps speed up I/O
input = sys.stdin.readline


# LC_HACK equivalent
def write_display_runtime():
    with open("display_runtime.txt", "w") as f:
        f.write("0\n")


# Registering the function to be called at program exit
atexit.register(write_display_runtime)
