cmake_minimum_required(VERSION 3.0)
project(leetcpp)
set(CMAKE_PROJECT_NAME leetcpp)
set(CMAKE_BUILD_TYPE DEBUG)

## for default arch ##
set(ARCH x86_64)

# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SWNR_SRCS)
add_definitions("-std=c++11")

## problems
add_executable(ans-1 answers/1/ans.cpp)         # 1.  Two Sum
add_executable(ans-2 answers/2/ans.cpp)         # 2.  Add Two Numbers
add_executable(ans-3 answers/3/ans.cpp)         # 3.  Longest Substring Without Repeating Characters
add_executable(ans-5 answers/5/ans.cpp)         # 5.  Longest Palindromic Substring
add_executable(ans-6 answers/6/ans.cpp)         # 6.  ZigZag Conversion
add_executable(ans-7 answers/7/ans.cpp)         # 7.  Reverse Integer
add_executable(ans-9 answers/9/ans.cpp)         # 9.  Palindrome Number
add_executable(ans-11 answers/11/ans.cpp)       # 11. Container With Most Water
add_executable(ans-12 answers/12/ans.cpp)       # 12. Integer to Roman
add_executable(ans-13 answers/13/ans.cpp)       # 13. Roman to Integer
add_executable(ans-14 answers/14/ans.cpp)       # 14. Longest Common Prefix
add_executable(ans-15 answers/15/ans.cpp)       # 15. 3Sum (TLE)
add_executable(ans-17 answers/17/ans.cpp)       # 17. Letter Combinations of a Phone Number
add_executable(ans-19 answers/19/ans.cpp)       # 19. Remove Nth Node From End of List
add_executable(ans-20 answers/20/ans.cpp)       # 20. Valid Parentheses
add_executable(ans-21 answers/21/ans.cpp)       # 21. Merge Two Sorted Lists
add_executable(ans-22 answers/22/ans.cpp)       # 22. Generate Parentheses
add_executable(ans-26 answers/26/ans.cpp)       # 26. Remove Duplicates from Sorted Array 
add_executable(ans-28 answers/28/ans.cpp)       # 28. Implement strStr()
add_executable(ans-29 answers/29/ans.cpp)       # 29. Divide Two Integers
add_executable(ans-33 answers/33/ans.cpp)       # 33. Search in Rotated Sorted Array
add_executable(ans-34 answers/34/ans.cpp)       # 34. Search for a Range
add_executable(ans-36 answers/36/ans.cpp)       # 36. Valid Sudoku
add_executable(ans-38 answers/38/ans.cpp)       # 38. Count and Say
add_executable(ans-41 answers/41/ans.cpp)       # 41. First Missing Positive
add_executable(ans-42 answers/42/ans.cpp)       # 42. Trapping Rain Water
add_executable(ans-44 answers/44/ans.cpp)       # 44. Wildcard Matching (TLE)
add_executable(ans-46 answers/46/ans.cpp)       # 46. Permutations
add_executable(ans-48 answers/48/ans.cpp)       # 48. Rotate Image
add_executable(ans-49 answers/49/ans.cpp)       # 49. Group Anagrams
add_executable(ans-50 answers/50/ans.cpp)       # 50. Pow(x, n)
add_executable(ans-53 answers/53/ans.cpp)       # 53. Maximum Subarray
add_executable(ans-54 answers/54/ans.cpp)       # 54. Spiral Matrix
add_executable(ans-55 answers/55/ans.cpp)       # 55. Jump Game
add_executable(ans-56 answers/56/ans.cpp)       # 56. Merge Intervals
add_executable(ans-62 answers/62/ans.cpp)       # 62. Unique Paths
add_executable(ans-66 answers/66/ans.cpp)       # 66. Plus One
add_executable(ans-69 answers/69/ans.cpp)       # 69. Sqrt(x)
add_executable(ans-70 answers/70/ans.cpp)       # 70. Climbing Stairs
add_executable(ans-73 answers/73/ans.cpp)       # 73. Set Matrix Zeroes
add_executable(ans-75 answers/75/ans.cpp)       # 75. Sort Colors
add_executable(ans-76 answers/76/ans.cpp)       # 76. Minimum Window Substring
add_executable(ans-78 answers/78/ans.cpp)       # 78. Subsets
add_executable(ans-79 answers/79/ans.cpp)       # 79. Word Search
add_executable(ans-84 answers/84/ans.cpp)       # 84. Largest Rectangle in Histogram
add_executable(ans-88 answers/88/ans.cpp)       # 88. Merge Sorted Array
add_executable(ans-91 answers/91/ans.cpp)       # 91. Decode Ways
add_executable(ans-94 answers/94/ans.cpp)       # 94. Binary Tree Inorder Traversal
add_executable(ans-98 answers/98/ans.cpp)       # 98. Validate Binary Search Tree

# vim:fileencoding=UTF-8:ts=4:sw=4:sta:et:sts=4:ai
