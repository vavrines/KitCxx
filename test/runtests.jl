#using KitCxx
cd(@__DIR__)
include("../src/KitCxx.jl")
using .KitCxx

prim = [1.0, 0.0, 1.0]
u = -5:0.01:5 |> collect
f = zero(u)
KC.maxwellian_1f1v(f, u, prim)
