function DRAW_GRAPH(VAL)
%DRAW - plot()
subplot(2,1,1);
title('������� ����������� ������ �� ���������� ��������� � �������� ���������');
plot(VAL);
xlabel('x');
ylabel('P(x)');

subplot(2,1,2);
semilogx(VAL(:));
title('������� ����������� ������ �� ���������� ��������� � ������������������� ���������');
xlabel('x');
ylabel('P(x)');
pause;

