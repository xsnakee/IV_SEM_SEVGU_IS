clear all;
m = 1;
n = 1000;
%exponential MU = 3
MU = 3;
A = exprnd(MU,m,n);
[bt,dt] = expstat(MU);

%расчет оценки М.О.СВ
for i = 1:n
    B(i) =  fregp(A,i);
end

%C - центрированный вектор относительно n-ой оценки М.О.СВ
for i = 1:n
   C(i) = A(i) - B(n); 
end

%D - вектор оценок дисперсии СВ
%E - вектор оценок цетр момента 3 порядка(характеритик ассиметрии)
%F - вектор оценок центр. момента 4 порядка (характеритики)
%G1 - вектор коэффициентов ассиметрии
%G2 - вектор коэффициентов эксцесса
for i = 1:n
   D(i) = fregp(C.^2, i);
   E(i) = fregp(C.^3, i); 
   F(i) = fregp(C.^4, i); 
   G1(i) = GAMMA_1(E(i),D(i));
   G2(i) = GAMMA_2(F(i),D(i));
end

b = B(n);%оценка МО СВ
d = D(n);%оценка дисперсии СВ
sigD = sqrt(d);% СКО СВ
e = E(n);% ЦЕНТР. М. 3-го порядка
f = F(n);% ЦЕНТР. М. 4-го порядка
g1 = G1(n);% КОЭФ. АССИМЕТРИИ
g2 = G2(n);% КОЭФ. АКСЦЕССА

DRAW_GRAPH(B);
DRAW_GRAPH(C);
DRAW_GRAPH(D);
DRAW_GRAPH(E);
DRAW_GRAPH(F);
DRAW_GRAPH(G1);
DRAW_GRAPH(G2);
