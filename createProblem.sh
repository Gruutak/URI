mkdir $1
cd $1
touch 0.in
touch $1.$2
if [ $2 = 'cpp' ]; then
	cp ../createProblem_base/cpp/Makefile .
	cp ../createProblem_base/cpp/base.cpp ./$1.cpp
else
	cp ../createProblem_base/c/Makefile .
	cp ../createProblem_base/c/base.c ./$1.c
fi