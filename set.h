/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef SET_H
#define SET_H
#define N 1024


enum ERR_
{
    ERROR_CANT_CREATE_SET,
    ERROR_NULL_POINTER,
    ERROR_OVERFLOW
};
//штука, содержащая все возможные ошибки

typedef enum ERR_ ERR;

void printMSG(ERR MSG);
//печатает сообщение об ошибке

#define stype int
//определение типа данных, 
//который будет храниться в наборе

struct set_;
//сруктура, определяющая набор



typedef struct set_ set;

set* create();
//создать новый набор


void addElem(set* s, stype x);
//добавляет элемент х в набор s, если такого элемента в нем нет
// если такой элемент уже имеется в наборе, не выполняет никаких действий


int checkElem(set* s, stype x);
//проверяет наличие элемента х в наборе s

void deleteSet(set* s);
//полностью удаляет набор s

void deleteElem(set* s, stype x);
//удаляет элемент x из набора s, если таковой в нем имеется
//если элемента в наборе нет, не выполняет никаких действий


int size(set* s);
//возвращает текущий размер набора s
void printSet(set* s);
// выводит в строку все элементы набора s

#endif /* SET_H */

