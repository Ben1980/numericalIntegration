set title "Simpson Approximation of Integral"
set xrange [0:pi/2]
set yrange [0:1]

f(x) = 5/(exp(pi)-2)*exp(2*x)*cos(x)
p(a,x)= a*(x-0.72)**2 + f(pi/4)

set arrow 1 from pi/4,0.001 to pi/4,f(pi/4) nohead lt 3

plot f(x), p(-1.1,x) title "p(x)", 1 title "m"
