#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int MXM = 2e4, MXK = 1e2;
struct st {
    int x, y, c;
}sg[MXM*MXK];
int t, n, m, sz, my, bit[MXM*MXK / 2 + 1];
pair<int, int> p[MXK], q[MXM];
int main() {
    for (scanf("%d", &t); t--;) {
        sz = my = 0;
        scanf("%d", &m);
        map<int, int> mp;
        for (int i = 0; i < m; i++) {
            scanf("%d", &n);
            for (int j = 0; j < n; j++) scanf("%d%d", &p[j].first, &p[j].second), mp[p[j].second] = 0;
            int tp = min_element(p, p + n) - p;
            q[i] = p[tp];
            int j = tp;
            do {
                sg[sz++] = { p[j].first,p[j].second,1 };
                sg[sz++] = { p[(j + 1) % n].first,p[(j + 1) % n].second,-1 };
                j = (j + 2) % n;
            } while (tp^j);
        }
        for (auto &it : mp) it.second = ++my;
        fill(bit + 1, bit + 1 + my, 0);
        sort(sg, sg + sz, [](st i, st j) {return i.x < j.x; });
        sort(q, q + m);
        int res = 0;
        for (int i = 0, j = 0; i < m; i++) {
            for (; j < sz&&sg[j].x <= q[i].first; j++)
                for (int k = mp[sg[j].y]; k <= my; k += k&-k) bit[k] += sg[j].c;
            int s = 0;
            for (int k = mp[q[i].second]; k; k -= k&-k) s += bit[k];
            res = max(res, s);
        }
        printf("%d\n", res);
    }
    return 0;
}