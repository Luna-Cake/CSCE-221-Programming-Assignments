g++ BSTree.cpp memory_leak_copy_assn.cpp -o memory_leak_copy_assn.out  >> DEBUG 2>&1
valgrind --leak-check=full --error-exitcode=1 ./memory_leak_copy_assn.out
EXIT_CODE=$? 
if [ $EXIT_CODE -eq 0 ]; then 
	echo true > OUTPUT
	echo 'Test passed!'
else 
	echo false > OUTPUT
	echo 'Memory leak detected!' >> DEBUG
fi

