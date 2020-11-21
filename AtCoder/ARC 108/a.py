"""
We need to find n, m such that n+m = s and nm = p. Solving the system of
equations for n, we obtain n^2 - sn + p = 0. In order for this to be an
integer, we need the discriminant, d = s^2 - 4p, to be a perfect square,
and we need s + sqrt(d) to be divisible by 2. To check if a number is a
perfect square, we can use binary search.

I used Python for this problem because my solution requires squaring
large numbers that will not fit into 64-bit integers.
"""

s, p = map(int, input().split())

d = s**2 - 4*p
if d < 0:
    print('No')
else:
    lo = 0
    hi = int(1e18)
    ans = -1
    while lo <= hi:
        mid = (lo+hi)//2
        if mid*mid == d:
            ans = mid
            break
        elif mid*mid > d:
            hi = mid-1
        else:
            lo = mid+1
    
    if ans == -1:
        print('No')
    elif (s+ans)%2 == 0:
        print('Yes')
    else:
        print('No')