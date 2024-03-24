import numpy as np

# 定义一个3x3的矩阵
matrix = np.array([[1, 2, 3],
                   [4, 5, 6],
                   [7, 8, 9]])

# 使用numpy.linalg.eig函数计算特征值和特征向量
eigenvalues, eigenvectors = np.linalg.eig(matrix)

# 打印特征值和特征向量
for i in range(len(eigenvalues)):
    eigenvalue = eigenvalues[i]
    eigenvector = eigenvectors[:, i]
    print(f"Eigenvalue #{i+1}: {eigenvalue}")
    print(f"Eigenvector #{i+1}: {eigenvector}")


# Eigenvalue #1: 16.116843969807043
# Eigenvector #1: [-0.23197069 -0.52532209 -0.8186735 ]
# Eigenvalue #2: -1.1168439698070427
# Eigenvector #2: [-0.78583024 -0.08675134  0.61232756]
# Eigenvalue #3: -1.3036777264747022e-15
# Eigenvector #3: [ 0.40824829 -0.81649658  0.40824829]