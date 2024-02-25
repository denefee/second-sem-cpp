import numpy as np
import matplotlib.pyplot as plt

x = np.array([])
y = np.array([])

for i in np.arange(100, 1000001, 100):
    x = np.append(x, i)

f = open('out11.txt')
for line in f:
    y = np.append(y, int(line))
f.close()


plt.xlabel(r'Количество данных в массиве', fontsize=14)
plt.ylabel(r'Время работы программы, $мкc$', fontsize=14)
plt.title(r'График зависимости времени работы функции поиска полным перебором от количества данных в массиве при наихудшем случае', fontsize=14)
plt.grid(True)
plt.errorbar(x, y, xerr=0, yerr=0, fmt='+', color='black', capsize=3)
p = np.polyfit(x, y, 1, full=True, cov=False)
print(p)
p = p[0]
yfit = np.polyval(p,x)
plt.plot(x, yfit, color="firebrick")
plt.show()