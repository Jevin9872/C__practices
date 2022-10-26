#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> A,B;
    cout<<A.empty()<<endl;
    A.push(123);

    cout<<A.top()<<endl;
    A.pop();

    cout<<A.empty()<<endl;
}