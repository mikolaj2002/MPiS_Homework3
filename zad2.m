S = zeros(10000, 1);
N = 100;

for i = 1:10000
    X = randi([0 1], 1, N);
    X(X == 0) = -1;
    S(i) = sum(X);
end

figure(1)
cdfplot(S);
hold on;
pd = makedist('Normal', 'mu', 0, 'sigma', sqrt(N));
x = -50:.1:50;
p = cdf(pd, x);
plot(x, p);
grid

figure(2)
histogram(S);
grid