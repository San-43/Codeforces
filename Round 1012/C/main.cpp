#include <bits/stdc++.h>
using namespace std;

constexpr int costOff[4] = {1, 2, 2, 5};
constexpr int xOff[4]  = {1, 1, 2, 2};
constexpr int yOff[4]  = {1, 2, 1, 2};

struct Table {
    int a, b, occ;
    int cost, seatX, seatY;
};

void update(Table &t) {
    const int s = t.a + t.b;
    t.cost = 3 * s + costOff[t.occ];
    t.seatX = 3 * t.a + xOff[t.occ];
    t.seatY = 3 * t.b + yOff[t.occ];
}

struct Comp {
    bool operator()(const Table &t1, const Table &t2) const {
        if(t1.cost != t2.cost) return t1.cost > t2.cost;
        if(t1.seatX != t2.seatX) return t1.seatX > t2.seatX;
        return t1.seatY > t2.seatY;
    }
};

void solve() {
    int n; cin >> n;
        vector<int> typ(n);
        for (int i = 0; i < n; i++)
            cin >> typ[i];

        int needed = n;
        vector<Table> gen;
        gen.reserve(needed);
        for (int s = 0; static_cast<int>(gen.size()) < needed; s++)
            for (int a = 0; a <= s && static_cast<int>(gen.size()) < needed; a++){
                int b = s - a;
                Table t {a, b, 0, 0, 0, 0};
                update(t);
                gen.push_back(t);
            }
        int genIdx = 0;

        priority_queue<Table, vector<Table>, Comp> emptyPQ, nonEmptyPQ;
        vector<pair<int,int>> ans;
        ans.reserve(n);

        for(int i = 0; i < n; i++){
            int currMin = INT_MAX;
            if(!emptyPQ.empty()) currMin = min(currMin, emptyPQ.top().cost);
            if(!nonEmptyPQ.empty()) currMin = min(currMin, nonEmptyPQ.top().cost);
            while(genIdx < static_cast<int>(gen.size()) && gen[genIdx].cost <= currMin)
                emptyPQ.push(gen[genIdx++]);

            Table chosen{};
            if(typ[i] == 0){
                if(emptyPQ.empty() && genIdx < static_cast<int>(gen.size()))
                    emptyPQ.push(gen[genIdx++]);
                chosen = emptyPQ.top();
                emptyPQ.pop();
            } else {
                if(!emptyPQ.empty() && !nonEmptyPQ.empty()){
                    Table t1 = emptyPQ.top(), t2 = nonEmptyPQ.top();
                    if(t1.cost < t2.cost || (t1.cost == t2.cost &&
                      (t1.seatX < t2.seatX || (t1.seatX == t2.seatX && t1.seatY < t2.seatY)))){
                        chosen = t1; emptyPQ.pop();
                    } else {
                        chosen = t2; nonEmptyPQ.pop();
                    }
                } else if(!emptyPQ.empty()){
                    chosen = emptyPQ.top(); emptyPQ.pop();
                } else if(!nonEmptyPQ.empty()){
                    chosen = nonEmptyPQ.top(); nonEmptyPQ.pop();
                } else {
                    emptyPQ.push(gen[genIdx++]);
                    chosen = emptyPQ.top(); emptyPQ.pop();
                }
            }
            ans.emplace_back(chosen.seatX, chosen.seatY);
            chosen.occ++;
            if(chosen.occ < 4){
                update(chosen);
                nonEmptyPQ.push(chosen);
            }
        }
        for(auto &p : ans)
            cout << p.first << " " << p.second << "\n";
}

int main() {
    cin.tie(  NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
