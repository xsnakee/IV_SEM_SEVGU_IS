clear all;
close all;
%imgFileName - ���������� ���������� ���� � �����
%imgFilePath - ���� � �����
[imgFileName, imgFilePath] = uigetfile('*.png','�������� �����������');

%���������� � ����������� ������������ �����
IMG = imread(imgFileName);
figure(1);
imshow(IMG);

%�������������� ���������� ��� ����������� ����������� ���������� ����. ��.
A = double(IMG);
%valVector - ������ ���������� ��������
valVector = A(:,13);
%���������� ������� ����. ��������
figure(2);
stem(valVector);
title('RANDOM PROCESS GRAPH');
ylabel('Y');%Y - ������� �������
xlabel('N');%N - �������� �������


vectLength = length(valVector);
optLength = round(sqrt(vectLength));
%���������� ����������� ���������� ��������
figure(3);
hist(valVector,optLength);
title('RANDOM PROCESS BAR CHART');
ylabel('Y');%Y - ������� �������
xlabel('Q');%Q - ������� ��������� �� � �������� ��������

%������ ������������ ���������
Ts = 0.01; %��� ������� (�)
T = 100;%������������ �������� (�)

rb = 250;
df = 1/T;
Fmax = 1/Ts;
f = -(Fmax/2):df:(Fmax/2);%������ �������� ������
freqValAmount = length(f);
[a,f] = pwelch(valVector,hann(vectLength),[],freqValAmount,Fmax);

%���������� ������� ������� ������������ ���������
figure(4);
stem(f(1:rb),a(1:rb));
grid;
title('SPECTRAL DESTINY GRAPH');
ylabel('SP');
xlabel('f');
%�������
vecLen = vectLength-1;
Tau=-(vecLen):Ts*100:(vecLen);

%������ ������������������ �������
R = xcorr(valVector);
%���������� ������� ����������������� ������� 
figure(5);
plot(Tau, R);
grid;
title('ACORR FUNCTION GRAPH');
ylabel('ACORR VAL');
xlabel('Tau');


%������ ������������������ �������
R1 = xcov(valVector);
%���������� ������� ������������������ ������� 
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

