#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using indexed_set = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
