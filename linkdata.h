#ifndef LINKDATA_H
#define LINKDATA_H

#include <string>


typedef enum {

    ERROR = 0,
    SUCCESS,
    POSITION_INVALID,
    ITEM_NOT_FOUND,
    ITEM_FOUND,
} RETURN_STATUS;


typedef struct Node {

    struct Node* prev;
    int data;
    struct Node* next;
} NODE;



class LinkData {

    private:
        NODE* curNodePtr;
        NODE* headNodePtr;
        NODE* tailNodePtr;
        unsigned int nodeCount;        

        void deleteNode(NODE* nodePtr);
        NODE* allocateNode(void);

        void insertFirstItem(int item);
        void deleteNodePtr(NODE* tempItr);

    public:
        LinkData();
        void insertAtFront(int item);
        void insertAtBack(int item);

        RETURN_STATUS insertAtPos(int item, int pos);

        void deleteLinkData(void);
        void deleteItem(int item);

        void deleteLastItem(void);
        void deleteFirstItem(void);

        void displayForward(void);
        void displayBackward(void);

        std::string searchItem(int item);
        unsigned int findNumberOfItems(void);
};

#endif // LINKDATA_H
