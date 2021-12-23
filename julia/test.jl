# ------------------------------------------
# Julia caller
# ------------------------------------------

cd(@__DIR__)

w = [1.0, 0.0, 1.0]
γ = 1.4

###
# C
###

prim = zeros(3)

ccall(
    #(:hello, :libkit), # name of C function and library
    (:hello, "../c/libkit.so"), # name of C function and library
    Nothing,              # output type
    (),                        # tuple of input types
                                  # name of Julia variable to pass in
)
ccall(
    (:conserve_prim_1d, "../c/libkit.so"), # name of C function and library
    #(:conserve_prim_1d, "./c/kinetic.so"), # name of C function and library
    Nothing,              # output type
    (Ref{Cdouble}, Ref{Cdouble}, Cdouble,),                        # tuple of input types
    prim, w, γ                                  # name of Julia variable to pass in
)

println(prim)

###
# C++
###

prim = zeros(3)

ccall(
    #(:hello, :libkit), # name of C function and library
    (:hello, "../c++/libkit.so"), # name of C function and library
    Nothing,              # output type
    (),                        # tuple of input types
                                  # name of Julia variable to pass in
)
ccall(
    (:conserve_prim_1d, "../c++/libkit.so"), # name of C function and library
    #(:conserve_prim_1d, "./c/kinetic.so"), # name of C function and library
    Nothing,              # output type
    (Ref{Cdouble}, Ref{Cdouble}, Cdouble,),                        # tuple of input types
    prim, w, γ                                  # name of Julia variable to pass in
)

println(prim)

"""
C++ doesn't work yet
"""