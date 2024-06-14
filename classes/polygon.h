#pragma once
#include "vector.h"
#include "edge_class.h"

#include <vector>

class Polygon{
public:
    Polygon(std::vector<Vector> vertices = {});
    std::vector<Vector> vertices;
    std::vector<Edge_class> edges;
    Polygon clip(Polygon &clipPolygon);
    Polygon clip_voronoi(std::vector<Vector> &points, Vector &p_i);

};