g++ -g BSTree.cpp memory_leak_move.cpp -o run-trees >> DEBUG 2>&1

valgrind --leak-check=full --error-exitcode=1 ./run-trees
EXIT_CODE=$? 
if [ $EXIT_CODE -eq 0 ]; then 
	echo true > OUTPUT
	echo 'Test passed!'
else 
	echo false > OUTPUT
	echo 'Memory leak detected!' >> DEBUG
fi

