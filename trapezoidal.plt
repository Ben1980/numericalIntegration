set title "Trapezoidal Approximation of Integral"
set xrange [0:pi/2]
set yrange [0:1]
set multiplot

f(x) = 5/(exp(pi)-2)*exp(2*x)*cos(x)
dx = pi/2/4

set object 1 polygon from 0,0 to 0,f(0) to dx,f(dx) to dx,0 
set object 2 polygon from dx,0 to dx,f(dx) to 2*dx,f(2*dx) to 2*dx,0 
set object 3 polygon from 2*dx,0 to 2*dx,f(2*dx) to 3*dx,f(3*dx) to 3*dx,0  
set object 4 polygon from 3*dx,0 to 3*dx,f(3*dx) to 4*dx,f(4*dx) to 4*dx,0 
set object 1 fillstyle solid border border lc rgb "#EE000000" back fc rgb "#EE22665F"
set object 2 fillstyle solid border border lc rgb "#EE000000" back fc rgb "#EE22665F"
set object 3 fillstyle solid border border lc rgb "#EE000000" back fc rgb "#EE22665F"
set object 4 fillstyle solid border border lc rgb "#EE000000" back fc rgb "#EE22665F"

plot 1 notitle
plot 2 notitle
plot 3 notitle
plot 4 notitle
plot f(x)
