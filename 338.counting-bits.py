class Solution:
    def countBits(self, n: int) -> List[int]:
        final_arr = []

        for i in range(n+1):
            count = 0
            binary = bin(i)[2:]

            for char in binary:
                if char == "1":
                    count += 1
            final_arr.append(count)
        return final_arr

        
