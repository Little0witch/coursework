#include <SFML/Graphics.hpp>
#include <ctime>
#include <unistd.h>

using namespace sf;

struct node{
    int x;
    int y;
    struct node* next;
};

struct coordinates{
    int x;
    int y;
};

typedef struct node ListNode;
typedef ListNode* List;

void showList(List);
bool isEmpty(List);
void freeList(List*);
void insertListFromFile(List*, char*);
void insertNode(List*, int, int);
bool checkFile(char*);
int sizeList(List);
void removeNode(List*, int);
int randomNumber(int);
struct coordinates giveCoord(List, int);


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

    List current = *head, remove = *head, start = *head;

    if ((*head)->next == nullptr && indexOfNode == 0)
    {
        free(*head);
        start = nullptr;
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
            int indexOfRemove = 1;
            (*head) = (*head)->next;
            while (*head != nullptr)
            {
                if (indexOfRemove == indexOfNode)
                {
                    remove = *head;
                    if ((*head)->next == nullptr)
                    {
                        free(remove);
                        current->next = nullptr;
                    }
                    else
                    {
                        current->next = (*head)->next;
                        free(remove);
                    }
                    break;
                }
                indexOfRemove++;
                (*head) = (*head)->next;
            }

        }
    }
    *head = start;
}

int randomNumber(int board)
{
    sleep(1);
    srand(time(NULL));
    return 0 + rand() % board;
}

struct coordinates giveCoord(List head, int indexOfNode){
    struct coordinates coord{};
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


int main()
{
    //RenderWindow window(sf::VideoMode(1846, 1048), "SFML works!");
    //CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Yellow);

    //Image image;

    List head = nullptr;

    //insertListFromFile(&head,"/home/user/CLionProjects/coursework/Resourses/Txt/PointsFor4");

    //showList(head);


    /*while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }*/

    return 0;
}
