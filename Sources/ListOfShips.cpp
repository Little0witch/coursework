#include "../Headers/ListOfShips.h"

bool isEmpty(ListOfShips head)
{
    if (head == nullptr)
        return true;

    return false;
}

void freeList(ListOfShips *head)
{
    ListOfShips current = *head;
    while (current != nullptr)
    {
        current = current->next;
        free(*head);
        *head = current;
    }

}

void showList(ListOfShips head) {
    if (head == nullptr)
        printf("Список пуст\n");
    else {
        printf("Список :\n");
        while (head != nullptr) {
            printf("\ndestroy: %d  size: %d  hit: %d", head->destroy, head->size, head->hit);
            showList(head->list);
            head = head->next;
        }
        printf("\n");
    }

}

int sizeList(ListOfShips head)
{
    if (head == nullptr)
        return 0;

    int size = 0;

    while (head != nullptr) {
        size++;
        head = head->next;
    }

    return size;
}

void removeNode(ListOfShips * head, int indexOfNode) {
    if (*head == nullptr)
    {
        return;
    }

    if (indexOfNode < 0)
    {
        return;
    }

    ListOfShips remove = *head;

    indexOfNode--;

    if ((*head)->next == nullptr && indexOfNode == 0)
    {
        free(*head);
        *head = nullptr;
    }
    else
    {
        if (indexOfNode == 0)
        {
            remove = *head;
            *head = (*head)->next;
            free(remove);
        }
        else
        {
            ListOfShips current = *head;
            ListOfShips previous = nullptr;
            while (current != nullptr && indexOfNode > 0)
            {
                previous = current;
                current = current->next;
                indexOfNode--;
            }
            if (current == nullptr)
            {
                printf("Index is out of range");
                return;
            } else
            {
                previous->next = current->next;
                free(current);
            }
        }
    }
}

void insertNode(ListOfShips * head, ListOfCoord list) {

    ListOfShips newPtr, currentPtr;
    newPtr = (ListOfShips)malloc(sizeof(ListNodeShips));

    if (newPtr == nullptr)
    {
        printf("Ошибка выделения памяти!");
        return;
    }

    newPtr->size = sizeList(list);
    newPtr->hit = 0;
    newPtr->destroy = false;
    newPtr->list = list;

    newPtr->next = nullptr;
    currentPtr = *head;

    if (currentPtr == nullptr)
        *head = newPtr;
    else
    {
        while (currentPtr->next != nullptr)
            currentPtr = currentPtr->next;

        currentPtr->next = newPtr;
    }


}

void autoRemoveNode(ListOfShips *head) {



}
