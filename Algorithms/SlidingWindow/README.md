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

        Two left and right pointers are introduced and points to index 0, we are
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
    <details><summary>Solution</summary><p>

        Two left and right pointers are introduced and points to index 0.
        We want to save the tree type and it's frequency, like fruit[2] = 3.
        We are iterating through the input vector using the right pointer
        and calculate fruit type occurance using unordered map.
        While size of the map exceed the 2 basket, we need to update
        returned result by getting maximum from current result and right - left.
        Also wee need to decrease the current window by increasing left pointer
        and decreasing frequency of the fruit in the hmap. If the frequency of the fruit
        type is equal to zero, we need to erase it from the hmap.
        Input: [1,2,3,2,2]
        Output: 4
        Explanation: collect [2,3,2,2].
 
</p></details>

* Longest Substring with At Most Two Distinct Characters: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
    <details><summary>Solution</summary><p>

        Two left and right pointers are introduced and points to index 0.
        We want to save the char and it's frequency, like hmap[a] = 3.
        We are iterating through the input string using the right pointer
        and save char frequency using unordered map.
        While size of the map exceed the 2, we need to update returned result by
        getting maximum from current result and right - left.
        Also wee need to decrease the current window by increasing left pointer
        and decreasing frequency of the char in the hmap. If the frequency of the char
        is equal to zero, we need to erase it from the hmap.
        Input: s = "ccaabbb"
        Output: 5
        Explanation: The substring is "aabbb" which its length is 5.
 
</p></details>

* Number of Substrings Containing All Three Characters: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
    <details><summary>Solution</summary><p>

        Two left and right pointers are introduced and points to index 0.
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

* Subarrays with K Different Integers: https://leetcode.com/problems/subarrays-with-k-different-integers/
    <details><summary>Solution</summary><p>

        The returned result could be the: return Exact(A, K) - Exact(A, K - 1);
        Where Exact() function can be implemented as described below:
        Two left and right pointers are introduced and points to index 0.
        We want to save the integer and it's frequency, like hmap[7] = 3.
        We are iterating through the input vector using the right pointer
        and save integer frequency using unordered map.
        While size of the map exceed K, we keep decreasing the current window by
        increasing left pointer and decreasing frequency of the integer in the hmap.
        If the frequency of the integer is equal to zero, we need to erase it from the hmap.
        After that we need to update the returned result, by adding to res: the length between
        right and left pointer: res += right - left + 1;
        Input: nums = [1,2,1,3,4], k = 3
        Output: 3
        Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 
</p></details>

**Arrays with pointers(indices):**
* Max Consecutive Ones III: https://leetcode.com/problems/max-consecutive-ones-iii/
    <details><summary>Solution</summary><p>

        Two left and right pointers are introduced and points to index 0.
        We are iterating through the input vector using the right pointer
        and increase the count if we met 0 in the input vector (means that we can flip it).
        While count exceed K, we keep decreasing the current window by
        increasing left pointer. While doing that we check if the vactor at left index is
        euqal to 0, and if so we decrease the count. Like vector[left] == 0 -> count--;
        After that we need to update the returned result: res = max(res, right - left + 1);
        Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
        Output: 6
        Explanation: [1,1,1,0,0,1,1,1,1,1,1]
 
</p></details>

* Minimum Size Subarray Sum: https://leetcode.com/problems/minimum-size-subarray-sum/
    <details><summary>Solution</summary><p>

        Two left and right pointers are introduced and points to index 0.
        We are iterating through the input vector using the right pointer
        and subtract the current vector value form target: target -= vector[right].
        While target <= 0, we keep decreasing the current window by
        increasing left pointer. While doing that we increase the target += vector[left]
        and calulating the returned result: res = min(res, right - left + 1);
        Input: target = 7, nums = [2,3,1,2,4,3]
        Output: 2
        Explanation: The subarray [4,3] has the minimal length under the problem constraint.
 
</p></details>

* Maximum Points You Can Obtain from Cards: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
    <details><summary>Solution</summary><p>

        Two left and right pointers are introduced to keep the sum from left and right.
        First, calculate the sum from the left part of the array from 0 to K.
        Then we are iterating thorugh the input array and keep increasing right 
        window of the array, while decreasing left part:
         * As a first step we decrease the current calulated result from the first step
           by removing the last element from the left part, like: left -= cardPoints[K - ind - 1].
         * Then we increase the current calculated result by adding the first element form the
           right part, like: right += cardPoints[size - ind - 1].
         * And finally we save the maximum of the current window:  ans = max(ans, left + right); 
        Input: cardPoints = [1,2,3,4,5,6,1], k = 3
        Output: 12
        Explanation: After the first step, your score will always be 1. However, choosing the
        rightmost card first will maximize your total score. The optimal strategy is to take the three
        cards on the right, giving a final score of 1 + 6 + 5 = 12.
 
</p></details>

* Maximum distance between pairs of values: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
    <details><summary>Solution</summary><p>

        Two ind1 and ind2 pointers are introduced and points to index 0 to different vectors.
        We are iterating through the input vectors using the ind1 and ind2 pointers together.
        There are two possible scenarios:
        * If the nums1[ind1] > nums2[ind2]: then we just increase the ind1.
        * Otherwise, we calculate the distance between two indicies and update the return
          result value if necessary: dist = max(dist, ind2 - ind1);
        Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
        Output: 2
        Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
        The maximum distance is 2 with pair (2,4).
 
</p></details>

**Dequeue approach:**
* Sliding Window Maximum: https://leetcode.com/problems/sliding-window-maximum/
    <details><summary>Solution</summary><p>

        Introduce deque to hold the indices of the input vector AND the front of the deque
        will always point to the current maximum value in the window.
        At a first step we update the deque for the current given window K:
        * While the deque is not empty AND the current value of the input vector is
          higher than vector value from the deque end -> keep removing the element from
          the back of the deque: while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        * Insert the current index to the deque at the end.
        At the end of this step we will know that we have the maximum value in the FRONT of the deque.
        Then keep iterating thorught the input vector starting from the K position:
        * Push the vector value by using index from the FRONT deque to the result vector.
        * While the deque is not empty AND the fromt index of the deque is less than
          current index minis window size -> keep removing the element from
          the FRONT of the deque: while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        * While the deque is not empty AND the current value of the input vector is
          higher than vector value from the deque end -> keep removing the element from
          the back of the deque: while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        * Insert the current index to the deque at the end.
 
</p></details>

* Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
    <details><summary>Solution</summary><p>

        Two left and right pointers are introduced and points to index 0.
        Introduce two deque mind and maxd, so the front() will hold the
        minimum/maximum value by the current point.
        While iterating through the input vector using right pointer we need:
        * Keep mind amd maxd in sync, so they will point to the current max/min
          value by the current point, like:
          while (!maxd.empty() && maxd.back() < nums[i]) maxd.pop_back();
          while (!mind.empty() && mind.back() > nums[i]) mind.pop_back();
        * Insert the current element to mind and maxd.
        * If the difference between two front deque elemens exceed the limit,
          we will try to remove the element from the deque and increase the
          left pointer.
        The returned result will be the right - left. 
        Input: nums = [8,2,4,7], limit = 4
        Output: 2 
        Explanation: All subarrays are: 
        [8] with maximum absolute diff |8-8| = 0 <= 4.
        [8,2] with maximum absolute diff |8-2| = 6 > 4. 
        [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
        [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
        [2] with maximum absolute diff |2-2| = 0 <= 4.
        [2,4] with maximum absolute diff |2-4| = 2 <= 4.
        [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
        [4] with maximum absolute diff |4-4| = 0 <= 4.
        [4,7] with maximum absolute diff |4-7| = 3 <= 4.
        [7] with maximum absolute diff |7-7| = 0 <= 4. 
        Therefore, the size of the longest subarray is 2.
 
</p></details>
* Shortest Subarray with Sum at Least K: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

**Harder questions:**
* Substring with Concatenation of All Words: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
* Minimum Window Substring: https://leetcode.com/problems/minimum-window-substring/
* Sliding Window Median: https://leetcode.com/problems/sliding-window-median/
