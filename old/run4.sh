g++ mergeksort.cpp heap.cpp
./a.out > res.dat
echo "run 1 complete"
for i in {2..4}; 
do
./a.out >> res.dat;
echo "run $i complete";
done
