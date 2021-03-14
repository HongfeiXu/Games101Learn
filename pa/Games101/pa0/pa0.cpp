#include<cmath>
#include<Eigen/Core>
#include<Eigen/Dense>
#include<iostream>


void eigen_demo()
{
    // Basic Example of cpp
    std::cout << "Example of cpp \n";
    float a = 1.0, b = 2.0;
    std::cout << a << std::endl;
    std::cout << a / b << std::endl;
    std::cout << std::sqrt(b) << std::endl;
    std::cout << std::acos(-1) << std::endl;
    std::cout << std::sin(30.0 / 180.0 * acos(-1)) << std::endl;

    // Example of vector
    std::cout << "Example of vector \n";
    // vector definition
    Eigen::Vector3f v(1.0f, 2.0f, 3.0f);
    Eigen::Vector3f w(1.0f, 0.0f, 0.0f);
    // vector output
    std::cout << "Example of output \n";
    std::cout << v << std::endl;
    // vector add
    std::cout << "Example of add \n";
    std::cout << v + w << std::endl;
    // vector scalar multiply
    std::cout << "Example of scalar multiply \n";
    std::cout << v * 3.0f << std::endl;
    std::cout << 2.0f * v << std::endl;

    // Example of matrix
    std::cout << "Example of matrix \n";
    // matrix definition
    Eigen::Matrix3f i, j;
    i << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0;
    j << 2.0, 3.0, 1.0, 4.0, 6.0, 5.0, 9.0, 7.0, 8.0;
    // matrix output
    std::cout << "Example of output \n";
    std::cout << i << std::endl;
    // matrix add i + j
    std::cout << "Example of add \n";
    std::cout << i + j << std::endl;
    // matrix scalar multiply i * 2.0
    std::cout << "Example of scalar multiply \n";
    std::cout << i * 2.0 << std::endl;
    // matrix multiply i * j
    std::cout << "Example of multiply matrix by matrix\n";
    std::cout << i * j << std::endl;
    // matrix multiply vector i * v
    std::cout << "Example of multiply vector by matrix \n";
    std::cout << i * v << std::endl;
}

int main() {

    Eigen::Vector3f P(2, 1, 1);
    float angle = 45.0f/180.0f;
    
    // 法一：直接构造出变换举证，先旋转+后平移
    Eigen::Matrix3f transformation;
    transformation << 
        std::cos(angle), -std::sin(angle), 1,
        std::sin(angle), std::cos(angle), 2,
        0, 0, 1;
 
    Eigen::Vector3f P_new = transformation * P;
    std::cout << "Example of output \n";
    std::cout << P_new << std::endl;

    // 法二：构造两个矩阵
    Eigen::Matrix3f rotation;
    rotation << 
        std::cos(angle), -std::sin(angle), 0,
        std::sin(angle), std::cos(angle), 0,
        0, 0, 1;
    Eigen::Matrix3f translation;
    translation <<
        1, 0, 1,
        0, 1, 2,
        0, 0, 1;
    Eigen::Matrix3f transformation_2 =  translation * rotation;

    P_new = transformation_2 * P;
    std::cout << "Example of output \n";
    std::cout << P_new << std::endl;

    return 0;
}

/*

Example of output
2.69042
3.46372
      1
Example of output
2.69042
3.46372
      1

*/