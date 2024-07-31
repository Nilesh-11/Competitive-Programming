import subprocess
import os

def run_command(command):
    process_result = subprocess.run(command, shell=True, capture_output=True, text=True)

    # Check if the process was successful
    if process_result.returncode != 0:
        return "Execution failed:\n" + process_result.stderr
    else:
        return process_result.stdout

def compile_cpp(cpp_file):
    file_name_without_ext = os.path.splitext(cpp_file)[0]
    compile_command = f'g++ {cpp_file} -std=c++17 -o zout_{file_name_without_ext}'

    # Run the compile command
    process_result = subprocess.run(compile_command, shell=True, capture_output=True, text=True)

    # Check if the process was successful
    if process_result.returncode != 0:
        return "Compilation failed:\n" + process_result.stderr
    else:
        return process_result.stdout

def run_cpp(cpp_file):
    file_name_without_ext = os.path.splitext(cpp_file)[0]
    return run_command(f'./zout_{file_name_without_ext}')

if __name__ == "__main__":
    cpp_test = 'test.cpp'
    cpp_correct = 'correct.cpp'
    cpp_testcase = 'TestcaseMaker.cpp'
    txt_testcase = 'testcase.txt'
    testcases = 1000

    # Compile the testcase generator and both test programs
    compile_testcase_result = run_command(f'g++ {cpp_testcase} Random.cpp ArrayGenerator.cpp TreeGenerator.cpp -o zout_{os.path.splitext(cpp_testcase)[0]}')
    result = run_cpp(cpp_testcase)
    if "failed" in compile_testcase_result:
        print(compile_testcase_result)
        exit(1)

    compile_test_result = compile_cpp(cpp_test)
    if "failed" in compile_test_result:
        print(compile_test_result)
        exit(1)

    compile_correct_result = compile_cpp(cpp_correct)
    if "failed" in compile_correct_result:
        print(compile_correct_result)
        exit(1)

    # Run the testcase generator and both test programs for each testcase
    for i in range(testcases):
        print(f"Testcase {i+1} ... ", end='')
        testcase_output = run_cpp(cpp_testcase)
        # print(testcase_output)
        # if "Execution failed" in testcase_output:
        #     print(testcase_output)
        #     continue

        # with open(txt_testcase, 'w') as f:
        #     f.write(testcase_output)

        test_result = run_cpp(cpp_test)
        # if "Execution failed" in test_result:
        #     print(test_result)
        #     continue

        correct_result = run_cpp(cpp_correct)
        # if "Execution failed" in correct_result:
        #     print(correct_result)
        #     continue

        if test_result != correct_result:
            print('wrong')
            print("Testcase:")
            with open('testcase.txt', 'r') as f:
                print(f.read())
            print('-' * 20)
            print("Test Output:")
            print(test_result)
            print('-' * 20)
            print("Correct Output:")
            print(correct_result)
            exit(1)
        else:
            print('correct')
