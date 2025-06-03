class Solution:
    def frequencySort(self, s: str) -> str:
        
        # 1.
        count = Counter(s) # char -> count
        buckets = defaultdict(list) # freq -> char

        for char, cnt in count.items():
            buckets[cnt].append(char)
        
        res = ""
        for i in range(len(s), 0, -1):
            for c in buckets[i]:
                res += c * i
        
        return res
        

        '''
        # 2. O(n log n)
        freq = {}

        for c in s:
            freq[c] = 1 + freq.get(c, 0) 
            # if c is not present then it will make the entry in the table then it will return 0
        
        freq = sorted(freq.items(), key = lambda x: -x[-1])
        # -x[] : because we want freq to sorted in descending order by adding - sign 
        # x[] = 5, 10 => descending order -x[] = -10, -5

        return ''.join([key * val for key, val in freq])
        '''



