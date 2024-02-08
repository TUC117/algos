all:
	g++ helper.cpp -o main

	for i in 1 2 3 4 5 6 7 8 9 10 ; do \
		./linesegment_linux.out < ./input/input$$i.txt > ./student_ouput/student_output$$i.txt; \
	done

	python3 autograder.py 
	
	for i in 1 2 3 4 5 6 7 8 9 10 ; do \
		rm ./student_ouput/student_output$$i.txt; \
	done

