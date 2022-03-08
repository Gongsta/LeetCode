class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        """
        We need to check 3 things. By row. Vertically. and in the 9-cell grids
        """
        # Check Horizontally
        for row in board:
            hash_table = {}
            for element in row:
                if element in hash_table:
                    return False
                else:
                    hash_table[element] = True

        # Check vertically
        for i in range(9):
            hash_table = {}
            for row in board:
                if row[i] in hash_table:
                    return False
                else:
                    hash_table[row[i]] = True

        # Check in the 9x9 grids
        while m < 9 and n < 9:
            hash_table = {}
            for i in range(n, n+3):
                for j in range(m, m+3):
                    if board[i][j] in hash_table:
                        return False
                    else:
                        hash_table[board[i][j]] = True

            if m == 6: # move vertically and back to the left
                m = 0
                n += 3
            
            else:  # Move horizontally
                m += 3

            
        return True








        
