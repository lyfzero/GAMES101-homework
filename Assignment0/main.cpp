#include<cmath>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<iostream>

void testEigenVector();
void testEigenMatrix();
Eigen::Vector3f transformation(Eigen::Vector3f p, float x, float y, float a);
int main(){
    // testEigenVector();
    // testEigenMatrix();
    Eigen::Vector3f p, q;
    p << 1, 2, 1;
    std::cout << "Vector P \n";
    std::cout << p << std::endl;
    std::cout << "Input translation(x, y) and rotation(alpha) \n";
    float x, y, a;
    std::cin >> x >> y >> a;
    q = transformation(p, x, y, a);
    std::cout << "After transformation \n";
    std::cout << q << std::endl;
    return 0;
}

void testEigenVector() {
    // Example of vector
    std::cout << "Example of vector \n";
    // vector definition
    Eigen::Vector3f v(1.0f,2.0f,3.0f);
    Eigen::Vector3f w(1.0f,0.0f,0.0f);
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
    // vector dot multiply
    std::cout << "Example of vector dot product \n";
    std::cout << v.dot(w) << std::endl;
    // vector cross multiply
    std::cout << "Examole of vector cross product \n";
    std::cout << v.cross(w) << std::endl;
}

void testEigenMatrix() {
    // Example of matrix
    std::cout << "Example of matrix (3x3) \n";
    // matrix definition
    Eigen::Matrix3f i,j;
    i << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0;
    j << 2.0, 3.0, 1.0, 4.0, 6.0, 5.0, 9.0, 7.0, 8.0;
    // matrix output
    std::cout << "Example of output \n";
    std::cout << i << std::endl;
    std::cout << j << std::endl;
    Eigen::MatrixXf m(3,4);
    m << 1,2,3,4,5,6,7,8,9,10,11,12;
    std::cout << "Example of output m (3x4) \n";
    std::cout << m << std::endl;

    // matrix transposition
    std::cout << "Example of matrix transposition \n";
    std::cout << m.transpose() << std::endl;    // not inplace

    // matrix add i + j
    std::cout << "Example of add \n";
    std::cout << i + j << std::endl;
    // matrix scalar multiply i * 2.0
    std::cout << "Example of scaler multiply \n";
    std::cout << i * 3 << std::endl;
    // matrix multiply i * j
    std::cout << "Example of matrix multiply \n";
    std::cout << i * j << std::endl;
    std::cout << "Example 2 \n";
    std::cout << i * m << std::endl;
    // matrix multiply vector i * v
    std::cout << "Example of matrix and vector multiply \n";
    Eigen::VectorXf v(3);
    v << 1,2,3;
    std::cout << i * v << std::endl;
}

Eigen::Vector3f transformation(Eigen::Vector3f p, float x, float y, float a) {
    Eigen::Matrix3f T;
    Eigen::Vector3f q;
    float cosA = std::cos(a/180*acos(-1)), sinA = std::sin(a/180*acos(-1));
    T << cosA, -1*sinA, x, sinA, cosA, y, 0, 0, 1;
    // std::cout << T << std::endl;
    q = T*p;
    std::cout << q << std::endl;
}
