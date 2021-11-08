g++ -g BSTree.cpp BSTree_main.cpp -o main  >> DEBUG 2>&1
./main
valgrind --leak-check=full --error-exitcode=1 ./main
EXIT_CODE=$? 
if [ $EXIT_CODE -eq 0 ]; then 
	echo true > OUTPUT
	echo 'Test passed!'
else 
	echo false > OUTPUT
	echo 'Memory leak detected!' >> DEBUG
fi

