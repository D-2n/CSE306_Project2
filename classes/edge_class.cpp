#include "edge_class.h"

Edge_class::Edge_class(Vector &v1, Vector &v2) : v1(v1), v2(v2) {}

bool Edge_class::inside (Vector &vertex){
    // P-u.norm(N)
    Vector u = (v1 + v2) / 2;

    Vector N(v2[1] - v1[1], v1[0] - v2[0]);
    double res = (vertex - u).dot(N); //define
    return res <= 0;
}
bool Edge_class::inside_voronoi (Vector &vertex){
    Vector M = (v1 + v2) / 2;
    double res = (vertex - M).dot(v2 - v1); 
    return res <= 0;
}
