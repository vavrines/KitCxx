module KitCxx

using CxxWrap

const KC = KitCxx
export KC

@wrapmodule(joinpath(@__DIR__, "../deps/build/libkit"))

function __init__()
    @initcxx
end

end # module
