#using KitCxx

cd(@__DIR__)
include("../src/KitCxx.jl")
using .KitCxx

KitCxx.greet()

x = KC.World()

KC.set(x, "hello")

KC.greet(x)

prim = zeros(3)
w = [1.0, 0.0, 1.0]
γ = 1.4

KC.conserve_prim_1d(prim, w, γ)

x = KC.Solution()
KC.set(x, 1.0, 2.0)
KC.get(x)

