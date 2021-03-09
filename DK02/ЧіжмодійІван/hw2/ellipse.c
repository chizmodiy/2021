#include<stdio.h>
#include "Ellipse.h"
#include "point.h"
#include <stdlib.h>
#include <math.h>




Ellipse* createByParametersEllipse(int a, int b) 
{
    return createEllipseByCoords(sqrt(a * a - b * b), -sqrt(a * a - b * b), a, b); 
    

}



int isPointBelongsToEllipse(Point p, Ellipse e) 
{
    if ((p.x * p.x / (e.a * e.a)) + (p.y * p.y / (e.b * e.b)) == 1)
    {
        return 1;                                                                         //перевірка значень на відповідніть до рівняння еліпса (чи належить еліпсу)
    }
    return -1;
}



Ellipse* createByFocusesEllipse(Point* f1, Point* f2, int a, int b) 
{
    if (NULL == f1 || NULL == f2) 
    {
        return NULL;                          //фокус еліпса != 0 .
    }

    Ellipse* ellipse = (Ellipse*)malloc(sizeof(Ellipse)); //виділення пам'яті.
    if (NULL != ellipse && f1->x == sqrt(a * a - b * b) && f2->x == -sqrt(a * a - b * b)) 
    {
        ellipse->f1 = copyPoint(f1);  // присвоюються ті самі значення для  copyPoint , що і в першому фокусі взятого із ellipse
        ellipse->f2 = copyPoint(f2); 
        ellipse->a = a;
        ellipse->b = b;
    }

    return ellipse;
}



Ellipse* createEllipseByCoords(int x1, int x2, int a, int b) 
{
    Ellipse* ellipse = (Ellipse*)malloc(sizeof(Ellipse)); //виділення пам'яті
    if (NULL != ellipse && x1 == sqrt(a * a - b * b) && x2 == -sqrt(a * a - b * b)) 
    {
        ellipse->f1 = createPoint(x1, 0);
        ellipse->f2 = createPoint(x2, 0);
        ellipse->a = a;
        ellipse->b = b;
    }
    return ellipse;
}



void deleteEllipse(Ellipse* ellipse) {
    if (NULL != ellipse) {
        deletePoint(ellipse->f1);
        deletePoint(ellipse->f2);
        free(ellipse);
    }
}




void printEllipse(Ellipse* ellipse) {
    if (NULL != ellipse) {
        printf("F1");
        printPoint(ellipse->f1);
        printf("F2");
        printPoint(ellipse->f2);
        printf("\n");
        printf("a : %i\n", ellipse->a);
        printf("b : %i\n", ellipse->b);
        printf("\n");
    }
}




Ellipse* copyEllipse(Ellipse* ellipse) {
    if (NULL == ellipse) {
        return NULL;
    }
    return createByFocusesEllipse(ellipse->f1, ellipse->f2, ellipse->a, ellipse->b);
}



int isEqualEllipse(Ellipse* ellipse1, Ellipse* ellipse2) {
    if (NULL == ellipse1 || NULL == ellipse2) {
        return -1;
    }
    return (isEqualPoints(ellipse1->f1, ellipse2->f1) && isEqualPoints(ellipse1->f2, ellipse2->f2) && (ellipse1->a == ellipse2->a) && (ellipse1->b == ellipse2->b)) ? 1 : 0;
}




double focusLenght(Ellipse* ellipse) {
    if (NULL == ellipse) {
        return -1;
    }
    return ellipse->f1->x - ellipse->f2->x;
}
