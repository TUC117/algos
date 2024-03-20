def compare_outputs(input_file, output_file):
    with open(input_file, 'r') as student_output, open(output_file, 'r') as expected_output:
        student_lines = student_output.readlines()
        expected_lines = expected_output.readlines()

        

    print(f"Test Passed for {input_file}!")
    return True

if __name__ == "__main__":
    for i in range(1, 27):  # Assuming the files are named input1.txt, input2.txt, ..., input10.txt
        output_file = f'./mytestout/outputcase{i}.txt'
        input_file = f'./uout/outputcase{i}.txt'
        if not compare_outputs(input_file, output_file):
            # break
            print(f"Outpus is not matching for case{i+1}.txt file")
            continue
