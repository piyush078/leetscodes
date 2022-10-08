<h2><a href="https://leetcode.com/problems/elimination-game/">390. Elimination Game</a></h2>
<hr>
<p>
<a href="./elimination_game.cpp">Solution</a>
</p>
<p>

You have a list <code>arr</code> of all integers in the range <code>[1, n]</code> sorted in a strictly increasing order. Apply the following algorithm on <code>arr</code>:
<lu>

<ul>
<li>Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.</li>
<li>Repeat the previous step again, but this time from right to left, remove the rightmost number and every other number from the remaining numbers.</li>
<li>Keep repeating the steps again, alternating left to right and right to left, until a single number remains.</li>
</ul>
Given the integer <code>n</code>, return <i>the last number that remains in</i> <code>arr</code>.

</p>
<br>
<p>
<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> n = 9
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
arr = [2, 4, 6, 8]
arr = [2, 6]
arr = [6]
</pre>
</p>
<p>
<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> 1
</pre>
</p>
<br>
<strong>Constraints:</strong>
<ul>
<li><code>1 <= n <= 10<sup>9</sup></code></li>
</ul>
</p>
