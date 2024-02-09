#include <string>
#include <vector>

/** [
     * ["blue", "red", "orange", "red"],
     * ["red", "RED", "blue", "orange"],
     * ["blue", "orange", "red", "red"],
     * ["orange", "orange", "red", "blue"]
 * ],
 * 1, 1 */
using namespace std;

struct min_coords {
    int h;
    int w;

    bool is_in_range(const int h, const int w) const {
        return this->h <= h && this->w <= w;
    }
    
    bool is_min(const int h, const int w) const {
        return this->h == h && this->w == w;
    }
};

struct max_coords {
    int h;
    int w;

    bool is_in_range(const int h, const int w) const {
        return this->h >= h && this->w >= w;
    }

    bool is_max(const int h, const int w) const {
        return this->h == h && this->w == w;
    }
};

struct adjacent_coords {
    bool is_adjacent(const int h, const int w) const {
        const min_coords min = {h - 1, w - 1};
        if (!min.is_in_range(h, w)) {
            return false;
        }

        const max_coords max = {h + 1, w + 1};
        if (!max.is_in_range(h, w)) {
            return false;
        }

        const bool is_on_edge = this->is_on_edge(h, w);
        if (is_on_edge) {
            return true;
        }

        return true;
    }

    bool is_on_edge(const int h, const int w) const {
        const min_coords min = {h - 1, w - 1};
        const max_coords max = {h + 1, w + 1};
        const bool is_min = min.is_min(h, w);
        const bool is_max = max.is_max(h, w);

        return is_min || is_max;
};

int solution(vector<vector<string> > board, int h, int w) {
    const string selected = board[h][w];

    int match = 0;

    const min_coords min = {h - 1, w - 1};
    const max_coords max = {h + 1, w + 1};

    for (auto i = 0; i < board.size(); ++i) {
        for (auto j = 0 ; j < board[0].size(); ++j) {
            adjacent_coords adjacent;
            if (!adjacent.is_adjacent(i, j))
                continue;
                
            const string color = board[i][j];
            if (color == selected) {
                ++match;
                continue;
            }
        }
    }

    return match;
}
