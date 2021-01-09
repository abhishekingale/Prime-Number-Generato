mkdir -p bin
pushd bin
cmake .. > /dev/null 
make && printf "\n\n" && ./primeclass* && printf "\n\n" 
popd > /dev/null
