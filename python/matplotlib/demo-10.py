import matplotlib.pyplot as plt

def draw_neural_net(ax, left, right, bottom, top, layer_sizes):
    '''
    绘制神经网络结构图

    :param ax: matplotlib.axes.Axes对象
    :param left: 图形左边界
    :param right: 图形右边界
    :param bottom: 图形底边界
    :param top: 图形顶边界
    :param layer_sizes: 包含每个层神经元数量的列表
    '''
    # 计算每层神经元的数量
    v_spacing = (top - bottom)/max(layer_sizes)
    h_spacing = (right - left)/len(layer_sizes)

    # 绘制神经元
    for n, layer_size in enumerate(layer_sizes):
        layer_top = v_spacing*(layer_size - 1)/2. + (top + bottom)/2.
        for m in range(layer_size):
            circle = plt.Circle((n*h_spacing + left, layer_top - m*v_spacing), v_spacing/4.,
                                color='w', ec='k', zorder=4)
            ax.add_artist(circle)
            # 添加神经元编号
            ax.text(n*h_spacing + left, layer_top - m*v_spacing, f'$x_{m+1}^{(n+1)}$',
                    ha='center', va='center', fontsize=12)

    # 连接神经元
    for n, layer_size in enumerate(layer_sizes[:-1]):
        layer_top = v_spacing*(layer_size - 1)/2. + (top + bottom)/2.
        layer_bottom = v_spacing*(layer_sizes[n+1] - 1)/2. + (top + bottom)/2.
        for m in range(layer_sizes[n+1]):
            for l in range(layer_size):
                line = plt.Line2D([n*h_spacing + left, (n + 1)*h_spacing + left],
                                  [layer_top - l*v_spacing, layer_bottom - m*v_spacing], c='k')
                ax.add_artist(line)

# 创建一个新的图形
fig = plt.figure(figsize=(12, 12))
ax = fig.gca()

# 设置坐标轴范围
ax.set_xlim(0, 10)
ax.set_ylim(0, 10)

# 绘制神经网络结构图
draw_neural_net(ax, 1, 9, 1, 9, [4, 3, 2])

# 关闭坐标轴
ax.axis('off')

# 显示图形
plt.show()
