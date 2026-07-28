class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        record = {}

        for number in nums:

            if number in record:

                record[number] += 1

            else:
                record[number] = 1

        sorted_record = sorted(record.items(), key=lambda x:x[1], reverse=True)
        top_nums = []

        for i in range(k):

            top_nums.append(sorted_record[i][0])

        return top_nums



