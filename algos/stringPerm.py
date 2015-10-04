"""
Find all the permutations of a given string

>>> permutations('ab')
['ba', 'ab']

"""
def permutations(word):
    if len(word)<=1:
        return [word]
    # find all the permutations
    perms = permutations(word[1:]) 
    pivot = word[0]
    result = []
    for perm in perms:
        for i in range(len(perm) + 1):
            result.append(perm[i:] + pivot + perm[:i])
    return result

