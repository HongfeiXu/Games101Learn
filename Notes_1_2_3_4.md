[toc]

> Notes For Lesson 01~04

# 01 Overview of Computer Graphics

Course Topics (mainly 4 parts)

- Rasterization
- Curves and Meshes
- Ray Tracing
- Animation / Simulation

# 02 Review of Linear Algebra

**规定：课程中全是右手坐标系。应用右手螺旋。**

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

**向量点乘、叉乘对应的矩阵形式**

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

<img src="images/transform_rotate.png" alt="image-20210307180104885" style="zoom: 50%;" />

## Linear Transforms 

= Matrices(of the same dimension)

<img src="images/linear transforms.png" alt="image-20210307180228112" style="zoom: 50%;" />

## Why Homogeneous Coordinates?

Translation cannot be represented in matrix form.

![image-20210307180433678](images/translation.png)

But we don't want translation to be as special case.

## Homogenous Coordinates

<img src="images/add third coordinate.png" alt="image-20210307181005656" style="zoom: 50%;" />

为啥向量的第三个坐标不是1？

答：向量具有平移不变性，所以添加的第三个坐标为0。另外，还保证了下述操作的正确性。

<img src="images/homo.png" alt="image-20210307181423255" style="zoom: 50%;" />

齐次坐标下，两个点相加的结果就是两个点的中点。

## Affine Transformations

仿射变换 = 线性变换 + 平移变换

**用齐次矩阵表示仿射变换**

![image-20210307181729453](images/affine map.png)

## 2D Transformations

<img src="images/2d transformations.png" alt="image-20210307182358677" style="zoom: 67%;" />

## Composing Transforms

<img src="images/t0.png" alt="image-20210307190849624" style="zoom:50%;" />

<img src="images/t2.png" alt="image-20210307191003257" style="zoom:50%;" />

<img src="images/t1.png" alt="image-20210307191212029" style="zoom: 67%;" />

<img src="images/t3.png" alt="image-20210307191701371" style="zoom:67%;" />

## Decomposing Complex Transforms

<img src="images/t4.png" alt="image-20210307191812797" style="zoom:67%;" />

## 3D Transforms

<img src="images/t5.png" alt="image-20210307192232835" style="zoom:67%;" />

<img src="images/t6.png" alt="image-20210307192315672" style="zoom:67%;" />

答案：仿射变换 = 线性变换 + 平移变换，先进行线性变换，再进行平移变换

类比2d空间下的情况，3d空间下也是一样哈。

<img src="images/affine map.png" alt="image-20210307181729453" style="zoom:67%;" />

# 04 Transformation Con.

## 旋转矩阵

上节课的补充：
旋转矩阵的逆 = 其转置，这类矩阵也称为正交矩阵。

## 本节内容

- 3D transformations
- Viewing transformation（观测矩阵）
  - view
  - projection
    - O
    - P

## 3D Transformations

<img src="images/trans_3d.png" alt="image-20210314104755117" style="zoom:67%;" />

### Scale

### Translate

### Rotation

先看下绕轴的旋转。

<img src="images/rot_3d.png" alt="image-20210314104956557" style="zoom: 67%;" />

- y叉乘z得到x

- x叉乘y得到y

- z叉乘x得到y，所以是这样的。

再看下任意的旋转。

<img src="images/rot_3d_2.png" alt="image-20210314105751398" style="zoom:67%;" />

<img src="images/rodrigues rotation.png" alt="image-20210314110107098" style="zoom: 67%;" />

题外话：

四元数主要是用来进行旋转的插值。

## Viewing Transformation

### View  /  Camera Transformation （视图 / 相机变换）

Think about how to take a photo: model（选好位置，人们坐好）->view(摆放相机)->projection（按下快门）

<img src="images/view.png" alt="image-20210314111122438" style="zoom:67%;" />

<img src="images/cam.png" alt="image-20210314111346681" style="zoom:67%;" />

<img src="images/cam_2.png" alt="image-20210314111457642" style="zoom:67%;" />

<img src="images/cam_3.png" alt="image-20210314111612072" style="zoom:67%;" />

### Projection transformation

- 3D to 2D
- Orthographic projection
- Perspective projection

#### Orthographic Projection

<img src="images/ortho.png" alt="image-20210314210931030" style="zoom:67%;" />

<img src="images/ortho_2.png" alt="image-20210314210957856" style="zoom:67%;" />

<img src="images/ortho_3.png" alt="image-20210314211215861" style="zoom:67%;" />

<img src="images/ortho_4.png" alt="image-20210314211344237" style="zoom:67%;" />

#### Perspective Projection

特点：近大远小；平行线不在平行

<img src="images/persp_0.png" alt="image-20210314211948741" style="zoom:67%;" />

<img src="images/persp_1.png" alt="image-20210314212103168" style="zoom:67%;" />

规定：

1. 近平面永远不变
2. 远平面z值还是f
3. 远平面中心不变

**推导“挤压”变换**

<img src="images/per_2.png" alt="image-20210314221137328" style="zoom:67%;" />

<img src="images/per_3.png" alt="image-20210314221247575" style="zoom:67%;" />

<img src="images/perc_4.png" alt="image-20210314221356843" style="zoom:67%;" />

<img src="images/perc_5.png" alt="image-20210314221431082" style="zoom:67%;" />

<img src="images/perc_6.png" alt="image-20210314221457744" style="zoom:67%;" />

<img src="images/perc_7.png" alt="image-20210314221621774" style="zoom:67%;" />

<img src="images/perc_8.png" alt="image-20210314221651141" style="zoom:67%;" />

问题：中间部分的顶点的z值经过挤压是如何变化的？正中间的顶点是向前还是向后移动呢？

解答：

将中点(0,0,(n+f)/2,1)应用挤压变换得到新的顶点坐标为(0,0,(n2+f2)/(n+f),1)，

经过大小比较，新的顶点坐标的z坐标要大，所以是更接近近平面，属于向前移动。

至于其他的，听下节课？

 



































