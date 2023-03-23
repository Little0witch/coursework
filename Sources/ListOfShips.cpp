#include "../Headers/ListOfShips.h"

bool isEmpty(ListOfShips head)
{
    if (head == nullptr)
        return true;

    return false;
}
//TODO::make normal freeList
void freeList(ListOfShips *head)
{
    *head = nullptr;
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
            printf("destroy: %d  size: %d  hit: %d \n", head->destroy, head->size, head->hit);
            showList(head->list);
            printf("\n");
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

int isHit(ListOfShips head, ListOfShips*removeHead, int x, int y) //-1 мимо 0 попали
{
    ListOfShips current = head;

    int index = 0, flag = -1;

    if (current == nullptr)
        return -10;
    else
    {
        while (current != nullptr) {

            if (findNode(current->list,x,y))
            {
                current->hit++;
                removeNode(&current->list,x,y);

                flag = 0;

                if (current->hit == current->size)
                {
                    current->destroy = true;
                    flag = current->size;
                }

                break;
            }
            index++;
            current = current->next;
        }
    }

    if(flag > 0)
        autoRemoveNode(removeHead);

    return flag;
}

void autoRemoveNode(ListOfShips * head) {
    if (*head == nullptr)
    {
        return;
    }

    ListOfShips remove = *head;

    if ((*head)->next == nullptr && (*head)->destroy)
    {
        free(*head);
        *head = nullptr;
    }
    else
    {
        if ((*head)->next != nullptr && (*head)->destroy)
        {
            remove = *head;
            *head = (*head)->next;
            free(remove);
        }
        else
        {
            ListOfShips current = *head;
            ListOfShips previous = nullptr;
            while (current != nullptr)
            {
                if (current->destroy)
                    break;
                else
                {
                    previous = current;
                    current = current->next;
                }
            }
            if (current == nullptr)
                return;
            else
            {
                previous->next = current->next;
                free(current);
            }
        }
    }
}
