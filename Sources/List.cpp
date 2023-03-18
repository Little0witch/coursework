#include "../Headers/List.h"

void printList(ListNodePtr sPtr)
{
    if (sPtr == NULL)
        printf("Список пуст\n");//если в списке null то пустой
    else
    {
        printf("Список :\n");
        while (sPtr != NULL)  //делаем пока не дойдем до конца списка пока не будет там нулл
        {

            printf("x: %d and y: %d" , sPtr->pointOfX, sPtr->pointOfY);
            sPtr = sPtr->next; //указатель меняем на адресс след структуры след списка
        }
        printf("\n");
    }
}
int check(ListNodePtr sPtr)
{
    return sPtr == NULL; //если список пустой то возращается 1 - истина иначе 0 - ложь
}
void insert(ListNodePtr* sPtr)
{
    ListNodePtr newPtr, currentPtr;//нев новый узел который мы добавляем карант текущий узел
    newPtr = (ListNodePtr)malloc(sizeof(ListNode));//выделяем память под наш новый узел

    if (newPtr != NULL)//если память выделилась то продолжаем
    {
        system("cls");

        do//проверка на ввод сканф возращает 0 если ввод неправильный и !0 = 1= истина и цикл работает пока сканф не вернет 1 и тогда !1=0=ложь и цикл рушится
        {
            system("cls"); //очистка экрана
            printf("Введите число: ");
            rewind(stdin);//очистка буфера
        } while (!scanf("%d", &newPtr->data));

        printf("\n");
        newPtr->next = NULL; //зануляем указатель на след стурктуру
        currentPtr = *sPtr; //текущий указываем на начало
        if (currentPtr == NULL)//если начало у нас нулевое то есть в списке нету еще элементов
        {
            *sPtr = newPtr;//то просто начало указываем на новый узел
        }
        else
        {
            while (currentPtr->next != NULL)//делаем пока не найдем конец списка
            {
                currentPtr = currentPtr->next;//переходим к сслед узлу
            }
            currentPtr->next = newPtr;//когда дошли до конечного до указываем след на наш новый узел
        }
    }
    else//иначе кидаем ошибку и выходим
    {
        printf("Ошибка выделения памяти\n");
        return;
    }
}
void countList(ListNodePtr sPtr)
{
    int counter = 0;
    while (sPtr != 0)//делаем пока не дошли до конца списка
    {
        sPtr = sPtr->next;//переходим к след узлу
        counter++;
    }
    printf("%d\n", counter);
}
void counting_el(ListNodePtr* sPtr)
{

    if (check(*sPtr))//проверяем если список пустой то выводим это
    {
        printf("Список пуст.\n");
    }
    else
    {//иначе считаем
        printf("Количество элементов: \n");
        countList(*sPtr);
    }
}

void deleteList(ListNodePtr* sPtr)
{
    ListNodePtr current = *sPtr;//ставим текущий на начало
    while (current != NULL)//идем пока не дошли до конца списка
    {
        current = current->next;//текущий перемещаем на след узел
        free(*sPtr);//очищаем указатель на наше начало
        *sPtr = current;//перемещаем наше начало на текущий узел
    }
}