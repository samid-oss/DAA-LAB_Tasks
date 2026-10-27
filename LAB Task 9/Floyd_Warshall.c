#include &lt;stdio.h&gt;
#define INF 99999
int main() {
int n, i, j, k;
int cost[10][10];
printf(&quot;Enter number of vertices: &quot;);
scanf(&quot;%d&quot;, &amp;n);
printf(&quot;Enter the adjacency matrix (use 99999 for INF):\n&quot;);
for (i = 0; i &lt; n; i++) {
for (j = 0; j &lt; n; j++) {
scanf(&quot;%d&quot;, &amp;cost[i][j]);
}
}
for (k = 0; k &lt; n; k++) {
for (i = 0; i &lt; n; i++) {
for (j = 0; j &lt; n; j++) {
if (cost[i][k] != INF &amp;&amp; cost[k][j] != INF &amp;&amp;
cost[i][k] + cost[k][j] &lt; cost[i][j]) {
cost[i][j] = cost[i][k] + cost[k][j];
}
}
}
}
printf(&quot;\nShortest Distance Matrix:\n&quot;);
for (i = 0; i &lt; n; i++) {
for (j = 0; j &lt; n; j++) {
if (cost[i][j] == INF)
printf(&quot;INF\t&quot;);
else
printf(&quot;%d\t&quot;, cost[i][j]);
}
printf(&quot;\n&quot;);
}
return 0;
}
