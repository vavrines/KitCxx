module CppHello
using CxxWrap

#@wrapmodule(joinpath("build", "libhello"))
@wrapmodule(joinpath(@__DIR__, "build/libhello"))

function __init__()
    @initcxx
end
end # module

# Call greet and show the result
@show CppHello.greet()
