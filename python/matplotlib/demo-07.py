import torch
import torch.nn as nn
import torch.optim as optim
import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['axes.unicode_minus']=False#用来正常显示负号

# 生成带有噪声的非线性数据
np.random.seed(42)
X = np.linspace(0, 2, 150).reshape(-1, 1)
y = np.sin(5 * X) + np.random.normal(0, 0.1, size=X.shape) + X/2

# 转换数据为PyTorch张量
X_tensor = torch.from_numpy(X).float()
y_tensor = torch.from_numpy(y).float()

# 定义神经网络模型
class SimpleNN(nn.Module):
    def __init__(self):
        super(SimpleNN, self).__init__()
        self.fc1 = nn.Linear(1, 64)
        self.relu = nn.ReLU()
        self.fc2 = nn.Linear(64, 1)

    def forward(self, x):
        x = self.fc1(x)
        x = self.relu(x)
        x = self.fc2(x)
        return x

# 实例化模型、损失函数和优化器
model = SimpleNN()
criterion = nn.MSELoss()
optimizer = optim.Adam(model.parameters(), lr=0.001)

# 训练模型
epochs = 2000
times = [2,80,200, 450, 900, 1900]

for epoch in range(epochs):
    # 前向传播
    outputs = model(X_tensor)
    loss = criterion(outputs, y_tensor)

    # 反向传播和优化
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()

    if (epoch+1) % 10 == 0:
        print(f'Epoch [{epoch + 1}/{epochs}], Loss: {loss.item():.4f}')
    
    for i in range(6):
        if(epoch+1)  == times[i]:
            plt.subplot(2, 3, i+1)
            plt.scatter(X, y, s=3, label='Actual Data')
            plt.plot(X, model(X_tensor).detach().numpy(), color='black', linewidth=0.9, label='Fitted Line')
            plt.tick_params(labelsize=7)
            plt.title(f'Loss: {loss.item():.4f}', fontsize=8)
            
    # if(epoch+1)  == times[0]:
    #     plt.subplot(2, 3, 1)
    #     plt.scatter(X, y, s=3, label='Actual Data')
    #     plt.plot(X, model(X_tensor).detach().numpy(), color='black', linewidth=0.9, label='Fitted Line')
    #     plt.tick_params(labelsize=7)
    #     plt.title(f'Loss: {loss.item():.4f}', fontsize=8)
    # if(epoch+1)  == times[1]:
    #     plt.subplot(2, 3, 2)
    #     plt.scatter(X, y, s=3, label='Actual Data')
    #     plt.plot(X, model(X_tensor).detach().numpy(), color='black', linewidth=0.9, label='Fitted Line')
    #     plt.tick_params(labelsize=7)
    # if(epoch+1)  == times[2]:
    #     plt.subplot(2, 3, 3)
    #     plt.scatter(X, y, s=3, label='Actual Data')
    #     plt.plot(X, model(X_tensor).detach().numpy(), color='black', linewidth=0.9, label='Fitted Line')
    #     plt.tick_params(labelsize=7)
    # if(epoch+1)  == times[3]:
    #     plt.subplot(2, 3, 4)
    #     plt.scatter(X, y, s=3, label='Actual Data')
    #     plt.plot(X, model(X_tensor).detach().numpy(), color='black', linewidth=0.9, label='Fitted Line')
    #     plt.tick_params(labelsize=7)
    # if(epoch+1)  == times[4]:
    #     plt.subplot(2, 3, 5)
    #     plt.scatter(X, y, s=3, label='Actual Data')
    #     plt.plot(X, model(X_tensor).detach().numpy(), color='black', linewidth=0.9, label='Fitted Line')
    #     plt.tick_params(labelsize=7)
    # if(epoch+1)  == times[5]:
    #     plt.subplot(2, 3, 6)
    #     plt.scatter(X, y, s=3, label='Actual Data')
    #     plt.plot(X, model(X_tensor).detach().numpy(), color='black', linewidth=0.9, label='Fitted Line')
    #     plt.tick_params(labelsize=7)


# 设置子图间距
plt.subplots_adjust(hspace=0.3)
plt.show()
