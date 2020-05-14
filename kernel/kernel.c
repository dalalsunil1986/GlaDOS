void write_string( int colour, const char *string )
{
    volatile char *video = (volatile char*)0xB8000;
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = colour;
    }
}

//80x25

void _start(){

	char* mem = 0xb8000;
	//0xb8000 + 2 * (row * 80 + col)
	write_string(14, "KAAAS!!");

}