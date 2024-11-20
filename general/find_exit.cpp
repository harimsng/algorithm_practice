#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

constexpr int intmax = 0x7fffffff;

struct pos {
  pos(): dist(intmax) {};
  int x;
  int y;
  int dist;
  bool operator>(const pos& rhs) const
  {
    return this->dist > rhs.dist;
  };
};

typedef std::priority_queue<pos, std::vector<pos>, std::greater<pos>> pqueue;

int n;
int m;

int get_shortest_path(const pos& start, const pos& end, std::vector<char>& map);
void visit_nodes(pqueue& pos_queue, std::vector<char>& map, std::vector<int>& distance);

int main()
{
  std::vector<char> map;
  pos start;
  pos end;
  int ghost_path = 2001;

  std::cin >> n >> m;
  map.reserve(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;

      std::cin >> c;
      switch (c) {
        case 'D':
          end.x = i;
          end.y = j;
          break;
        case 'N':
          start.x = i;
          start.y = j;
          start.dist = 0;
          break;
        default:
          break;
      }
      map.push_back(c);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (map[i * m + j] != 'G') {
        continue;
      }
      int path = std::abs(end.x - i) + std::abs(end.y - j);
      if (path < ghost_path) {
        ghost_path = path;
      }
    }
  }
  int path = get_shortest_path(start, end, map);
  std::cout << (path < ghost_path ? "Yes" : "No") << '\n';
}

/*
 * dijkstra
 * 1. create set of unvisited nodes
 * 2. assign to every node a distance from source node.
 * 3. visit node having shortest path(0 for source node) in the unvisited set.
 * 4. update distance of neighboring nodes using distance of the current node and
 *    weight of the edge.
 * 5. after updating every neighboring nodes, mark the current node as visited and proceed to step 3.
 * 6. loop(3-5) exits, every nodes has shortest path from the source node.
 */
int get_shortest_path(const pos& start, const pos& end, std::vector<char>& map)
{
  std::vector<int> distance(n * m, intmax);
  pqueue  pos_queue;

  distance[m * start.x + start.y] = 0;
  pos_queue.push(start);
  while (pos_queue.size() > 0) {
    visit_nodes(pos_queue, map, distance);
  }
  return distance[m * end.x + end.y];
}

void visit_nodes(pqueue& pos_queue, std::vector<char>& map, std::vector<int>& distance)
{
  static const int dx[4] = {-1, 1, 0, 0};
  static const int dy[4] = {0, 0, -1, 1};
  // visit a node
  const pos node = pos_queue.top();

  pos_queue.pop();
  for (int i = 0; i < 4; ++i) {
    // update neighboring nodes
    pos neighbor;

    neighbor.x = node.x + dx[i];
    neighbor.y = node.y + dy[i];
    if (neighbor.x < 0 || neighbor.x >= n || neighbor.y < 0 || neighbor.y >= m ||
        map[m * neighbor.x + neighbor.y] == '#') {
      continue;
    }
    neighbor.dist = node.dist + 1;
    if (distance[m * neighbor.x + neighbor.y] == intmax) {
      pos_queue.push(neighbor);
    }
    if (neighbor.dist < distance[m * neighbor.x + neighbor.y]) {
      distance[m * neighbor.x + neighbor.y] = neighbor.dist;
    }
  }
  // mark as visited
  map[m * node.x + node.y] = '#';
}
