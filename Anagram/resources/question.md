## Anagram Check

Given two strings, determine whether they are anagrams of each other.

### Input
Two strings, str1 and str2 (1 <= length of str1, str2 <= 10^5)

### Output
A boolean value indicating whether the strings are anagrams or not

### Examples

#### Example 1
```
Input : "listen", "silent"
Output : true
```


#### Example 2

```
Input : "hello", "world"
Output : false
```

### Complexity

- Time complexity: O(nlogn), where n is the length of the longest string
- Space complexity: O(1)

### Hints
- Sort the characters in both strings and compare the sorted strings
- Use a dictionary to count the occurrences of each character in the strings and compare the dictionaries

### Constraints
- The strings can include uppercase and lowercase letters, as well as special characters and spaces.