using CxxWrap

prefix = CxxWrap.prefix_path()
options = ["-DCMAKE_BUILD_TYPE=Release", "-DCMAKE_PREFIX_PATH=$prefix"]
#options = ["-DCMAKE_BUILD_TYPE=Release"]
files = [""]

cd(@__DIR__)
run(`mkdir -p build`)
cd("build/")

run(`cmake $options ../../lib/`)
run(`make -j 4`)
