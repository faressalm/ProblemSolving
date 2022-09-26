class Solution(object):
    def lengthOfLastWord(self, s):
        words = s.split(" ")
        for i in range(len(words)-1, -1, -1):
            if len(words[i])!=0:
              return len(words[i])
        return 0