cd(@__DIR__)

ccall((:hello, "./pure c/libkit.so"), Nothing, ())

prim = zeros(3)
w = [1.0, 0.0, 1.0]
γ = 1.4
ccall(
    (:conserve_prim_1d, "./pure c/libkit.so"), # name of C function and library
    Nothing, # output type
    (Ref{Cdouble}, Ref{Cdouble}, Cdouble), # tuple of input types
    prim,
    w,
    γ,
)

@show prim

a = zeros(2, 2)
ccall(
    (:test, "./pure c/libkit.so"), # name of C function and library
    Nothing, # output type
    (Ref{Cdouble},), # tuple of input types
    a,
)

@show a