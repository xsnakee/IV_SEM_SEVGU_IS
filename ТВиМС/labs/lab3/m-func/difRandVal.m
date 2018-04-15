row = 4;
col = 1000;

L = rand(row,col);

I = [0.2, 0.7;
     0, 0.3;
     0.1, 0.5];
 
for i = 1:col     
    A(i) = logzn(I(1,1),I(1,2),L(1,i));
    B(i) = logzn(I(2,1),I(2,2),L(2,i));
    C(i) = logzn(I(3,1),I(3,2),L(3,i));
    
    A1(i) = logzn(I(1,1),I(1,2),L(4,i));
    B1(i) = logzn(I(2,1),I(2,2),L(4,i));
    C1(i) = logzn(I(3,1),I(3,2),L(4,i));
end

F = (A & (~B) & C) | ((~A) & B) | (B & (~C));
F1 = (A1 & (~B1) & C1) | ((~A1) & B1) | (B1 & (~C1));

res = mean(F);
res1 = mean(F1);
