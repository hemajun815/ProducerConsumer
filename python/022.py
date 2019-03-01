# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）


class Solution:
    def IsPopOrder(self, pushV, popV):
        if len(pushV) == 0:
            return False
        s = []
        idx_pop = 0
        for push in pushV:
            s.append(push)
            while idx_pop < len(popV) and popV[idx_pop] == s[-1]:
                s.pop()
                idx_pop += 1
        return len(s) == 0
