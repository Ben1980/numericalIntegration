set title "Legendre Polynomial of first 5 Orders"
set xrange [-1:1]
set yrange [-1:1]

p1(x) = x
p2(x) = (3*x**2 - 1)/2
p3(x) = (5*x**3 - 3*x)/2
p4(x) = (35*x**4 - 30*x**2 + 3)/8
p5(x) = (63*x**5 - 70*x**3 + 15*x)/8

plot p1(x), p2(x), p3(x), p4(x), p5(x)
