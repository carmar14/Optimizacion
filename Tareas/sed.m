function dXdt= sed(t, X )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
u=X(1);  %Variable u
v=X(2);  %Variable v
du=3*u-0.4*u.^2-u.*v; %du/dt
dv=-v+2*u.*v; %dv/dt
dXdt=[du;dv];

end

