#include "classes/polygon.h"
#include "classes/vector.h" 
#include "functions/save_svg.h"
#include <iostream>
#include <mutex>
#include <random>
#include <thread>

Vector generate_random_point(double min, double max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    std::uniform_real_distribution<> dis1(0, max+1);
    double w = dis1(gen);
    return Vector(dis(gen), dis(gen), dis1(gen));
}

Polygon create_square_around_point(const Vector& point, double side_length) {
    double half_side = side_length / 2.0;
    return Polygon({
        Vector(point.coords[0] - half_side, point.coords[1] - half_side),
        Vector(point.coords[0] + half_side, point.coords[1] - half_side),
        Vector(point.coords[0] + half_side, point.coords[1] + half_side),
        Vector(point.coords[0] - half_side, point.coords[1] + half_side)
    });
}
int main(){
    std::vector<Polygon> polygons;
    const int num_points = 1000;
    const double min_coord = 0.0;
    const double max_coord = 1.0;
    std::vector<Vector> points;
    /* Sutherland-Hodgman test
    Polygon test_triangle{
        {Vector(0, 0), Vector(0.5, 0.6), Vector(1, 0)}}; //triangle

    Polygon clipper{
        {Vector(0.2, 0.2), Vector(0.7, 0.2), Vector(0.7, 0.7), Vector(0.2, 0.7)}}; //square
    */

    Polygon background{
        {Vector(0, 0), Vector(1, 0), Vector(1, 1), Vector(0, 1)}};
    
    for (int i = 0; i < num_points; ++i) {
        Vector point = generate_random_point(min_coord, max_coord);
        points.push_back(point); 
    }



    for (int i = 0; i < num_points; ++i){
        Polygon result = background.clip_voronoi(points, points[i]);
        polygons.push_back(result);
    }
    /* Sutherland-Hodgman test result 
    Polygon res = test_triangle.clip(clipper);
    polygons.push_back(test_triangle);
    polygons.push_back(res);
    */
    save_svg(polygons, "./clip_test.svg", "none");
}