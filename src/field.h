/*
 * field.h
 *
 *  Created on: 2016/01/13
 *      Author: makitaku
 */

#ifndef FIELD_H_
#define FIELD_H_

#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

namespace cfd {

typedef enum {
    VertexType, EdgeType, FaceType, VolumeType
} ElementType;

template<typename T>
struct ElementTraits {
    static const size_t NumberOfVertices = T::NumberOfVertices;
    typedef T::iterator iterator;
    typedef std::iterator_traits<iterator> traits;
    typedef typename traits::value_type vertex_type;
};

template<size_t N, class Derived>
class ElementBase {
public:
    typedef ElementTraits<Derived> traits;
    typedef typename traits::iterator iterator;

    static const size_t NumberOfVertices = N;

protected:
    iterator v_[NumberOfVertices];
};

struct Vertex {
private:

};

template<typename Iterator>
class Edge {
public:
    static const size_t NumberOfVertices = 2;

    typedef std::iterator_traits<Iterator> ite_traits;
    typedef ite_traits::value_type vertex_type;

    enum {
        Start, End
    };

public:

    Edge() :
            V_() {
    }

    Edge(const Edge& other) :
            V_() {
        this->V_[Start] = other.V_[Start];
        this->V_[End] = other.V_[End];
    }

    template<typename InputIterator>
    Edge(InputIterator start, InputIterator end) :
            V_() {
        this->V_[Start] = start;
        this->V_[End] = end;
    }

    ~Edge() {
    }

    Iterator operator[](size_t n) const {
        return this->V_[n];
    }

    Edge& operator=(const Edge& rhs) {
        if (&rhs == this) {
            return *this;
        }

        this->V_[Start] = rhs.V_[Start];
        this->V_[End] = rhs.V_[End];

        return *this;
    }

private:
    Iterator V_[NumberOfVertices];
};

template<typename Iterator>
class Triangle {
public:
    static const size_t NumberOfEdge = 3;

private:
    Iterator E_[NumberOfEdge];
};

template<typename Iterator>
class Quad {
public:
    static const size_t NumberOfEdge;

    typedef std::iterator_traits<Iterator> iterator_traits;
    typedef iterator_traits::value_type vertex_type;

    const vertex_type& operator[](size_t n) const {
        return *(this->E_[n]);
    }

    vertex_type& operator[](size_t n) {
        return *(this->E_[n]);
    }

private:
    Iterator E_[NumberOfEdge];
};

template<typename Cell>
struct CellTraits {
    typedef Cell::value_type value_type; ///< Type of boundary.
    typedef Cell::iterator iterator;
    typedef Cell::pointer pointer;
};

template<typename BoundaryIterator, size_t N>
class Cell {
public:
    typedef BoundaryIterator iterator;
    typedef std::iterator_traits<BoundaryIterator> ite_traits;
    typedef typename ite_traits::value_type value_type;

public:

    iterator begin() const {
        return *(this->x_);
    }

    iterator end() const {
        return *(this->x_ + N);
    }

protected:
    iterator x_[N];
};

template<typename Boundary>
struct BoundaryTraits {
    typedef Boundary::value_type value_type; ///< Type of vertex.
};

template<typename VertexIterator, size_t N>
class Boundary {
public:
    typedef VertexIterator iterator;
    typedef std::iterator_traits<VertexIterator> ite_traits;
    typedef typename ite_traits::value_type value_type;

public:

    iterator begin() const {
        return *(this->x_);
    }

    iterator end() const {
        return *(this->x_ + N);
    }

protected:
    iterator x_[N];
};

template<typename Cell>
class Field {
public:
    typedef std::list<Cell> cell_list_type;
    typedef typename CellTraits<Cell>::value_type boundary_type;
    typedef typename BoundaryTraits<boundary_type>::value_type vertex_type;

public:
    Field() {

    }

    ~Field() {

    }

private:
    cell_list_type cell_list_;
    std::list<boundary_type> boundary_list_;
    std::list<vertex_type> vertex_list_;
};

}  // namespace cfd

#endif /* FIELD_H_ */
