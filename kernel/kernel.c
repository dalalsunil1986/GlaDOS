void _start(){
	char* video_memory = (char*) 0xb8000;
	*video_memory = 'X';
	while(1) {
		*video_memory = 'X';	
	}
}
