import numpy as np
import matplotlib.pyplot as plt

x = np.array([])
y = np.array([])

for i in np.arange(1, 40001):
    x = np.append(x, np.log(i))

f = open('contain-rand.txt')
for line in f:
    y = np.append(y, np.log(int(line)))
f.close()


plt.xlabel(r'Количество поищенных из массива элементов', fontsize=14)
plt.ylabel(r'Время поиска элемента в массиве, $нс$', fontsize=14)
plt.title(r'Асимптотика contain при рандомных значениях, k=0.79', fontsize=14)
plt.grid(True)
plt.errorbar(x, y, xerr=0, yerr=0, fmt='+', color='black', capsize=3)
p = np.polyfit(x, y, 1, cov=True)
print(p)
p = p[0]
yfit = np.polyval(p,x)
plt.plot(x, yfit, color="firebrick")
plt.show()