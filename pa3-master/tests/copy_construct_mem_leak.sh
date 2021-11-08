g++ memory_leak_copy.cpp BSTree.cpp -o leak_copy.out >> DEBUG 2>&1

valgrind --leak-check=full --error-exitcode=1 ./leak_copy.out
EXIT_CODE=$? 
if [ $EXIT_CODE -eq 0 ]; then 
	echo true > OUTPUT
	echo 'Test passed!'
else 
	echo false > OUTPUT
	echo 'Memory leak detected!' >> DEBUG
fi

