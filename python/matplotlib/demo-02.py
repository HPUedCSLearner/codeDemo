import matplotlib.pyplot as plt

#折线图
x = [16,32,128,256]#点的横坐标
k1 = [650,285,199,100]#线1的纵坐标
k2 = [645,300,220,97]#线2的纵坐标
plt.plot(x,k1,linestyle = '--',color = 'r',label="实际时间")#s-:方形
plt.plot(x,k2,linestyle = '--',color = 'g',label="预测时间")#o-:圆形
plt.xlabel("进程数量")#横坐标名字
plt.ylabel("程序运行时间(s)")#纵坐标名字
plt.legend(loc = "best")#图例

plt.xticks(x)
plt.grid(axis = 'both',linestyle='--', linewidth = 0.5)

plt.show()


