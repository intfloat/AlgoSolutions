class Solution:
    def replaceWords(self, dict: List[str], sentence: str) -> str:
        d = set(dict)
        words = sentence.split()
        res = []
        for w in words:
            has_root = False
            for i in range(len(w)):
                if w[:i] in d:
                    res.append(w[:i])
                    has_root = True
                    break
            if not has_root:
                res.append(w)
        return ' '.join(res)
