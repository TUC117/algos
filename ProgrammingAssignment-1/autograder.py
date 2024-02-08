def compare_outputs(input_file, output_file):
    with open(input_file, 'r') as student_output, open(output_file, 'r') as expected_output:
        student_lines = student_output.readlines()
        expected_lines = expected_output.readlines()

        if student_lines != expected_lines:
            print(f"Test Failed for {input_file}!")
            return False

    print(f"Test Passed for {input_file}!")
    return True

if __name__ == "__main__":
    for i in range(1, 11):  # Assuming the files are named input1.txt, input2.txt, ..., input10.txt
        input_file = f'./expected_outputs/output{i}.txt'
        output_file = f'./student_ouput/student_output{i}.txt'
        if not compare_outputs(input_file, output_file):
            break
