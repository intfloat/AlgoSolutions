class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        res = [0 for _ in range(n)]
        stack = []
        log_tp = []
        for log in logs:
            idx, cmd, tm = log.split(':')
            idx, tm = int(idx), int(tm)
            if cmd == 'end':
                tm += 1
            log_tp.append((idx, cmd, tm))
        for i, (idx, cmd, tm) in enumerate(log_tp):
            if cmd == 'start':
                if stack:
                    res[stack[-1]] += tm - log_tp[i-1][2]
                stack.append(idx)
            elif cmd == 'end':
                res[stack[-1]] += tm - log_tp[i-1][2]
                stack.pop()
        return res
