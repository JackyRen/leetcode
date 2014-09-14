# LeetCode

## Jump Game

### Time
maybe O(n), may be depending on data

### Space
O(1)

##python code
### main.py
the starting point  
    `python2 main.py`
### tests.py
testcases stores here  
using `yield` to push your testcases
### libs.py
some libs

### Details
    mataining `max_reachable_index`  and `last_max_reachable_index`.
    lm_new = m_old
    m_new = max{[i+A[i] for i in [lm_old,m_old] ]}

    True when max_reach >= len(A)-1
    False when last_max_reachable_index >= max_reachable_index


