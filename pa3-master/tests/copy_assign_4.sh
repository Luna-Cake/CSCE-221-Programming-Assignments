printf "\nTestcase: \n"
cat testcase.txt

rm -f OUTPUT
sed -i '1s/^/#include "test_functions.h"\n /' BSTree.cpp
g++ -c test_functions.cpp BSTree.cpp
g++ test_functions.o BSTree.o
./a.out >> OUTPUT
printf "\n\nResult: "
cat OUTPUT