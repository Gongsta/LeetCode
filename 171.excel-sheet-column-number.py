class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        final_int = 0
        for idx, letter in enumerate(columnTitle):
            multiplier = len(columnTitle) - idx - 1
            
            final_int += 26**multiplier * (ord(letter.lower()) - 96)

        return final_int

        

