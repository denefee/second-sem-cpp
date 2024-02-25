import numpy as np
import matplotlib.pyplot as plt

x = np.array([])
y = np.array([])

for i in np.arange(1000, 1000000, 1000):
    x = np.append(x, i)

f = open('out14.txt')
for line in f:
    y = np.append(y, int(line))
f.close()


plt.xlabel(r'Количество данных в массиве', fontsize=14)
plt.ylabel(r'Время работы программы, $нc$', fontsize=14)
plt.title(r'График зависимости времени работы функции бинарного поиска от количества данных в массиве при среднем случае', fontsize=14)
plt.grid(True)
plt.errorbar(x, y, xerr=0, yerr=0, fmt='+', color='black', capsize=3)
plt.show()