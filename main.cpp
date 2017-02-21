#include <iostream>
#include "linkdata.h"

using namespace std;


int main()
{
    cout << "Hello World!" << endl;

    RETURN_STATUS retCode = ERROR;
    LinkData linkData;

    linkData.insertAtBack(8);
    linkData.insertAtBack(9);
    linkData.insertAtBack(10);

    linkData.insertAtFront(7);
    linkData.insertAtFront(6);
    linkData.insertAtFront(5);
    linkData.insertAtFront(4);
    linkData.insertAtFront(3);
    linkData.insertAtFront(2);
    linkData.insertAtFront(1);

    linkData.insertAtBack(11);
    linkData.insertAtBack(12);


    cout << "Search for 2 " << linkData.searchItem(2) << endl;
    cout << "Search for 8 " << linkData.searchItem(8) << endl;

    cout << "Number of items: " << linkData.findNumberOfItems() << endl;

    retCode = linkData.insertAtPos(20, 0);
    cout << "retCode: " << retCode << endl;

    linkData.insertAtPos(30, 1);
    linkData.insertAtPos(40, 2);
    linkData.insertAtPos(50, 8);
    linkData.insertAtPos(60, 60);

    //linkData.displayBackward();


    linkData.displayForward();

    cout << "Deleting item 30" << endl;
    linkData.deleteItem(30);
    linkData.displayForward();

    cout << "Deleting item 60" << endl;
    linkData.deleteItem(60);
    linkData.displayForward();

    cout << "Deleting item 6" << endl;
    linkData.deleteItem(6);
    linkData.displayForward();

    cout << "Deleting last item" << endl;
    linkData.deleteLastItem();
    linkData.displayForward();

    cout << "Deleting first item" << endl;
    linkData.deleteFirstItem();
    linkData.displayForward();

    linkData.deleteLinkData();
    return 0;
}

