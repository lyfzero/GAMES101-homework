

要修改的部分就是Triangle.hpp 中判断光线与三角面是否有交点的函数，和Render.hpp中的Render函数生成每个像素投射的光线。



第一个就只要直接应用 Moller -Trumbore 算法来计算，调用vector.hpp中提供的计算叉乘和点乘的函数。需要注意的是，判断当交点在三角形内部时，需要更新tnear\u\v，若不在内部，则不需更新。



第二个要找到像素点(i, j)在投影面上的位置(x, y)，给定i, j，首先要找到这个像素的中心点，即(i+0.5, j+0.5)，分别除以宽度和高度，将其变换到(0, 1)范围内。再将其乘以2，减去1.0，可将x和y分别变换到(-1.0, 1.0)间。最后只要乘以投影面的scale，同时x乘以长宽比就好了。

找到像素在投影面的位置后，创建一条从(0, 0, 0)到(x, y, -1)的光线，标准化后调用光线投递函数castRay。