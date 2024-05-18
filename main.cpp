#include <boost/compute/algorithm/transform.hpp>
#include <boost/compute/container/vector.hpp>
#include <iostream>
#include <linalg.hpp>
#include <chrono>

using namespace std;
using namespace chrono;
namespace compute = boost::compute;

void runRegularDotProduct() {
    long long iterations = 100;
    long long vectorSize = 100000000;

    vector<int> v1(vectorSize);
    vector<int> v2(vectorSize);
    for (int i = 0; i < vectorSize; i++) {
        v1[i] = 1;
        v2[i] = 2;
    }
    auto start = high_resolution_clock::now();
    for (long long i = 0; i < iterations; i++) {
        int result = linalg::dotProduct(v1, v2, vectorSize);
    }
    auto end = high_resolution_clock::now();
    auto startTime = duration_cast<microseconds>(start.time_since_epoch());
    auto endTime = duration_cast<microseconds>(end.time_since_epoch());
    auto average = (endTime.count() - startTime.count()) / iterations;
    
    cout << "dotProduct: " << average << " micro seconds" << endl;
}

void runThreadedDotProduct() {
    long long iterations = 100;
    long long vectorSize = 100000000;

    vector<int> v1(vectorSize);
    vector<int> v2(vectorSize);
    for (int i = 0; i < vectorSize; i++) {
        v1[i] = 1;
        v2[i] = 2;
    }
    auto start = high_resolution_clock::now();
    for (long long i = 0; i < iterations; i++) {
        int result = linalg::threadedDotProduct(v1, v2, vectorSize, 8);
    }
    auto end = high_resolution_clock::now();
    auto startTime = duration_cast<microseconds>(start.time_since_epoch());
    auto endTime = duration_cast<microseconds>(end.time_since_epoch());
    auto average = (endTime.count() - startTime.count()) / iterations;
    
    cout << "threadedDotProduct: " << average << " micro seconds" << endl; 
}

int main() {
    /* auto device = compute::system::default_device();
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
    } */
    runRegularDotProduct();
    runThreadedDotProduct();
    

    return 0;
}