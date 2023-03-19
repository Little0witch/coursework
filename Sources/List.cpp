#include "../Headers/List.h"

void showList(List head)
{
    if (head == nullptr)
        printf("Список пуст\n");
    else {
        printf("Список :\n");
        while (head != nullptr) {
            printf("\nx: %d  y: %d", head->x, head->y);
            head = head->next;
        }
        printf("\n");
    }
}

bool isEmpty(List head)
{
    if (head == nullptr)
        return false;

    return true;
}

void freeList(List* head)
{
    List current = *head;
    while (current != nullptr)
    {
        current = current->next;
        free(*head);
        *head = current;
    }
}

void insertListFromFile(List * head, char* nameOfFile)
{
    if (!checkFile(nameOfFile))
    {
        printf("Ошибка файла");
        return;
    }

    FILE* file = fopen(nameOfFile, "a+");
    char c;
    int x, y;
    rewind(file);
    c = getc(file);
    while (c != EOF)
    {
        if (c == '0')
            x = 10;
        else
            x = c - '0';

        c = getc(file);
        c = getc(file);

        if (c == '0')
            y = 10;
        else
            y = c - '0';

        insertNode(head,x,y);

        c = getc(file);
        c = getc(file);
    }
}

bool checkFile(char * nameOfFile)
{
    if (fopen(nameOfFile, "r") == nullptr)
        return false;

    return true;
}

void insertNode(List * head, int x, int y)
{
    List newPtr, currentPtr;
    newPtr = (List)malloc(sizeof(ListNode));

    if (newPtr == nullptr)
    {
        printf("Ошибка выделения памяти!");
        return;
    }

    newPtr->y = y;
    newPtr->x = x;

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

int sizeList(List head)
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

void removeNode(List* head, int indexOfNode)
{
    if (*head == nullptr)
    {
        return;
    }

    if (indexOfNode < 0)
    {
        return;
    }

    List remove = *head;

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
            List current = *head;
            List previous = nullptr;
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

int randomNumber(int board)
{
    sleep(1);
    srand(time(NULL));
    return 1 + rand() % board;
}

struct coordinates giveCoord(List head, int indexOfNode){
    struct coordinates coord{};
    indexOfNode--;
    int index = 0;

    if (head == nullptr)
        return coord;
    else
    {
        while (head != nullptr) {
            if (indexOfNode == index)
            {
                coord.x = head->x;
                coord.y = head->y;
                return coord;
            }
            index++;
            head = head->next;
        }
    }
}



