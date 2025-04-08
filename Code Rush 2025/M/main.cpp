#include <bits/stdc++.h>

using namespace std;

struct point {
    int x;
    int y;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> xs(n);
    vector<pair<int,int>> ys(m);
    for (int i = 0; i < n; i++) {
        cin >> xs[i].first;
        xs[i].second = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> ys[i].first;
        ys[i].second = i;
    }
    ranges::sort(xs,
                 [](const auto& a, const auto& b) {
                     return a.first < b.first;
                 });
    ranges::sort(ys,
                 [](const auto& a, const auto& b) {
                     return a.first < b.first;
                 });

    int h, l;
    cin >> h >> l;
    vector<point> points;
    point tmp{
        h,
        0,
    };
    points.push_back(tmp);
    for (int i = 1; i <= l; i++) {
        tmp.x++;
        tmp.y++;
        points.push_back(tmp);
    }

    bool yflag = false;
    bool xflag = false;

    for (int i = 0; i < points.size(); i++) {
        int y = -1;
        int init = 0, end = ys.size() - 1;
        int indexy = -1;
        while (init <= end) {
            int mid = init + (end - init) / 2;
            if (ys[mid].first == points[i].y) {
                y = ys[mid].first;
                indexy = ys[mid].second;
                break;
            }
            if (ys[mid].first > points[i].y) {
                y = ys[mid].first;
                indexy = ys[mid].second;
                end = mid - 1;
            } else
                init = mid + 1;
        }

        if (y == -1) {
            yflag = true;
        } else {
            y = y - points[i].y;
        }

        int x = -1;
        int indexx = -1;
        init = 0;
        end = xs.size() - 1;

        while (init <= end) {
            int mid = init + (end - init) / 2;

            if (xs[mid].first == points[i].x) {
                x = xs[mid].first;
                indexx = xs[mid].second;
                break;
            }
            if (xs[mid].first < points[i].x) {
                x = xs[mid].first;
                indexx = xs[mid].second;
                init= mid + 1;
            } else {
                end = mid - 1;
            }
        }
        if (x == -1) {
            xflag = true;
        } else {
            xflag = false;
            x = points[i].x - x;
        }
        if (yflag && xflag) {
            cout << -1 << " ";
            continue;
        }
        if (yflag) {
            cout << 'A' << indexx << " ";
        } else if (xflag) {
            cout << 'T' << indexy << " ";
        } else {
            if (x <= y) {
                cout << 'A' << indexx << " ";
            } else {
                cout << 'T' << indexy << " ";
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}