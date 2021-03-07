[toc]

> Notes For Lesson 01~04

# 01 Overview of Computer Graphics

Course Topics (mainly 4 parts)

- Rasterization
- Curves and Meshes
- Ray Tracing
- Animation / Simulation

# 02 Review of Linear Algebra

规定：课程中全是右手坐标系。应用右手螺旋。

## 向量

点乘的用途：

- 求投影

- 求夹角
- 判断方向的接近程度

叉乘的用途：

- 判定左右：看叉乘后z分量的正负，a叉乘b的z大于零，表示b在a的左侧。
- 判定点在三角形的内外：P点在AB向量、BC向量、CA向量的左侧，则在内部。

![](images/cross product usage.png)

向量叉乘改为矩阵向量乘法的方法：

![image-20210307111421021](images/cross produc formula.png)

## 矩阵

2D reflection about y-axis

![image-20210307111514916](images/matrix_vector.png)

向量点乘、叉乘对应的矩阵形式

![image-20210307111719973](images/vector_multi_in_matrix.png)

# 03 Transformation

## Contents

- Why study transformation
- 2D transformations: rotation, scale, shear
- Homogeneous coordinates
- Composing transforms
- 3D transformations

scale

shear

## rotation 推导

<img src="images/transform_rotate.png" alt="image-20210307180104885" style="zoom:80%;" />

## Linear Transforms 

= Matrices(of the same dimension)

<img src="images/linear transforms.png" alt="image-20210307180228112" style="zoom:80%;" />

## Why Homogeneous Coordinates?

Translation cannot be represented in matrix form.

![image-20210307180433678](images/translation.png)

But we don't want translation to be as special case.

## Homogenous Coordinates

<img src="images/add third coordinate.png" alt="image-20210307181005656" style="zoom:80%;" />

为啥向量的第三个坐标不是1？

答：向量具有平移不变性，所以添加的第三个坐标为0。另外，还保证了下述操作的正确性。

<img src="images/homo.png" alt="image-20210307181423255" style="zoom:80%;" />

齐次坐标下，两个点相加的结果就是两个点的中点。

## Affine Transformations

仿射变换 = 线性变换 + 平移变换

**用齐次矩阵表示仿射变换**

![image-20210307181729453](images/affine map.png)

## 2D Transformations

![image-20210307182358677](images/2d transformations.png)

## Composing Transforms

<img src="images/t0.png" alt="image-20210307190849624" style="zoom:50%;" />

<img src="images/t2" alt="image-20210307191003257" style="zoom:50%;" />

![image-20210307191212029](images/t1.png)

![image-20210307191701371](images/t3.png)

## Decomposing Complex Transforms

![image-20210307191812797](images/t4.png)

## 3D Transforms

![image-20210307192232835](images/t5.png)

![image-20210307192315672](images/t6.png)

答案：仿射变换 = 线性变换 + 平移变换，先进行线性变换，再进行平移变换

类比2d空间下的情况，3d空间下也是一样哈。

![image-20210307181729453](images/affine map.png)