import subprocess
import os
from unittest import result

def run_command(command):
    process_result = subprocess.run(command, shell=True, capture_output=True, text=True)

    # Check if the process was successful
    if process_result.returncode != 0:
        print("Execution failed:\n" + process_result.stderr)
        exit(0)
    else:
        return process_result.stdout

def compile_cpp(cpp_file):
    file_name_without_ext = os.path.splitext(cpp_file)[0]
    compile_command = f'g++ {cpp_file} -std=c++17 -o zout_{file_name_without_ext}'

    # Run the compile command
    return run_command(compile_command)

def run_cpp(cpp_file):
    file_name_without_ext = os.path.splitext(cpp_file)[0]
    return run_command(f'./zout_{file_name_without_ext}')

if __name__ == "__main__":
    cpp_test = 'test.cpp'
    cpp_correct = 'correct.cpp'
    cpp_testcase = 'TestcaseMaker.cpp'
    txt_testcase = 'testcase.txt'
    testcases = 10

    print("Compiling and testing ... ", end='')
    # Compile the testcase generator and both test programs
    compile_testcase_result = run_command(f'g++ {cpp_testcase} Random.cpp TreeGenerator.cpp ArrayGenerator.cpp StringGenerator.cpp -o zout_{os.path.splitext(cpp_testcase)[0]}')

    # test commands to handle errors
    result_ = run_cpp(cpp_testcase)

    result_ = compile_cpp(cpp_test)

    result_ = compile_cpp(cpp_correct)
    print("done")

    # Run the testcase generator and both test programs for each testcase
    for i in range(testcases):
        print(f"Testcase {i+1} ... ", end='')
        testcase_output = run_cpp(cpp_testcase)

        test_result = run_cpp(cpp_test)

        correct_result = run_cpp(cpp_correct)

        if test_result != correct_result:
            print('wrong\nTestcase:')
            with open('testcase.txt', 'r') as f:
                print(f.read())
            print('-' * 20, '\n', f"Test Output: {test_result}")
            print('-' * 20, '\n', f"Correct Output: {correct_result}")
            exit(1)
        else:
            print('correct')


