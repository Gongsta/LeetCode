class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        n = len(answerKey)
        max_len = 0

        for letter in ['T', 'F']:
            left = 0
            num_changes = 0

            for right in range(n):
                if answerKey[right] != letter:
                    num_changes += 1

                while num_changes > k:
                    if answerKey[left] != letter:
                        num_changes -= 1
                    left += 1

                max_len = max(max_len, right - left + 1)

        return max_len