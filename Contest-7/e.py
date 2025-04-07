def damerau_levenshtein_distance(s, t):
    m = len(s)
    n = len(t)
    d = [[0] * (n + 1) for _ in range(m + 1)]
    
    for i in range(m + 1):
        d[i][0] = i
    for j in range(n + 1):
        d[0][j] = j
    
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            cost = 0 if s[i-1] == t[j-1] else 1
            deletion = d[i-1][j] + 1
            insertion = d[i][j-1] + 1
            substitution = d[i-1][j-1] + cost
            current_min = min(deletion, insertion, substitution)
            
            if i > 1 and j > 1 and s[i-1] == t[j-2] and s[i-2] == t[j-1]:
                transposition = d[i-2][j-2] + 1
                current_min = min(current_min, transposition)
            
            d[i][j] = current_min
    
    return d[m][n]

s = input().strip()
t = input().strip()
print(damerau_levenshtein_distance(s, t))