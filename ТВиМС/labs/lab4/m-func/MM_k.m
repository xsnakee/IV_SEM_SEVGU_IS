function y = MM_k(V,M,k,n)
%MiddleMoment of k
y = fregp(V(1:n)-V,n);
end