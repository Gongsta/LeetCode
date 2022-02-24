a = 5

count_ones = 0
while a:
    count_ones += a & 1;
    a >>= 1;

print(count_ones)
