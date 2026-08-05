// #include <ctype.h>
// #include <stdio.h>

// int main(void) {
//     char message[30] = "";
//     char converted_message[30] = "";

//     printf("Enter a message: ");

//     int length = 0;

//     while (length < 29) {
//         message[length] = getchar();

//         if (message[length] == '\n')
//             break;

//         length++;
//     }

//     for (int i = 0; i < length; i++) {
//         switch (toupper(message[i])) {
//             case 'A':
//                 converted_message[i] = '4';
//                 break;
//             case 'B':
//                 converted_message[i] = '8';
//                 break;
//             case 'E':
//                 converted_message[i] = '3';
//                 break;
//             case 'I':
//                 converted_message[i] = '1';
//                 break;
//             case 'O':
//                 converted_message[i] = '0';
//                 break;
//             case 'S':
//                 converted_message[i] = '5';
//                 break;
//             default:
//                 converted_message[i] = toupper(message[i]);
//         }
//     }

//     converted_message[length] = '\0';

//     printf("In BIFF-speak: %s!!!!!!!!!!\n", converted_message);

//     return 0;
// }

// #include <ctype.h>
// #include <stdio.h>

// int main(void) {
//     char message[80];
//     int i = 0;

//     printf("Enter a message: ");

//     while ((message[i] = getchar()) != '\n' && i < 79)
//         i++;

//     printf("In BIFF-speak: ");

//     for (int j = 0; j < i; j++) {
//         switch (toupper(message[j])) {
//             case 'A': putchar('4'); break;
//             case 'B': putchar('8'); break;
//             case 'E': putchar('3'); break;
//             case 'I': putchar('1'); break;
//             case 'O': putchar('0'); break;
//             case 'S': putchar('5'); break;
//             default:  putchar(toupper(message[j]));
//         }
//     }

//     printf("!!!!!!!!!!\n");

//     return 0;
// }


#include <ctype.h>
#include <stdio.h>

int main (void) {
    char message[30] = {""};
    char converted_message[30] = {""};

    printf("Enter a message: ");

    for (int i = 0; i < 30; i++) {
        message[i] = getchar();

        if (message[i] == '\n') {
            break;
        }
    }

    for (int i = 0; i < 30; i++) {
        printf("%c", toupper(message[i]));
        switch (toupper(message[i])) {
            case 'A': 
                converted_message[i] = '4';
                break;
            case 'B':
                converted_message[i] = '8';
                break;
            case 'E':
                converted_message[i] = '3';
                break;
            case 'I':
                converted_message[i] = '1';
                break;
            case 'O':
                converted_message[i] = '0';
                break;
            case 'S':
                converted_message[i] = '5';
                break;
            default:
                converted_message[i] = toupper(message[i]);
                break;
        }
    }

    printf("Converted message: ");
    for (int i = 0; i < 30; i++) {
        printf("%c", converted_message[i]);
    }
    printf("\n");
    // Hey dude, C is rilly cool
    return 0;
}

