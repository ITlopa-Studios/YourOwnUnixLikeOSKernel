void kernelmain(void)
{
	const char *str = "Hello World!\nAnd hello all!";
	char *vidptr = (char*)0xb8000; 	/* видео пямять начинается здесь */
	unsigned int i = 0;
	unsigned int j = 0;

	/* этот цикл очищает экран*/
	while(j < 80 * 25 * 2) {
		/* пустой символ */
		vidptr[j] = ' ';
		/* байт атрибутов */
		vidptr[j+1] = 0x07;
		j = j + 2;
	}

	j = 0;

	/* в этом цикле строка записывается в видео память */
	while(str[j] != '\0') {
        /* инит стандартного \n */
        if (str[j] == '\n') {
			i = (i / 160) * 160 + 160;
		} else {
		    /* ascii отображение */
		    vidptr[i] = str[j];
		    vidptr[i+1] = 0x07;
		    ++j;
		    i = i + 2;
        }
	}
	return;
}
/* это твое ядро на C, но надо еще ассемблер */
