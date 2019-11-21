#include "charbuffer.h"
#include <stdio.h>
#include <string.h>

#define SUCCESS 0
#define ERROR 1

int test_charbuffer_new() {
	int INITIAL_SIZE = 100;
	CharBuffer* buf = charbuffer_new(INITIAL_SIZE);

	if(buf == NULL) {
		printf("buf == NULL\n");
	       	return ERROR;
	}
	if(buf->content_size != INITIAL_SIZE) {
		printf("buf->content_size != INITIAL_SIZE\n");
	       	return ERROR;
	}
	if(buf->content == NULL) {
		printf("buf->content == NULL\n");
	       	return ERROR;
	}
	if(buf->content_len != 0) {
		printf("buf->content_len != 0\n");
	       	return ERROR;
	}

	return SUCCESS;
}

int test_charbuffer_append() {
	CharBuffer *buf = charbuffer_new(10);

	charbuffer_append(buf, 'a');
	charbuffer_append(buf, 'b');
	charbuffer_append(buf, 'c');

	if(strcmp(buf->content, "abc") != 0) {
		printf("test_charbuffer_append: invalid content\n");
		return ERROR;
	}

	for(int i = 0; i < 1000; i++) {
		int rc = charbuffer_append(buf, 'z');
		if(rc != SUCCESS) {
			printf("test_charbuffer_append: Abbruch mit Fehlercode %d\n", rc);
			return ERROR;
		}
	}

	if(buf->content_len != 1003) {
		printf("test_charbuffer_append: Falsche Anzahl an Zeichen %d\n", buf->content_len);
		return ERROR;
	}

	charbuffer_free(buf);
	return SUCCESS;
}

int test_charbuffer_print() {
	CharBuffer *buf = charbuffer_new(10);

	charbuffer_append(buf, 'a');
	charbuffer_append(buf, 'a');
	charbuffer_append(buf, 'a');

	charbuffer_print(buf);

	charbuffer_free(buf);
}

int test_charbuffer_free() {
	CharBuffer *buf = charbuffer_new(100);

	if(buf == NULL) {
		printf("test_charbuffer_free: buf unerwartet NULL\n");
		return ERROR;
	}

	charbuffer_free(buf);

	charbuffer_free(NULL);

	return SUCCESS;
}

int main() {
	int rc = SUCCESS;

	rc = rc || test_charbuffer_new();
	rc = rc || test_charbuffer_append();
	rc = rc || test_charbuffer_print();
	rc = rc || test_charbuffer_free();

	return rc;
}
