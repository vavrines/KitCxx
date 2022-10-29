ccall((:hello, "libkit.so"), Nothing, ())



prim = zeros(3)
w = [1.0, 0.0, 1.0]
γ = 1.4
ccall(
    (:conserve_prim_1d, "libkit.so"), # name of C function and library
    Nothing,              # output type
    (Ref{Cdouble}, Ref{Cdouble}, Cdouble,),                        # tuple of input types
    prim, w, γ                                  # name of Julia variable to pass in
)

@show prim
