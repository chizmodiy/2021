#include <stdio.h>


#include "point.h"
#include "Ellipse.h"

int main(int argc, const char* argv[]) {


    
    
    Point* f1 = createPoint(5, 0);
    Point* f2 = createPoint(-5, 0);

    Ellipse* ellipse = createEllipseByCoords(5, -5, 13, 12);
    Ellipse* ellipse2 = createByFocusesEllipse(f1, f2, 13, 12);
    Ellipse* ellipse3 = createByParametersEllipse(17, 15);

 

    printf("Ellipses :  \n");

    printEllipse(ellipse);
    printEllipse(ellipse2);
    printEllipse(ellipse3);
    printf("\n");

    Ellipse* copy = copyEllipse(ellipse);

    printEllipse(copy);
    printf("\n");

    printf("is equal ellipse 2: %d\n", isEqualEllipse(ellipse2, copy));
    printf("is equal ellipse  : %d\n", isEqualEllipse(ellipse, copy));
    printf("is equal ellipse 3: %d\n", isEqualEllipse(ellipse3, copy));


    printf("len1: %f\n", focusLenght(ellipse));
    printf("len2: %f\n", focusLenght(ellipse2));
    printf("len3: %f\n", focusLenght(ellipse3));

    deleteEllipse(ellipse);
    deleteEllipse(ellipse2);
    deleteEllipse(ellipse3);
    deleteEllipse(copy);

    return 0;
}
