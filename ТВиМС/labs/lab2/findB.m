m = 5;
n = 1000;

A = rand(m,n);

%вариант 4
C = [0.3 0.8;0.3 0.8;0.3 0.8; 0.20 0.25; 0.06 0.096];

for i = 1:size(A,1)
    for j = 1:size(A,2)
        if (logzn(C(i,1),C(i,2),A(i,j)))
            B(i,j) = 1;
        else
            B(i,j) = 0;
        end
    end
end