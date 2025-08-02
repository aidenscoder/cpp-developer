#include "iostream"
#include "vector"
#include "any"
using namespace std;

#define function(args...)[](args)


int main() {
    int z = 10;
    auto add = function(int x, int y) {};
    return 0;
}