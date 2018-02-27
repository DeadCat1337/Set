/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "set.h"

int main()
{
    set* t = create();
    addElem(t, 3);
    addElem(t, 89);
    printSet(t);
    printf("%d\n", checkElem(t, 90));
    printf("%d\n", checkElem(t, 3));
    deleteElem(t, 3);
    printf("%d\n", size(t));
    printSet(t);
    deleteSet(t);
    
    return 0;
    
}
