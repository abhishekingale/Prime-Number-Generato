mkdir -p bin
pushd bin
cmake .. > /dev/null 
make && printf "\n\n" && ./primeParallel* && printf "\n\n" 
popd > /dev/null
