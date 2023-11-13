#include "math.h"
#include "stdbool.h"
#include "stdint.h"
#include "stdio.h"

#define PI 3.141592654

typedef enum
{
    DRAW_RECTANGULAR = 1,
    DRAW_SQUARE,
    DRAW_RIGHT_TRIANGLE,
    DRAW_EXIT,
} draw_type;

void draw_rectangular(uint16_t width, uint16_t height)
{
    for (uint16_t i = 0; i < width; ++i) printf("* ");
    printf("\n");

    if (height <= 1)
        return;

    for (uint16_t i = 1; i < height - 1; ++i)
    {
        for (uint16_t j = 0; j < width; ++j)
        {
            if (j == 0 || j == (width - 1))
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    for (uint16_t i = 0; i < width; ++i) printf("* ");
    printf("\n");
}

void draw_right_triangle(uint16_t edge_1, uint16_t edge_2)
{
    double angle  = atan((float) edge_2 / edge_1);
    printf("*\n");
    for (uint16_t i = 2; i < edge_1; i++)
    {
        /* code */
        printf("*");
        float k = tan(angle) * i;
        k       = 2 * k - 3;
        for (uint16_t j = 0; j < k; j++) printf(" ");
        printf("*");
        printf("\n");
    }
    for (uint16_t i = 0; i < edge_2; i++) printf("* ");
    printf("\n");
}

void show_console_draw_rectangular(void)
{
    int width = 0, height = 0;
    printf("\n You choice option 1 to draw rectangular >>>");
    printf("\n Please input width and height for rectangular !\n");
    printf("   - Width: ");
    scanf("%d", &width);
    printf("   - Height: ");
    scanf("%d", &height);
    printf("Output: %dx%d\n", width, height);
    draw_rectangular(width, height);
}

void show_console_draw_square(void)
{
    int edge = 0;
    printf("\n You choice option 2 to draw square >>>");
    printf("\n Please input edge for square !\n");
    printf("   - Edge: ");
    scanf("%d", &edge);
    printf("Output: %dx%d\n", edge, edge);
    draw_rectangular(edge, edge);
}

void show_console_right_triangle(void)
{
    int edge_1 = 0, edge_2 = 0;
    printf("\n You choice option 3 to right triangle >>>\n");

    printf("        * \n");
    printf("        * * \n");
    printf(" edge_1 *   * \n");
    printf("        * * * * \n");
    printf("           edge_2 ");

    printf("\n Please input 2 square sides !\n");
    printf("   - First edge: ");
    scanf("%d", &edge_1);
    printf("   - Second edge: ");
    scanf("%d", &edge_2);
    printf("Output: %dx%d\n", edge_1, edge_2);
    draw_right_triangle(edge_1, edge_2);
}

void printf_console(void)
{
    printf("\n----- Draw picture ----- \n");
    printf(" 1. Draw rectangular \n");
    printf(" 2. Draw square \n");
    printf(" 3. Draw right triangle \n");
    printf(" 4. Exit\n");
    printf("-------------------------- \n");
}

bool handle_choice(uint8_t choice)
{
    bool result = true;
    switch (choice)
    {
    case DRAW_EXIT:
    {
        result = false;
        printf("End program !");
        break;
    }
    case DRAW_RECTANGULAR:
    {
        show_console_draw_rectangular();
        break;
    }
    case DRAW_SQUARE:
    {
        show_console_draw_square();
        break;
    }
    case DRAW_RIGHT_TRIANGLE:
    {
        show_console_right_triangle();
        break;
    }
    default:
    {
        printf("\n Invalid choice! Try again!");
        break;
    }
    }
    return result;
}

void program_draw(void)
{
    uint8_t choice = 0;
    while (1)
    {
        /* code */
        printf_console();
        scanf("%d", &choice);
        if (handle_choice(choice) == false)
            break;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    system("cls");
    program_draw();
    return 0;
}
