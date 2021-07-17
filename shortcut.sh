if [[ -f ramen_app ]]
then
    make clean && make 
else
    make
fi