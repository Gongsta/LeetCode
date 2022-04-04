class Solution:
    def isValid(self, s: str) -> bool:
        stack = list()
        match_dict = {")":"(", "}": "{", "]": "["}
        for bracket in s:
            if bracket == ")" or bracket == "}" or bracket ==  "]":
                if len(stack) == 0:
                    return False
                l = stack.pop()
                if match_dict[bracket] != l:
                    return False
            else:
                stack.append(bracket)
        

        return len(stack) == 0

        
