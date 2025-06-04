class Solution:
    def frequencySort(self, s: str) -> str:
        '''
        # 1. O(n)
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
        #                       /OR/
        res = []
        buckets = [ [] for _ in range(len(s) + 1) ]

        for c, freq in Counter(s).items():
            buckets[freq].append(c)

        for freq in reversed(range(len(buckets))):
            for c in buckets[freq]:
                res.append(c * freq)

        return "".join(res)

        # {a:1, b:1, c:1, d:2, f:3}
        # [
        #     [a,b,c] -> 1
        #     [d] -> 2
        #     [f] -> 3
        # ]

        

        '''
        # 2. O(n log n)
        freq = {}

        for c in s:
            freq[c] = 1 + freq.get(c, 0) 
        # if c is not present then it will make the entry in the table then it will return 0
        
        freq = sorted(freq.items(), key = lambda x: -x[-1])
        # -x[] : because we want freq to sorted in descending order i.e. by adding - sign 
        # x[] = 5, 10 => descending order -x[] = -10, -5

        return ''.join([key * val for key, val in freq])
        '''

        '''
        # 3. O(n logn)
        freq = Counter(s) # char -> cnt

        max_heap = []

        for key, val in freq.items():
            # By default py uses mean heap; i.e. - val is used
            heapq.heappush(max_heap, [-val, key])

        res = ""

        for _ in range(len(max_heap)):
            val, key = heapq.heappop(max_heap)
            res += key * (-val)

        return res
        '''









