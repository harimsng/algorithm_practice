#include <iostream>
#include <vector>
#include <utility>

std::vector<int> fruitMap;
std::vector<bool> posMap;
std::vector<std::vector<std::pair<int, int> > > track;
std::vector<std::vector<int> > ftrack;
int n;

int backtrack(std::vector<std::pair<int, int> > posArr, int time);
void printPos();

int main(int argc, char** argv)
{
    int m;

    std::cin >> n >> m;
    fruitMap.reserve(n * n);
    posMap.assign(n * n, false);
    for (int i = 0; i < n * n; ++i) {
        int fruits;

        std::cin >> fruits;
        fruitMap.push_back(fruits);
    }
    std::vector<std::pair<int, int> > posArr;
    
    for (int i = 0; i < m; ++i) {
        int x;
        int y;

        std::cin >> x >> y;
        posArr.push_back(std::pair<int, int>(x - 1, y - 1));
        track.push_back(std::vector<std::pair<int, int> >());
        ftrack.push_back(std::vector<int>());
    }
    // what if first mover is at the corner surrounded by the others
    // if m > 1, anyone who is not at the corner should be first mover
    std::cout << backtrack(posArr, 3);
    return 0;
}

int backtrack(std::vector<std::pair<int, int> > posArr, int time)
{
    static const int dx[4] = {-1, 1, 0, 0};
    static const int dy[4] = {0, 0, -1, 1};
    std::vector<int> fruitTrack;
    int maxFruits = 0;
    int curFruits = 0;

    for (int i = 0; i < posArr.size(); ++i) {
        int x = posArr[i].first;
        int y = posArr[i].second;

        if (x < 0 || x >= n || y < 0 || y >= n || posMap[n * x + y] == true)
            return 0;
    }
    for (int i = 0; i < posArr.size() - 1; ++i) {
      for (int j = i + 1; j < posArr.size(); ++j) {
        if (posArr[i].first == posArr[j].first &&
            posArr[i].second == posArr[j].second)
          return 0;
      }
    }
    for (int i = 0; i < posArr.size(); ++i) {
        int x = posArr[i].first;
        int y = posArr[i].second;
        int& fruit = fruitMap[n * x + y];

        curFruits += fruit;
        track[i].push_back(std::pair<int, int>(x, y));
        ftrack[i].push_back(fruit);
        fruitTrack.push_back(fruit);
        fruit = 0;
        posMap[n * x + y] = true;
    }
    if (time == 0) {
        printPos();
    }
    if (time != 0) {
    for (int i = 0; i < (1 << (2 * posArr.size())); ++i) {
        auto newPosArr = posArr;

        unsigned int bitmask = 0x3;
        for (int j = 0; j < posArr.size(); ++j) {
            newPosArr[j].first += dx[(i & bitmask) >> (2 * j)];
            newPosArr[j].second += dy[(i & bitmask) >> (2 * j)];
            bitmask <<= 2;
        }
        int fruits = backtrack(newPosArr, time - 1);
        if (fruits == 0)
            continue;
        if (fruits > maxFruits) {
            maxFruits = fruits;
        }
    }
    }
    for (int i = 0; i < posArr.size(); ++i) {
        int x = posArr[i].first;
        int y = posArr[i].second;

        track[i].pop_back();
        ftrack[i].pop_back();
        fruitMap[n * x + y] = fruitTrack[i];
        posMap[n * x + y] = false;
    }
    return maxFruits + curFruits;
}

void printPos()
{
  for (int i = 0; i < track.size(); ++i) {
    for (int j = 0; j < track[i].size(); ++j) {
      std::cout << "(" << track[i][j].first << ", " << track[i][j].second << ")" << "=" << ftrack[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}
