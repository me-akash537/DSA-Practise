Inside each folder, you will find problems from different websites. It's not that I jump between platforms; I simply prefer to keep everything organized so that I can easily find problems later when needed.

As I am starting out, I learn topics one by one and solve problems on LeetCode. Apart from learning the basics of a new topic, I use Codeforces for additional practice and contests.

If a problem goes into my notes, I name the file in the format `pno_filename.cpp`. For example: `027_bitmanipulation.cpp`.

Also, I use AI at several places to clean up, or somtimes to fasten up basic stuff. But trust me, I am actually writing all of this code myself. 

Use the following command to clear up all the .exe and .out files.

```bash
find . -type f \( -name "*.out" -o -name "*.exe" \) -delete
```

To sync/link a problem file to notes (so changes in one reflect in the other):

```bash
ln -sr <source_file> <target_link>
```
```bash
# Example:
# ln -sr Leetcode/Medium/lc322_coin_change.cpp Notes/1_Dynamic_programming/iii_canSum.cpp
```
