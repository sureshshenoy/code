"""
Determine if the brackets are matching in a string

>>> matchingBrackets('{ab}')
True
>>> matchingBrackets('ab')
True
>>> matchingBrackets('}ab{')
False
>>> matchingBrackets('}ab')
False
>>> matchingBrackets('{a[b}c]')
False
>>> matchingBrackets('{a[b]c}')
True
"""
def matchingBrackets(input):
    stack = []
    chars = list(input)
    for char in chars:
        if (char == '{') or (char == '[') or (char == '('):    
            stack.append(char)
        elif (char == '}'):
            if len(stack) > 0:
                if stack.pop() != '{':
                    return False 
            else:
                return False
        elif (char == ']'):
            if len(stack) > 0:
                if stack.pop() != '[':
                    return False
            else:
                return False
        elif (char == ')'):
            if len(stack) > 0:
                if stack.pop() != '(':
                    return False
            else:
                return False

    if len(stack):
        return False
    else:
        return True
