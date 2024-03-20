import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['axes.unicode_minus']=False#用来正常显示负号

# 生成带有噪声的多项式数据
np.random.seed(42)
x = np.linspace(-2, 2, 100)
y = 2 * x**3 - 3 * x**2 + 2 * x + np.random.normal(0, 1, size=x.shape)

# 多项式拟合
coefficients = np.polyfit(x, y, 3)
poly = np.poly1d(coefficients)

# 生成拟合曲线的数据
x_fit = np.linspace(-2, 2, 100)
y_fit = poly(x_fit)

# 绘制原始数据和拟合曲线
plt.figure(figsize=(8, 6))
plt.scatter(x, y, label='Original Data')
plt.plot(x_fit, y_fit, color='red', label='Fitted Curve')
plt.xlabel('X')
plt.ylabel('y')
plt.title('Polynomial Fitting Example')
plt.legend()
plt.grid(True)
plt.show()
