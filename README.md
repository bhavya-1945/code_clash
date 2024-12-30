# Question 1
Sort and Filter the Words: First, sort the wordList alphabetically and keep only the words at even indices in the sorted list.
Check for Validity: If endWord is not in the filtered list, return 0 because no transformation sequence is possible.
Breadth-First Search (BFS): Use BFS to explore the shortest transformation sequence, starting from beginWord. BFS ensures we find the shortest path because it explores level by level.
Track Visited Words: Keep a set of visited words to avoid revisiting and infinite loops.
Transformation Condition: In BFS, only move to words that differ by exactly one letter, and ensure that each transformation uses words from the filtered list.
Return Result: If endWord is reached, return the number of steps; otherwise, return 0 if no valid sequence exists.

# Question 2
Convert each integer in the list to its binary string representation.
Remove any leading zeros from the binary strings to compare them lexicographically.
Use a stable sort to sort the integers based on their binary strings. Stable sort ensures that if two integers have the same binary representation, they remain in their original order.
The sorting is done lexicographically, meaning the binary strings are compared like words in a dictionary.
Once sorted, print the integers in the order of their binary string sort.
The approach ensures the integers are sorted by their binary representations while maintaining the relative order of equal binary values.

# Question 3
Input: We are given n teams, each with 2 members, and w weeks for scheduling. We need to ensure that all team members meet at least once within these weeks.
Goal: We need to minimize the maximum "isolation" for any pair of team members from different teams. Isolation is defined by the maximum gap between their first and last meeting week or between any two consecutive meeting weeks.
Scheduling Strategy: Use a round-robin approach where each week, one member from each team comes to the office. Alternate between team members 1 and 2 to ensure that all pairs meet.
Check Feasibility: After generating the schedule, check if every pair of members from different teams meets at least once. If not, it’s impossible to arrange the meetings within the given weeks.
Output: If a valid schedule is found, print it. Otherwise, output "infinity" if it's not possible to meet the conditions within the given weeks.

# Question 4
Goal: We need to transform a starting word into a target word by changing one letter at a time, with each intermediate word being valid from a dictionary.
BFS (Breadth-First Search) is used to find the shortest path. Each word is treated as a node, and an edge exists between words that differ by exactly one letter.
Queue: Start from the given word and explore all possible transformations, keeping track of how many transformations (steps) it took.
Visited Set: To avoid revisiting the same word, we use a set to track visited words.
Process: For each word, we try transforming it by changing one letter at a time and check if it's in the dictionary. If we reach the target word, return the number of transformations; otherwise, return -1 if it's impossible.
Time Complexity: The time complexity is O(n * m) where n is the number of words and m is the length of each word.

# Question 5
To solve this problem, we use the concept of prefix sums and modulo arithmetic:
Prefix Sum: We calculate the cumulative sum of elements up to each index in the array.
Modulo Operation: A subarray sum is divisible by k if the difference between two prefix sums has the same remainder when divided by k. So, we store the remainder of the prefix sum when divided by k.
Use a HashMap: We maintain a hashmap to track how many times each remainder has appeared. If a remainder appears again, it means there exists a subarray whose sum is divisible by k.
Counting Magical Subarrays: For each element in the array, we update the prefix sum and check how many times the same remainder has been seen before. If it has, we count it as a valid subarray.
Time Complexity: The approach runs in O(n) time, where n is the size of the array, and uses O(k) space for the hashmap to store the remainders.






