import numpy as np
import matplotlib.pyplot as plt

x = np.array([])
y = np.array([])

for i in np.arange(50, 751, 50):
    x = np.append(x, np.log(i))

f = open('ringbuffer.txt')
for line in f:
    y = np.append(y, np.log(int(line)))
f.close()


plt.xlabel(r'Количество людей в кругу', fontsize=14)
plt.ylabel(r'Время работы программы, $нс$', fontsize=14)
plt.title(r'Логарифмический график зависимости среднего времени работы при среднем случае для RingBuffer. k = 1.79', fontsize=14)
plt.grid(True)
plt.errorbar(x, y, xerr=0, yerr=0, fmt='+', color='black', capsize=3)
p = np.polyfit(x, y, 1, full=True, cov=False)
print(p)
p = p[0]
yfit = np.polyval(p,x)
plt.plot(x, yfit, color="firebrick")
plt.show()