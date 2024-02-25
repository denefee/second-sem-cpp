import numpy as np
import matplotlib.pyplot as plt

x = np.array([])
y = np.array([])

for i in np.arange(1, 100000, 1):
    x = np.append(x, (i))

f = open('test3.txt')
for line in f:
    y = np.append(y, (int(line)))
f.close()


plt.xlabel(r'Количество добавленных в массив элементов', fontsize=14)
plt.ylabel(r'Время добавления нового элемента в массив, $нс$', fontsize=14)
plt.title(r'График при Стратегии 3', fontsize=14)
plt.grid(True)
plt.errorbar(x, y, xerr=0, yerr=0, fmt='+', color='black', capsize=3)
p = np.polyfit(x, y, 1, full=True, cov=False)
print(p)
p = p[0]
yfit = np.polyval(p,x)
plt.plot(x, yfit, color="firebrick")
plt.show()