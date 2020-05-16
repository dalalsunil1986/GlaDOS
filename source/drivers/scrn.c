#include "../kernel/utils.h"
#include "../drivers/asm_utils.h"

unsigned short *textmemptr;
int attrib = 0x0F;
int csr_x = 0, csr_y = 0;


//Scrolls the screen
void scroll(void)
{
    unsigned blank, temp;

    /* A blank is defined as a space... we need to give it
    *  backcolor too */
    blank = 0x20 | (attrib << 8);

    /* Row 25 is the end, this means we need to scroll up */
    if(csr_y >= 25)
    {
        /* Move the current text chunk that makes up the screen
        *  back in the buffer by a line */
        temp = csr_y - 25 + 1;
        memcpy (textmemptr, textmemptr + temp * 80, (25 - temp) * 80 * 2);

        /* Finally, we set the chunk of memory that occupies
        *  the last line of text to our 'blank' character */
        memsetw (textmemptr + (25 - temp) * 80, blank, 80);
        csr_y = 25 - 1;
    }
}

//Updates cursor position
void move_csr(void)
{
    unsigned temp;

    //Finding the index in a linear chunk of memory by: Index = [(y * width) + x]
    temp = csr_y * 80 + csr_x;

    /* This sends a command to indicies 14 and 15 in the
    *  CRT Control Register of the VGA controller. These
    *  are the high and low bytes of the index that show
    *  where the hardware cursor is to be 'blinking'. To
    *  learn more, you should look up some VGA specific
    *  programming documents. A great start to graphics:
    *  http://www.brackeen.com/home/vga */
    outb(0x3D4, 14);
    outb(0x3D5, temp >> 8);
    outb(0x3D4, 15);
    outb(0x3D5, temp);
}

//Clear the screen
void cls()
{
    unsigned blank;
    int i;

    //Sets our current color
    blank = 0x20 | (attrib << 8);

    //Sets screen to spaces using current color
    for(i = 0; i < 25; i++)
        memsetw (textmemptr + i * 80, blank, 80);

    //Set the cursor back to 0,0
    csr_x = 0;
    csr_y = 0;
    move_csr();
}

//Sets forecolor and backcolor
void settextcolor(unsigned char forecolor, unsigned char backcolor)
{
    //First 4 bytes is the background color and the last 4 is the foreground color
    attrib = (backcolor << 4) | (forecolor & 0x0F);
}

//Sets our text-mode VGA pointer, then clears the screen
void init_video(void)
{
    textmemptr = (unsigned short *)0xB8000;
    cls();
}

//Writes a sigle character on screen
void print_char(char c)
{
    unsigned short *where;
    unsigned att = attrib << 8;

    //Handle a backspace, by moving the cursor back one space
    if(c == 0x08)
    {
        if(csr_x != 0) csr_x--;
    }

    //Handles tab by incrementing the cursor's x
    else if(c == 0x09)
    {
        csr_x = (csr_x + 8) & ~(8 - 1);
    }

    //returns cursor back to the margin
    else if(c == '\r')
    {
        csr_x = 0;
    }

    //if \n in string create a newline
    else if(c == '\n')
    {
        csr_x = 0;
        csr_y++;
    }

    //Any character greater than or equal to space is printable by: Index = [(y * width) + x]
    else if(c >= ' ')
    {
        where = textmemptr + (csr_y * 80 + csr_x);
        *where = c | att;   /* Character AND attributes: color */
        csr_x++;
    }

    //If the cursor is at the end of the screen create a newline
    if(csr_x >= 80)
    {
        csr_x = 0;
        csr_y++;
    }

    //Scrolls the screen and moves the cursor
    scroll();
    move_csr();
}

//Uses print_char in a loop to write a string
void print_string(char *text)
{
    int i;

    for (i = 0; i < strlen(text); i++)
    {
        print_char(text[i]);
    }
}

//Fill one line with a chosen character
void fill_line(char c, int width){

    //Set cursor to margin
    csr_x = 0;
    move_csr();

    //Write charater for givin width
    for (int i = 0; i < width; i++)
    {
        print_char(c);
    }
}

unsigned int window_borderForeColor = 0;
unsigned int window_borderBackColor = 0;
unsigned int window_fillForeColor = 0;
unsigned int window_fillBackColor = 0;

void windowcolor(unsigned int borderFore, unsigned int borderBack,unsigned int fillFore, unsigned int fillBack){
    window_borderForeColor = borderFore;
    window_borderBackColor = borderBack;
    window_fillForeColor = fillFore;
    window_fillBackColor = fillBack;
}

void create_window(int width, int height,int xOffset, int yOffset){
    if((width + xOffset) > 80 || (height + yOffset) > 25){
        settextcolor(4,15);
        print_string("[Error]: create_window(); Size/Offset too large");
        settextcolor(14,0);
    }
    else
    {

        for(int x = 0; x <= width; x++){
            for(int y = 0; y <= height; y++){            
                csr_x = x + xOffset;
                csr_y = y + yOffset;
                move_csr();

                //Draw sides
                if(x == 0 && y >= 1 && y <= height - 1 || x == width && y >= 1 && y <= height - 1 )
                {
                    settextcolor(window_borderForeColor,window_borderBackColor);
                    print_char('|');
                }else if(y == 0 || y == height){
                    settextcolor(window_borderForeColor,window_borderBackColor);
                    print_char('-');
                }else{
                    settextcolor(window_fillForeColor,window_fillBackColor);
                    print_char(' ');
                }
            }
        }

    }    
}
