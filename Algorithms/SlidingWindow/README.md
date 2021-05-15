# Sliding Window

**Description:**
The Sliding window is a problem-solving technique for problems that involve arrays/strings.
Generally speaking a sliding window is a sub-list that runs over an underlying collection.

**Basic tamplate that can be used to solve some sliding window problems:**

```
unordered_map<char, int> hmap;
int left = 0, right = 0;
int res = INT_MIN;
for (left = 0; left < s.size(); left++) {
    hmap[s[left]]++;
    while (hmap.size() > 2) {
        res = max(res, left - right);
        if (--hmap[s[right]] == 0) {
            hmap.erase(s[right]);
        }
        right++;
    }
}
res = max(res, left - right);
return res;
```

**Strings/Arrays hash map approach:**
* Longest Substring Without Repeating Characters: https://leetcode.com/problems/longest-substring-without-repeating-characters/
    <details><summary>Solution</summary><p>

        Two left and right pointers are introduced and points to 0, we are
        iterating through the input string using the right pointer
        and check if we already meet this character. To check if we met the
        char we use unordered map and save the index of this char to it.
        Two cases are possible: 
            1. If we met this char -> calculate the length by
               subtraction left pointer from the right, andupdate left pointer
               with the maximum index value (current or use char index that we met).
               And we still need to update the current char index in unordered map.
            2. If we didn't meet this char -> Just update the current char index in unordered map.
        Input: s = "abcabcbb"
        Output: 3
 
</p></details>

* Number of Substrings Containing All Three Characters: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
    <details><summary>Solution</summary><p>

        Two left and right pointers are introduced and points to 0.
        We are iterating through the input string using the right pointer
        and calculate number of times we met this character by using vector[3].
        Then while all three characters are exist in the array, we iterating through the
        input string using left pointer and decrease the freequence of character.
        At a last step we add left pointer to the result variable.
                 0 1 2 3 4 5 6 7 8 9
        Example: a a a b b c c a b c
        When all a, b, c > 0 for first time at position 5, then after while loop left pointer
        will be at position 3, we will add 3 to result because there would be three substrings
        from three a's. Then a,b,c > 0 at position 7 ,then we will move left pointer to position 5
        then we will add 5 to result because there could be 5 substrings starting from 0 to second b.
        At position 5: a a a b b c, a a b b c, a b b c,
        At position 7: a a a b b c c a, a a b b c c a, a b b c c a, b b c c a, b c c a,  
 
</p></details>

* Find All Anagrams in a String: https://leetcode.com/problems/find-all-anagrams-in-a-string/
    <details><summary>Solution</summary><p>

        Create a first vector1 of 26 elements and fill it with the frequences of charactes from the
        source string. Create a second vector2 of 26 elements to hold frequnces of chars for the
        target string.
        While iterating through the target string, calculate frequency for the current char and
        save it into vector2.
        If target string index is higher than size of the source string we decrease frequency
        of character at index i - size. Than we vector1 and vector2 are equal -> we save the
        i - size + 1 index to the result vector.
        Input: s = "cbaebabacd", p = "abc"
        Output: [0,6]
 
</p></details>

* Fruit Into Baskets: https://leetcode.com/problems/fruit-into-baskets/
* Longest Substring with At Most Two Distinct Characters: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
* Subarrays with K Different Integers: https://leetcode.com/problems/subarrays-with-k-different-integers/

**Arrays with pointers(indices):**
* Max Consecutive Ones III: https://leetcode.com/problems/max-consecutive-ones-iii/
* Minimum Size Subarray Sum: https://leetcode.com/problems/minimum-size-subarray-sum/
* Maximum Points You Can Obtain from Cards: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

**Dequeue approach:**
* Sliding Window Maximum: https://leetcode.com/problems/sliding-window-maximum/
* Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
* Shortest Subarray with Sum at Least K: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

**Harder questions:**
* Substring with Concatenation of All Words: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
* Minimum Window Substring: https://leetcode.com/problems/minimum-window-substring/
* Sliding Window Median: https://leetcode.com/problems/sliding-window-median/
