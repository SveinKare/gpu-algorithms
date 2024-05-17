#include <boost/compute/algorithm/transform.hpp>
#include <boost/compute/container/vector.hpp>
#include <iostream>

using namespace std;
namespace compute = boost::compute;

int main() {
    auto device = compute::system::default_device();
    compute::context context(device);
    compute::command_queue queue(context, device);
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> b = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0};
    vector<int> c(10);
    compute::vector<int> device_a(a.size(), context);
    compute::vector<int> device_b(b.size(), context);
    compute::copy(a.begin(), a.end(), device_a.begin(), queue);
    compute::copy(b.begin(), b.end(), device_b.begin(), queue);
    compute::vector<int> device_c(c.size(), context);
    compute::transform(device_a.begin(), device_a.end(),
                       device_b.begin(), device_c.begin(), compute::plus<int>(), queue);
    compute::copy(device_c.begin(), device_c.end(), c.begin(), queue);
    cout << "c: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << c[i] << " ";
    }

    return 0;
}