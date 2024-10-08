#include <iostream>
#include "Node.h"
using namespace std;

int main(){

    Node<int> node1(10);
    cout<<"Node 1 item: "<<node1.getItem();

    return 0;
}