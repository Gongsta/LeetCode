class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        ver1 = version1.split(".")
        ver2 = version2.split(".")

        if len(ver1) == len(ver2):
            for idx, _ in enumerate(ver1):
                if int(ver1[idx]) > int(ver2[idx]):
                    return 1
                elif int(ver1[idx]) < int(ver2[idx]):
                    return -1

            return 0 # Both are equal till the very end

        elif len(ver1) > len(ver2):
            for idx, _ in enumerate(ver2):
                if int(ver1[idx]) > int(ver2[idx]):
                    return 1
                elif int(ver1[idx]) < int(ver2[idx]):
                    return -1

            for i in range(len(ver2), len(ver1)):
                if int(ver1[i]) > 0: # The extra character at the end
                    return 1

            return 0 # Both are equal till the very end

        
        elif len(ver1) < len(ver2):
            for idx, _ in enumerate(ver1):
                if int(ver1[idx]) > int(ver2[idx]):
                    return 1
                elif int(ver1[idx]) < int(ver2[idx]):
                    return -1


            for i in range(len(ver1), len(ver2)):
                if int(ver2[i]) > 0: # The extra character at the end
                    return -1

            return 0 # Both are equal till the very end
