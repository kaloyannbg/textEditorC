#include <stdio.h>
#include "prots.h"

void main() {

    char str1[50] = "asdasd";

    char str2[50] = "ASDASDaS./../.../.123asd.''AD";

    char str3[] = "12312AAAAAAAasojdaosdkoasdkoaskdakosdkasdokaskdoaksod................S";

    stringSymbCutter(str3);

    if(!checkLength(str3, 20)) {
        printf("too long\n");
    }

    printf("%s", str3);

}