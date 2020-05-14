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
void black_screen() {
	char* mem = (char*)0xb8000;
	for (int row = 0; row < 25; row++){
		for (int col = 0; col < 80; col++){
			*mem++ = ' ';
			*mem++ = 7;
		}
	}
}

void _start(){
	
	//0xb8000 + 2 * (row * 80 + col)
	write_string(14, "Dit is een test!");

	black_screen();

}