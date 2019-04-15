set title "Romberg Parable"
set xrange [0:1]
set yrange [0:1.2]

f(x) = 5/(exp(pi)-2)*exp(2*x)*cos(x)
p(a,x)= a*x**2 + 1

set arrow 1 from 0.5,0.001 to 0.5,0.724727 nohead lt 3
set arrow 2 from 0.25,0.001 to 0.25,0.925565 nohead lt 3

set label 1 at 0.4,0.7
set label 1 "T(1/2)" tc lt 3
set label 2 at 0.15,0.9
set label 2 "T(1/4)" tc lt 3

plot p(-1.07,x) title "p(x)"