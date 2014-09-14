class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        s = list(' ' + s.strip()[::-1] + ' ')
        st = 0
        space_counts = 0
        word_counts = 0
        in_a_word = False
        for i in xrange(len(s)):
            if s[i] == ' ':
                space_counts +=1
                if in_a_word == True:
                    s[st:i] = s[st:i][::-1]
                    offset = space_counts - word_counts - 1 # last one for the end ' '
                    s[st-offset:i-offset] = s[st:i]
                    s[i-offset:i] = [' '] * offset
                    word_counts +=1
                    in_a_word = False
            elif not in_a_word:
                st = i
                in_a_word = True
        return ''.join(s[: word_counts - space_counts - 1 ])


