<h2><a href="https://leetcode.com/problems/perfect-rectangle/">391. Perfect Rectangle</a></h2>
<hr>
<p>
<a href="./perfect_rectangle.cpp">Solution</a>
</p>
<p>
Given an array <code>rectangles</code> where <code>rectangles[i] = [x<sub>i</sub>, y<sub>i</sub>, a<sub>i</sub>, b<sub>i</sub>]</code> represents an axis-aligned rectangle. The bottom-left point of the rectangle is <code>(x<sub>i</sub>, y<sub>i</sub>)</code> and the top-right point of it is <code>(a<sub>i</sub>, b<sub>i</sub>)</code>.

Return <code>true</code> <i>if all the rectangles together form an exact cover of a rectangular region.</i>

</p>
<br>
<p>
<strong>Example 1:</strong>
<br>
<img src="https://assets.leetcode.com/uploads/2021/03/27/perectrec1-plane.jpg" style="width: 300px; height: 294px;" />
<pre>
<strong>Input:</strong> rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
<strong>Output:</strong> true
<strong>Explanation:</strong> All 5 rectangles together form an exact cover of a rectangular region.
</pre>
</p>
<p>
<strong>Example 2:</strong>
<br>
<img src="https://assets.leetcode.com/uploads/2021/03/27/perfectrec2-plane.jpg" style="width: 300px; height: 294px;" />
<pre>
<strong>Input:</strong> rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
<strong>Output:</strong> false
<strong>Explanation:</strong> Because there is a gap between the two rectangular regions.
</pre>
</p>
<p>
<strong>Example 3:</strong>
<br>
<img src="https://assets.leetcode.com/uploads/2021/03/27/perfectrec3-plane.jpg" style="width: 300px; height: 294px;" />
<pre>
<strong>Input:</strong> rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
<strong>Output:</strong> false
<strong>Explanation:</strong> Because two of the rectangles overlap with each other.
</pre>
</p>
<br>
<strong>Constraints:</strong>
<ul>
<li><code>1 <= rectangles.length <= 2 * 10<sup>4</sup></code></li>
<li><code>rectangles[i].length == 4</code></li>
<li><code>-10<sup>5</sup> <= x<sub>i</sub>, y<sub>i</sub>, a<sub>i</sub>, b<sub>i</sub> <= 10<sup>5</sup></code></li>
</ul>
</p>
