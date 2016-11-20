prime = []          
def buildPrime (s):       #populates primes upto size s
    prime.append (2)
    
    i = 3
    while len (prime) <= s:
        flag = True
        
        j = 0
        while prime[j] * prime[j] <= i:
            if not (i % prime[j]):
                flag = False
                break
            j += 1
            
        if flag:
            prime.append (i)
            
        i += 2
        
    return prime[s]
