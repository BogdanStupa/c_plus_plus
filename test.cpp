#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n, c(0), t;
    std::cin >> n;
    std::vector<std::pair<int, int> > a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> t;
        a[i] = { t, i + 1 };
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> t;
        a[i].first -= t;
        c += a[i].first;
        
    }
    if (c != 0) {
        std::cout << -1 << "\n";
        return;
    }
    std::sort(a.begin(), a.end(), [](std::pair<int, int> x, std::pair<int, int> y) {
        return x.first < y.first;
    });
    // for (auto d: a) {
    //     std::cout << d.first << " " << d.second << "\n";
    // }
    int l = 0, r = n - 1;
    std::vector<std::pair<int, int>> ans;
    while (l < r) {
        if (!a[l].first || !a[r].first){
            break;
        }
        if (-a[l].first > a[r].first) {
            for (int i = 0; i < a[r].first; ++i) {
                ans.push_back({ a[r].second, a[l].second });
            }
            a[l].first += a[r].first;
            a[r].first = 0;
            --r;

        } else if (-a[l].first < a[r].first) {
            for (int i = 0; i < -a[l].first; ++i) {
                ans.push_back({ a[r].second, a[l].second });
            }
            a[r].first += a[l].first;
            a[l].first = 0;
            ++l;
            
        } else {
             for (int i = 0; i < a[r].first; ++i) {
                ans.push_back({ a[r].second, a[l].second });
            }
            a[l].first = 0;
            a[r].first = 0;
            ++l;
            --r;
        }
    }

    std::cout << ans.size() << "\n";

    for (auto a: ans) {
        std::cout << a.first << " " << a.second << "\n";
    }
    
}


int main() {
    int t; 
    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}