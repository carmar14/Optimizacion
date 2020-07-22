function [px,py]=gradf(xk,yk)
    px=(1-2*xk^2)*exp(-xk^2-yk^2);
    py=-2*xk*yk*exp(-xk^2-yk^2); 
end