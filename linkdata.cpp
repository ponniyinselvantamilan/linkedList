#include <iostream>
#include <string>

#include "linkdata.h"

using namespace std;



LinkData::LinkData() {

    curNodePtr = NULL;
    headNodePtr = NULL;
    tailNodePtr = NULL;
    nodeCount = 0;    
}



NODE* LinkData::allocateNode(void) {
    nodeCount++;
    return new NODE;
}


void LinkData::deleteNode(NODE* nodePtr) {

    if(nodeCount != 0) {
        nodeCount--;
    }
    delete nodePtr;
}



void LinkData::insertFirstItem(int item) {

    NODE* addNode = allocateNode();

    addNode->data = item;
    addNode->prev = NULL;
    addNode->next = NULL;

    headNodePtr = addNode;
    tailNodePtr = addNode;
    curNodePtr = addNode;
}



void LinkData::insertAtFront(int item) {

    NODE* addNode = NULL;

    if(headNodePtr == NULL) {
        insertFirstItem(item);
    }
    else {

        addNode = allocateNode();

        addNode->data = item;
        addNode->prev = NULL;
        addNode->next = headNodePtr;
        headNodePtr->prev = addNode;
        headNodePtr = addNode;
        curNodePtr = headNodePtr;
    }
}



void LinkData::insertAtBack(int item) {

    NODE* addNode = NULL;

    if(tailNodePtr == NULL) {

        insertFirstItem(item);

    }
    else {

        addNode = allocateNode();
        addNode->data = item;
        addNode->prev = tailNodePtr;
        addNode->next = NULL;
        tailNodePtr->next = addNode;
        tailNodePtr = addNode;
        curNodePtr = tailNodePtr;
    }
}


RETURN_STATUS LinkData::insertAtPos(int item, int pos) {

    RETURN_STATUS retCode = ERROR;

    if(pos <= 1) {
        insertAtFront(item);
    }
    else if(pos >= nodeCount) {
        cout << "Last position; " << nodeCount << ", requested position: " << pos << endl;
        insertAtBack(item);
    }
    else {

        NODE* addNode = allocateNode();
        unsigned int tempPos = 1;

        for(curNodePtr = headNodePtr->next; curNodePtr != NULL; curNodePtr = curNodePtr->next) {

            tempPos++;
            if(tempPos == pos) {

                addNode->data = item;
                addNode->prev = curNodePtr->prev;
                addNode->next = curNodePtr;
                curNodePtr->prev->next = addNode;
                curNodePtr->prev = addNode;
            }
        }
    }

    //Dummy return - Modify it later.
    retCode = SUCCESS;

    return retCode;

}


void LinkData::deleteLinkData(void) {

    if(headNodePtr == NULL) {
        cout << "Link Data is empty...!!!" << endl;
        return;
    }

    curNodePtr = headNodePtr;

    cout << "Deleting item: ";

    do {

        headNodePtr = curNodePtr->next;

        cout << " " << curNodePtr->data;

        deleteNode(curNodePtr);

        curNodePtr = headNodePtr;

    } while(headNodePtr != NULL);

    cout << endl;
}


void LinkData::deleteNodePtr(NODE* tempItr) {

    curNodePtr = tempItr->prev;

    if(tempItr == headNodePtr) {
        headNodePtr = tempItr->next;
    }
    else {
        curNodePtr->next = tempItr->next;
    }

    if(tempItr == tailNodePtr) {
        tailNodePtr = tempItr->prev;
    }
    else {
        tempItr->next->prev = curNodePtr;
    }

    deleteNode(tempItr);
}


void LinkData::insertBeforeNodePtr(int item, NODE* nodePtrRef, unsigned int pos) {

    NODE* addNode = allocateNode();

    curNodePtr = nodePtrRef;

    addNode->data = item;
    addNode->prev = curNodePtr->prev;
    addNode->next = curNodePtr;
    curNodePtr->prev->next = addNode;
    curNodePtr->prev = addNode;
}


void LinkData::insertAftBinaryAscSort(int item) {

    NODE* tempNodePtr = NULL;
    unsigned int tempPos = 1;

    tempNodePtr = headNodePtr;

    while(tempNodePtr != NULL) {

        if( (item > tempNodePtr->data) && (item < tempNodePtr->next->data) ) {

            insertBeforeNodePtr(item, tempNodePtr->next, tempPos);
            break;
        }
        tempNodePtr = tempNodePtr->next;

        tempPos++;
    }
}


void LinkData::insertAftRecursiveSort(int item) {

    NODE* tempNodePtr = NULL;

    unsigned int tempPos = nodeCount / 2;

    tempNodePtr = headNodePtr;

    while(tempNodePtr != NULL) {

        if( (item > tempNodePtr->data) && (item < tempNodePtr->next->data) ) {

            insertBeforeNodePtr(item, tempNodePtr->next, tempPos);
            break;
        }
        else {

            for(unsigned int loop = 1; loop <= tempPos; loop++) {
                tempNodePtr = tempNodePtr->next;
            }
            if()

        }


        tempPos++;
    }
}



void LinkData::insertAfterAscendingSort(int item) {

    if(headNodePtr == NULL) {

        insertFirstItem(item);
    }
    else if(headNodePtr->data >= item) {
        insertAtFront(item);
    }
    else if(tailNodePtr->data <= item) {
        insertAtBack(item);
    }
    else {
        if(nodeCount <= 10) {
            insertAftBinaryAscSort(item);
        }
        else {
            insertAftRecursiveSort(item);
        }

    }
}



void LinkData::deleteItem(int item) {

    NODE* tempItr = NULL;

    for(tempItr = headNodePtr; tempItr != NULL; tempItr = tempItr->next) {

        if(tempItr->data == item) {

            deleteNodePtr(tempItr);            

            break;
        }
    }
    return;
}


void LinkData::deleteLastItem(void) {

    NODE* tempItr = tailNodePtr;

    deleteNodePtr(tempItr);
}


void LinkData::deleteFirstItem(void) {

    NODE* tempItr = headNodePtr;

    deleteNodePtr(tempItr);
}


void LinkData::displayForward(void) {

    cout << endl << "Forward:  ";
    for(curNodePtr = headNodePtr; curNodePtr != NULL; curNodePtr = curNodePtr->next) {
        cout << " " << curNodePtr->data;
    }
    cout <<  endl << endl;
}


void LinkData::displayBackward() {

    cout << endl << "Backward: ";
    for(curNodePtr = tailNodePtr; curNodePtr != NULL; curNodePtr = curNodePtr->prev) {
        cout << " " << curNodePtr->data;
    }
    cout <<  endl;
}


string LinkData::searchItem(int item) {

    bool retStatus = false;

    for(curNodePtr = headNodePtr; curNodePtr != NULL; curNodePtr = curNodePtr->next) {

        if(curNodePtr->data == item) {
            cout << "Found the item" << endl;
            retStatus = true;
            break;
        }
    }

    if(true == retStatus) {
        return "true";
    }
    else {
        return "false";
    }
}


unsigned int LinkData::findNumberOfItems(void) {

    return nodeCount;
}



