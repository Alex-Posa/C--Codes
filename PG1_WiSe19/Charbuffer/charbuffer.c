#include "charbuffer.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Neuen CharBuffer auf dem Heap reservieren
 * @param initial_size: initiale Größe von content
 */
CharBuffer* charbuffer_new(int initial_size) {
	CharBuffer* buf = calloc(sizeof(CharBuffer), 1);
	buf->content_size = initial_size;
	buf->content_len = 0;
	buf->content = calloc(sizeof(char), initial_size);
	return buf;
}

/*
 * Ein Zeichen an den CharBuffer anfügen
 * @param buf: Zeiger auf CharBuffer
 * @param c: Anzufügendes Zeichen
 */
int charbuffer_append(CharBuffer* buf, char c) {
	if(buf == NULL) {
		return CHARBUFFER_ERR_NULLPTR;
	}

	if(buf->content == NULL) {
		int initial_size = 10;
		buf->content = calloc(sizeof(char), 10);
		buf->content_len = 0;
		buf->content_size = initial_size;	
	}

	if(buf->content_len+2 > buf->content_size) {
		// Merken der alten werte
		char* tmp = buf->content;
		int old_size = buf->content_size;

		// Vergrößern versuchen
		buf->content_size += 10;
		buf->content = realloc(buf->content, buf->content_size);

		// Prüfen obs geklappt hat
		if(buf->content == NULL) {
			// Gegebenenfalls zurück auf Anfang und abbrechen
			buf->content = tmp;
			buf->content_size = old_size;

			return CHARBUFFER_ERR_REALLOC_FAILED;
		}
	}

	buf->content[buf->content_len] = c;
	buf->content_len += 1;
	buf->content[buf->content_len] = '\0';

	return SUCCESS;
}

/*
 * Inhalt des CharBuffers auf Console ausgeben
 */
void charbuffer_print(CharBuffer* buf) {
	if(buf == NULL) {
		return;
	}

	if(buf->content == NULL) {
		return;
	}

	if(buf->content[buf->content_len] != '\0') {
		printf("FEHLER: Kein Nullbyte am Ende\n");
		return;
	}

	printf("%s", buf->content);
	// NIEMALS
	// printf(buf->content); // DAS IST GEFÄHRLICH!
}

/*
 * Reservierten Speicher des Charbuffers freigeben
 */
void charbuffer_free(CharBuffer* buf) {
	if(buf == NULL) {
		return;
	}

	if(buf->content != NULL) {
		free(buf->content);
	}

	free(buf);
}
