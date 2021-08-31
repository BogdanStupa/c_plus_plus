#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using tree<T, null_type, less<T>, rb_tree_tag,
                    tree_order_statistics_node_update>
                    ordered_set;

ordered_set<int> ord_set;

int a;
ord_set.insert(a);
*ord_set.find_by_order(a);
ord_set.order_of_key(a);