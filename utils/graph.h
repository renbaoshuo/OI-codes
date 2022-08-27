#include <tuple>
#include <vector>

template <typename T>
class Graph {
  private:
    // Indexes of the first edge of each vertex.
    std::vector<std::size_t> head;

    // Edges of the graph.
    // Elements in a std::tuple are <to, weight, next>
    std::vector<std::tuple<std::size_t, T, std::size_t>> edge;

  public:
    Graph() = default;

    Graph(const int &_n)
        : head(n, -1) {}

    // Add an edge from u to v with weight w.
    void add(const std::size_t &_u, const std::size_t &_v, const T &_w) {
        edge.emplace_back(_v, _w, head[_u]);
        head[_u] = edge.size() - 1;
    }

    // Add an undirected edge from u to v with weight `w`.
    void add_undirected(const std::size_t &_u, const std::size_t &_v, const T &_w) {
        add(_u, _v, _w);
        add(_v, _u, _w);
    }

    // Add an undirected edge from u to v with weight `w`, specifies the weight `rw` of reverse edge.
    void add_undirected(const std::size_t &_u, const std::size_t &_v, const T &_w, const T &_rw) {
        add(_u, _v, _w);
        add(_v, _u, _rw);
    }
};
