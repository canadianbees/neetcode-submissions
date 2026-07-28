from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        anagram_record = defaultdict(list)        

        for word in strs:

            sorted_word = ''.join(sorted(word))

            anagram_record[sorted_word].append(word)

        return list(anagram_record.values())