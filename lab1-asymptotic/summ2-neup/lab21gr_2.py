import numpy as np
import matplotlib.pyplot as plt
import math

x = np.array([])
y = np.array([])

for i in np.arange(20, 4001, 10):
    x = np.append(x, np.log(i))

f = open('out21.txt')
for line in f:
    if (int(line) != 0):
        y = np.append(y, np.log(int(line)))
f.close()


plt.xlabel(r'ln(Количество данных в массиве)', fontsize=14)
plt.ylabel(r'ln(Время работы программы, $мкc$)', fontsize=14)
plt.title(r'Линеаризованный график зависимости времени работы функции поиска суммы двух в неупорядоченном массиве от количества данных в массиве при худшем случае', fontsize=14)
plt.grid(True)
plt.errorbar(x, y, xerr=0, yerr=0, fmt='+', color='black', capsize=3)
p = np.polyfit(x, y, 1, full=True, cov=False)
print(p)
p = p[0]
yfit = np.polyval(p,x)
plt.plot(x, yfit, color="firebrick")
plt.show()