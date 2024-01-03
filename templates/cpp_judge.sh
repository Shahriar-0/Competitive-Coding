make > /dev/null 2>&1

./cpp.out < ../test/in > ../test/out

diff ../test/out ../test/ans > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo -e "\033[32mPassed\033[0m"
else
    echo -e "\033[31mFailed\033[0m"
    diff ../test/out ../test/ans > ../test/err
    cat ../test/err
fi