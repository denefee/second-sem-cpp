import numpy as np
import matplotlib.pyplot as plt

x = np.array([])
y = np.array([])

for i in np.arange(100, 1000000, 100):
    x = np.append(x, i)
    

f = open('out13.txt')
for line in f:
    y = np.append(y, int(line))
f.close()


plt.xlabel(r'Количество данных в массиве', fontsize=14)
plt.ylabel(r'Время работы программы, $нc$', fontsize=14)
plt.title(r'График зависимости времени работы функции поиска бинарным поиском от количества данных в массиве при наихудшем случае', fontsize=14)
plt.grid(True)
plt.errorbar(x, y, xerr=0, yerr=0, fmt='+', color='black', capsize=3)
plt.show()

