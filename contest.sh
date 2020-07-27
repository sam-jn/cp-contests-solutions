mkdir ./$1/$2
n=`expr $3 + 1`
a=1
while [ $a -lt $n ]
do
    cp ./template.cpp ./$1/$2/$a.cpp
    a=`expr $a + 1`
done