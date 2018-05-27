clear all;
close all;
%imgFileName - переменная содержащая путь к файлу
%imgFilePath - путь к файлу
[imgFileName, imgFilePath] = uigetfile('*.png','Выберите изображение');

%считывание и отображение графического файла
IMG = imread(imgFileName);
figure(1);
imshow(IMG);

%преобразование выполняетя для обеспечения возможности выполнения арфм. оп.
A = double(IMG);
%valVector - вектор сулчайного процесса
valVector = A(:,13);
%построение графика случ. процесса
figure(2);
stem(valVector);
title('RANDOM PROCESS GRAPH');
ylabel('Y');%Y - уровень яроксти
xlabel('N');%N - значение отсчета


vectLength = length(valVector);
optLength = round(sqrt(vectLength));
%построение гистограммы случайного процесса
figure(3);
hist(valVector,optLength);
title('RANDOM PROCESS BAR CHART');
ylabel('Y');%Y - уровень яроксти
xlabel('Q');%Q - частота попадания СВ в заданный интервал

%расчет спектральной плотности
Ts = 0.01; %шаг времени (с)
T = 100;%длительность процесса (с)

rb = 250;
df = 1/T;
Fmax = 1/Ts;
f = -(Fmax/2):df:(Fmax/2);%Вектор значений частот
freqValAmount = length(f);
[a,f] = pwelch(valVector,hann(vectLength),[],freqValAmount,Fmax);

%построение графика функции спектральной плотности
figure(4);
stem(f(1:rb),a(1:rb));
grid;
title('SPECTRAL DESTINY GRAPH');
ylabel('SP');
xlabel('f');
%периоды
vecLen = vectLength-1;
Tau=-(vecLen):Ts*100:(vecLen);

%расчет автоковариационной функции
R = xcorr(valVector);
%построение графика автоковариционной функции 
figure(5);
plot(Tau, R);
grid;
title('ACORR FUNCTION GRAPH');
ylabel('ACORR VAL');
xlabel('Tau');


%расчет автокорреляционной функции
R1 = xcov(valVector);
%построение графика автокорреляционной функции 
figure(6);
plot(Tau, R1);
grid;
title('ACOV FUNCTION GRAPH');
ylabel('ACOV VAL');
xlabel('Tau');

MOa = mean(valVector);
M2 = moment(valVector,2);
M3 = moment(valVector,3);
M4 = moment(valVector,4);
GAMMA1 = GAMMA_1(M3,M2);
GAMMA2 = GAMMA_2(M4,M2);

