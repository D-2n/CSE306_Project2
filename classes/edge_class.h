#pragma once
#include "vector.h"

class Edge_class{
public:
    Edge_class(Vector &v1, Vector &v2);
    bool inside(Vector &vertex);
    bool inside_voronoi(Vector &vertex);
    Vector v1;
    Vector v2;
};