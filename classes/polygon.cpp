#include "polygon.h"
#include "vector.h"
#include "edge_class.h"
#include "iostream"
#include <vector>
Polygon::Polygon(std::vector<Vector> vertices) : vertices(vertices){};

void generate_edges(Polygon *polygon){ //CALL ONLY ON EMPTY POLYGONS
    for (int i = 0; i < polygon->vertices.size(); ++i){
        Vector v1 = polygon->vertices[i];
        Vector v2 = polygon->vertices[(i > 0 ) ? i - 1 : polygon->vertices.size()-1];
        polygon->edges.push_back(Edge_class(v2,v1));
    }
}

Vector intersect(Vector &v1, Vector &v2, Edge_class &edge){
    Vector N(v2[1] - v1[1], v1[0] - v2[0], 1);
    double t = (v1 - edge.v1).dot(N) / (edge.v2 - edge.v1).dot(N);
    return edge.v1 + (edge.v2 - edge.v1) * t;
}

Vector intersect_voronoi(Vector &v1, Vector &v2, Edge_class &edge){
    Vector M = (v1 + v2) / 2;   
    Vector M_prime = M + (v1-v2)*(v1.weight - v2.weight)/(2*((v1 - v2).norm2()));
    double t = (M_prime - edge.v1).dot(v1 - v2) / (edge.v2 - edge.v1).dot(v1 - v2);
    return edge.v1 + (edge.v2 - edge.v1) * t;
}

Polygon Polygon::clip(Polygon &clipPolygon){
    Polygon subjectPolygon (*this);
    generate_edges(&clipPolygon);
    for (auto edge : clipPolygon.edges){
        Polygon res = Polygon();
        for (int i = 0; i < subjectPolygon.vertices.size(); ++i){

            Vector curr_vertex = subjectPolygon.vertices[i];
            Vector prev_vertex = subjectPolygon.vertices[( i > 0 ) ?  i - 1 : subjectPolygon.vertices.size()-1];
            Vector intersection = intersect(prev_vertex, curr_vertex, edge);

            if (edge.inside(curr_vertex)){
                if (!edge.inside(prev_vertex)){
                    res.vertices.push_back(intersection);
                }
                res.vertices.push_back(curr_vertex);
            }else if(edge.inside(prev_vertex)){
                res.vertices.push_back(intersection);
            }
        }
        subjectPolygon = res;   
    }
    return subjectPolygon;
}
Polygon Polygon::clip_voronoi(std::vector<Vector> &points, Vector &p_i){
    Polygon subjectPolygon (*this);
    for (auto point : points){
        Polygon res = Polygon();
        if (point == p_i){
            continue;
        }
        for (int i = 0; i < subjectPolygon.vertices.size(); ++i){

            Vector curr_vertex = subjectPolygon.vertices[i];
            Vector prev_vertex = subjectPolygon.vertices[( i > 0 ) ?  i - 1 : subjectPolygon.vertices.size()-1];
            Edge_class clipper_edge = Edge_class(prev_vertex, curr_vertex);
            Edge_class p_edge = Edge_class(p_i, point);

            Vector intersection = intersect_voronoi(p_i, point, clipper_edge);

            if (p_edge.inside_voronoi(curr_vertex)){
                if (!p_edge.inside_voronoi(prev_vertex)){
                    res.vertices.push_back(intersection);
                }
                res.vertices.push_back(curr_vertex);
            }else if(p_edge.inside_voronoi(prev_vertex)){
                res.vertices.push_back(intersection);
            }
        }
        subjectPolygon = res;   
    }
    return subjectPolygon;
}