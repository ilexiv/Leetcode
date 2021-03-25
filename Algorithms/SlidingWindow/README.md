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
* Number of Substrings Containing All Three Characters: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
* Find All Anagrams in a String: https://leetcode.com/problems/find-all-anagrams-in-a-string/
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
