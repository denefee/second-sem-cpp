import numpy as np
import matplotlib.pyplot as plt

x = np.array([])
y = np.array([])

for i in np.arange(5, 2000, 5):
    x = np.append(x, np.log(i))

f = open('out2.txt')
for line in f:
    y = np.append(y, np.log(int(line)))
f.close()


plt.xlabel(r'Количество данных в массиве', fontsize=14)
plt.ylabel(r'Время работы программы, $нc$', fontsize=14)
plt.title(r'Линеаризованный график зависимости количества перестановок сортировки расчёской от размера массива при среднем случае  (k $\approx$ 1.81)', fontsize=14)
plt.grid(True)
plt.errorbar(x, y, xerr=0, yerr=0, fmt='+', color='black', capsize=3)
p = np.polyfit(x, y, 1, full=True, cov=False)
print(p)
p = p[0]
yfit = np.polyval(p,x)
plt.plot(x, yfit, color="firebrick")
plt.show()