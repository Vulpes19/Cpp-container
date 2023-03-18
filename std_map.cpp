#include <iostream>
#include <map>

using namespace std;

int main( void )
{
    // std::map< std::string, int > students;
    // students["Ayman"] = 21;
    // students["saad"] = 20;
    // students["Amine"] = 24;

    // std::map< std::string, int >::iterator it = students.begin();

    // for ( ; it != students.end(); ++it )
    //     std::cout << it->first << it->second << std::endl;

    map< int, int > tree;

    tree[1] = 1;
    tree[2] = 2;
    tree[3] = 2;
    tree[4] = 4;
    tree[5] = -2;
    tree[6] = 4;
    tree[7] = -2;

    map< int, int >::iterator it = tree.begin();
    for ( ; it != tree.end(); ++it )
        std::cout << it->first << " " << it->second << std::endl;
    return (0);
}