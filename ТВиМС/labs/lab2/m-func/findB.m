m = 5;
n = 10000;

A = rand(m,n);

%������� 4
C = [0.3 0.8;0.3 0.8;0.3 0.8; 0.20 0.25; 0.06 0.096];

for i = 1:m
    for j = 1:n
        B(i,j) = logzn(C(i,1),C(i,2),A(i,j));
    end
end

for i = 1:m
    for j = 1:n
        y(i,j) = fregp(B(i,:),j);
    end
end

subplot(2,1,1);
plot(y(1,:));
xlabel('���������� �������');
ylabel('������� ������� Z');

subplot(2,1,2);
semilogx(y(1,:));
xlabel('���������� �������');
ylabel('������� ������� Z');