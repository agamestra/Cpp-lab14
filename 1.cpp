#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct Node       //Структура являющаяся звеном списка
{
        int x;     //Значение x будет передаваться в список
        int y;
        struct Node *next,*prev; //Указатели на адреса следующего и предыдущего элементов списка
};


struct List   //Создаем тип данных Список
{
        Node *head;
        Node *tail;  //Указатели на адреса начала списка и его конца
};


void add( List *list, int x , int y )
{
        Node *temp = new Node(); // Выделение памяти под новый элемент структуры
        temp->next = NULL;       // Указываем, что изначально по следующему адресу пусто
        temp->x = x;             // Записываем значение в структуру
        temp->y = y;

        if ( list->head != NULL ) // Если список не пуст
        {
                temp->prev = list->tail; // Указываем адрес на предыдущий элемент в соотв. поле
                list->tail->next = temp; // Указываем адрес следующего за хвостом элемента
                list->tail = temp;       //Меняем адрес хвоста
        }
        else //Если список пустой
        {
                temp->prev = NULL; // Предыдущий элемент указывает в пустоту
                list->head = list->tail = temp;    // Голова=Хвост=тот элемент, что сейчас добавили
        }
}

void print( List * list )
{
        Node * temp = list->head;  // Временно указываем на адрес первого элемента
        while( temp != NULL )      // Пока не встретим пустое значение
        {
                cout << temp->x <<" "; //Выводим значение на экран
                temp = temp->next;     //Смена адреса на адрес следующего элемента
        }
        cout<<"\n";
}

void make ( List * list, int n )
{
        int i,x, y;
        for (i=0; i<n; i++)
        {
                x=rand();
                y=rand();
                add(list, x, y);
        }
}

Node *first_search (List * list, int x, int y)
{
        Node *temp = list -> head;
        while( temp->next != NULL)
        {
                if (temp->x == x || temp ->y == y)
                {
                        return temp;
                }
                temp = temp->next;
        }
        return NULL;
}



int main() {
        List list;
        list.head = list.tail = NULL;
        add( &list, 1, 1 );
        add( &list, -1, 1 );
        print( &list );
        return 0;
}
