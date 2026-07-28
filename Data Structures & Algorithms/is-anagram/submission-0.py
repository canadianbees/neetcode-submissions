class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        if not s or not t:
            return False

        if len(s) != len(t):
            return False

        sorted_s = ''.join(sorted(s))
        sorted_t = ''.join(sorted(t))


        for index, char in enumerate(sorted_s):

            if char != sorted_t[index]:
                return False

        return True





        
        