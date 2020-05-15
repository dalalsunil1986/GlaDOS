unsigned short *textmemptr;
int attrib = 0x0F;
int csr_x = 0, csr_y = 0;

void* memcpy(void* dest, const void* src, int count)
{
    unsigned char* destC = (unsigned char*)dest;
    unsigned char* srcC = (unsigned char*)src;
    int i;
    for (i = 0; i < count; i++)
        destC[i] = srcC[i];
    return dest;
}

unsigned short *memsetw(unsigned short *dest, unsigned char val, int count){
    int i;
    for (i = 0; i < count; i++)
        dest[i] = val;
    return dest;
}

void outportb(unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

int strlen(const char *str)
{
    int count = 0;
    while(*str!='\0'){
        count++;
        str++;
    }
    return count;
    /* This loops through character array 'str', returning how
    *  many characters it needs to check before it finds a 0.
    *  In simple words, it returns the length in bytes of a string */
}

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
    outportb(0x3D4, 14);
    outportb(0x3D5, temp >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, temp);
}

//Clear the screen
static void cls()
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
static void settextcolor(unsigned char forecolor, unsigned char backcolor)
{
    //First 4 bytes is the background color and the last 4 is the foreground color
    attrib = (backcolor << 4) | (forecolor & 0x0F);
}

//Sets our text-mode VGA pointer, then clears the screen
static void init_video(void)
{
    textmemptr = (unsigned short *)0xB8000;
    cls();
}

//Writes a sigle character on screen
static void print_char(unsigned char c)
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

//Uses putch in a loop to write a string
static void print_string(unsigned char *text)
{
    int i;

    for (i = 0; i < strlen(text); i++)
    {
        print_char(text[i]);
    }
}
