# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def __init__(self):
        self.__paths = []
        self.__path = []

    # 返回二维列表，内部每个列表表示找到的路径
    def FindPath(self, root, expectNumber):
        if root:
            self.__path.append(root.val)
            expectNumber -= root.val
            if expectNumber == 0 and root.left == None and root.right == None:
                self.__paths.append(self.__path[:])
            self.FindPath(root.left, expectNumber)
            self.FindPath(root.right, expectNumber)
            self.__path.pop()
            expectNumber += root.val
        return self.__paths
