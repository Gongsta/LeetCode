class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        """
        Cases:
        1. No overlap
        2. end_new in front of start_old
        3. start_new behind of end_old
        4. start_new and end_new enclose start_old and end_old
        """
        merged_intervals = []
        meetings.sort()

        curr_start, curr_end = meetings[0]

        for meeting_idx in range(1, len(meetings)):
            start, end = meetings[meeting_idx]
            # separate interval
            if start > curr_end:
                merged_intervals.append((curr_start,curr_end))
                curr_start = start
                curr_end = end
            else: # merge this interval
                curr_end = max(end, curr_end)

        merged_intervals.append((curr_start,curr_end))
        
        ans = 0
        prev_free = 1
        for start, end in merged_intervals:
            ans += start - prev_free
            prev_free = end + 1
        ans += days + 1 - prev_free
        return ans


                

        