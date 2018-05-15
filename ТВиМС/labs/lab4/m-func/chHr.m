clear all;
m = 1;
n = 1000;
%exponential MU = 3
MU = 3;
A = exprnd(MU,m,n);
[bt,dt] = expstat(MU);

%������ ������ �.�.��
for i = 1:n
    B(i) =  fregp(A,i);
end

%C - �������������� ������ ������������ n-�� ������ �.�.��
for i = 1:n
   C(i) = A(i) - B(n); 
end

%D - ������ ������ ��������� ��
%E - ������ ������ ���� ������� 3 �������(������������ ����������)
%F - ������ ������ �����. ������� 4 ������� (�������������)
%G1 - ������ ������������� ����������
%G2 - ������ ������������� ��������
for i = 1:n
   D(i) = fregp(C.^2, i);
   E(i) = fregp(C.^3, i); 
   F(i) = fregp(C.^4, i); 
   G1(i) = GAMMA_1(E(i),D(i));
   G2(i) = GAMMA_2(F(i),D(i));
end

b = B(n);%������ �� ��
d = D(n);%������ ��������� ��
sigD = sqrt(d);% ��� ��
e = E(n);% �����. �. 3-�� �������
f = F(n);% �����. �. 4-�� �������
g1 = G1(n);% ����. ����������
g2 = G2(n);% ����. ��������

DRAW_GRAPH(B);
DRAW_GRAPH(C);
DRAW_GRAPH(D);
DRAW_GRAPH(E);
DRAW_GRAPH(F);
DRAW_GRAPH(G1);
DRAW_GRAPH(G2);
