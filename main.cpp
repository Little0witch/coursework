#include <SFML/Graphics.hpp>

using namespace sf;

struct node{
    int x;
    int y;
    struct node* next;
};

typedef struct node ListNode;
typedef ListNode* List;

void showList(List);
bool isEmpty(List);
void freeList(List*);
void insertListFromFile(List*, char*);
void insertList(List*, int, int);
bool checkFile(char*);

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

        insertList(head,x,y);

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

void insertList(List * head, int x, int y)
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


int main()
{
    RenderWindow window(sf::VideoMode(1846, 1048), "SFML works!");
    CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Yellow);

    Image image;

    List head = nullptr;

    insertListFromFile(&head,"/home/user/CLionProjects/coursework/Resourses/Txt/PointsFor4");
    showList(head);

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
