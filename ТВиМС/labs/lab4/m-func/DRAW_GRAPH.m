function DRAW_GRAPH(VAL)
%DRAW - plot()
subplot(2,1,1);
title('Графики зависимости оценки от количества испытаний в линейном массштабе');
plot(VAL);
xlabel('x');
ylabel('P(x)');

subplot(2,1,2);
semilogx(VAL(:));
title('Графики зависимости оценки от количества испытаний в полулогарифмическом массштабе');
xlabel('x');
ylabel('P(x)');
pause;

