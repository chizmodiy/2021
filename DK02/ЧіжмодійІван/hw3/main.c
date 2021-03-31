#include "list.h"

int main() {

  
    CharList* list = createCharList();              //Створюємо двозв'язний список типу char
   
    printf("\n");

    //Додаємо елементи до списку
    addCharValueToCharList(list, 'C');
    addCharValueToCharList(list, 'h');
    addCharValueToCharList(list, 'i');
    addCharValueToCharList(list, 'z');
    addCharValueToCharList(list, ' o');
    addCharValueToCharList(list, 'd');
    addCharValueToCharList(list, 'i');
    addCharValueToCharList(list, 'y');
    
    //Друкуємо список
    printCharList(list);

    insertCharItemToCharListAtIndex(list, 4, 'm'); //вставка пропущеної літери за індексом
   
    printCharList(list);//друкуємо редактований список
    
    printf("Number of characters : %d", SizeOfList(list));//розрахунок кількості елементів в списку

    removeAllItems(list);
    
    
    deleteCharList(list);
    return 0;
}
