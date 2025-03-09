
typedef float(*function)(float);

float root(function f, function g, float a, float b, float eps1, function df, function dg);

float integral(function f, float a, float b, float eps2);