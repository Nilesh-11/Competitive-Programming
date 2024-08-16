Steps:

1. Paste correct code in `correct.cpp` and test code in `test.cpp`.

2. Take input from `testcase.txt` file - add the following code below in both `test.cpp` and `correct.cpp` file.
    ```
    #ifndef ONLINE_JUDGE
        freopen("testcase.txt", "r", stdin);
    #endif
    ```

3. In `TestcaseMaker.cpp` file, generate your testcase and make sure to print output to `testcase.txt` file.
    - This is done by using following code:
    ```
    ofstream outfile("testcase.txt");
    ```
    - use _outfile_ instead of _cout_
    - output from this is read by other files so print "1" before the printing the testcase.

4. run `debug.py` file.