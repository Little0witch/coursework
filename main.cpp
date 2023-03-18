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


void showList(List head)
{
    if (head == NULL)
        printf("Список пуст\n");
    else {
        printf("Список :\n");
        while (head != NULL) {
            printf("\nx: %d  y: %d", head->x, head->y);
            head = head->next;
        }
        printf("\n");
    }
}

bool isEmpty(List head)
{
    if (head == NULL)
        return false;

    return true;
}

void freeList(List* head)
{
    List current = *head;
    while (current != NULL)
    {
        current = current->next;
        free(*head);
        *head = current;
    }
}


int main()
{
    RenderWindow window(sf::VideoMode(1846, 1048), "SFML works!");
    CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Yellow);

    Image image;
    image.loadFromFile("Resourses/p1.jpg");
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
