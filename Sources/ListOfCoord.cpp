#include "../Headers/ListOfCoord.h"


void showList(ListOfCoord head)
{
    if (head == nullptr)
        printf("Список пуст\n");
    else {
        printf("Список :\n");
        while (head != nullptr) {
            printf("x: %d  y: %d\n", head->x, head->y);
            head = head->next;
        }
        printf("\n");
    }
}

bool isEmpty(ListOfCoord head)
{
    if (head == nullptr)
        return true;

    return false;
}

//TODO::make normal freeList
void freeList(ListOfCoord* head)
{
    *head = nullptr;
    ListOfCoord current = *head;
    while (current != nullptr)
    {
        current = current->next;
        free(*head);
        *head = current;
    }


}


void insertListFromFile(ListOfCoord * head, char* nameOfFile)
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

void insertNode(ListOfCoord * head, int x, int y)
{
    ListOfCoord newPtr, currentPtr;
    newPtr = (ListOfCoord)malloc(sizeof(ListNode));

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

int sizeList(ListOfCoord head)
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

void removeNode(ListOfCoord* head, int indexOfNode)
{
    if (*head == nullptr)
    {
        return;
    }

    if (indexOfNode < 0)
    {
        return;
    }

    ListOfCoord remove = *head;

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
            ListOfCoord current = *head;
            ListOfCoord previous = nullptr;
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
    return 0 + rand() % board;
}

struct coordinates giveCoord(ListOfCoord head, int indexOfNode){
    struct coordinates coord{};
    int index = 0;

    if (head == nullptr || indexOfNode > sizeList(head))
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

bool findNode(ListOfCoord head, int x, int y) {
    if (head == nullptr)
        return false;

    while (head != nullptr) {
        if (head->y == y && head->x == x)
            return true;
        head = head->next;
    }
    return false;
}

void removeNode(ListOfCoord * head, int x, int y) {
    if (*head == nullptr)
    {
        return;
    }

    ListOfCoord remove = *head;

    if ((*head)->next == nullptr && (*head)->x == x && (*head)->y == y)
    {
        free(*head);
        *head = nullptr;
    }
    else
    {
        if ((*head)->next != nullptr && (*head)->x == x && (*head)->y == y)
        {
            remove = *head;
            *head = (*head)->next;
            free(remove);
        }
        else
        {
            ListOfCoord current = *head;
            ListOfCoord previous = nullptr;
            while (current != nullptr )
            {
                if (current->y == y && current->x == x)
                    break;
                else
                {
                    previous = current;
                    current = current->next;
                }
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

struct coordinates giveMinCoord(ListOfCoord head) {
    struct coordinates minCoord{};

    if (head == nullptr)
        return minCoord;

    minCoord.x = head->x;
    minCoord.y = head->y;

    while (head != nullptr) {

        if (head->y + head->x < minCoord.x + minCoord.y)
        {
            minCoord.y = head->y;
            minCoord.x = head->x;
        }

        head = head->next;
    }

    return minCoord;
}

struct coordinates giveMaxCoord(ListOfCoord head) {
    struct coordinates maxCoord{};

    if (head == nullptr)
        return maxCoord;

    maxCoord.x = head->x;
    maxCoord.y = head->y;

    while (head != nullptr) {

        if (head->y + head->x > maxCoord.x + maxCoord.y)
        {
            maxCoord.y = head->y;
            maxCoord.x = head->x;
        }

        head = head->next;
    }

    return maxCoord;
}



