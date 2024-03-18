import matplotlib.pyplot as plt
from matplotlib import ticker
import numpy as np

# https://zhuanlan.zhihu.com/p/147794661?from_voters_page=true

plt.rcParams['axes.unicode_minus']=False#用来正常显示负号

x  = np.array([16,32,64,128,256]) #点的横坐标
y1 = np.array([650,340,190, 103,70]) # 实际时间
y2 = np.array([670,377,160, 131,80])  # 预测时间
# y3 =np.array() [0.02,0.023,0.025, 0.023, 0.019]
y3 = np.abs(y1 - y2) / y2
print(y3)

fig = plt.figure()

ax1 = fig.add_subplot(111)
ax1.plot(x, y1 ,color = 'black',label="实际时间")
ax1.plot(x, y2, linestyle = '--', color = 'r',label="预测时间")


ax1.set_xlabel('进程数量')
ax1.set_ylabel('程序运行时间(s)')
# ax1.set_title("Double Y axis")

# 设置图例位置
ax1.legend(loc='upper right')     #设置ax子图的图例(legend)
# ax1.legend(loc='best')

ax2 = ax1.twinx()  # this is the important function
ax2.plot(x, y3, 'grey')


# 设置坐标轴范围
# ax2.set_xlim([0, np.e])
ax2.set_ylim([0.0, 1])
ax2.set_ylabel('相对误差(%)')
# ax2.set_xlabel('Same X for both exp(-x) and ln(x)')

# 设置只显示刻度
plt.xticks(x)
# plt.grid(axis = 'both',linestyle='--', linewidth = 0.5)

# 设置图例位置
# ax2.legend(loc='upper right')
# plot.legend(loc='best')

#  设置网格
ax1.grid(linestyle='--', linewidth = 0.5)
ax2.grid(linestyle='--', linewidth = 0.5)
# ax2.grid()

# 设置第二个有轴用百分数显示
# https://blog.csdn.net/lfod1997/article/details/106961100
ax2.yaxis.set_major_formatter(ticker.PercentFormatter(xmax=1, decimals=1))

plt.show()
