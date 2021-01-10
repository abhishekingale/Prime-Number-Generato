mkdir -p bin
pushd bin
cmake .. > /dev/null 
make && printf "\n\n" && ./primeBenchmark* && printf "\n\n" 
popd > /dev/null
