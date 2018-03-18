m = 5;
n = 1000;

A = rand(m,n);

%вариант 4
C = [0.3 0.8;
    0.3 0.8;
    0.3 0.8; 
    0.20 0.25; 
    0.06 0.96];

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

for i = 1:m
%subplot(2,1,1);
plot(y(i,:));
xlabel('Количество событий');
ylabel('Частота события Z');

pause;
%subplot(2,1,2);
semilogx(y(i,:));
xlabel('Количество событий');
ylabel('Частота события Z');
pause;
end
