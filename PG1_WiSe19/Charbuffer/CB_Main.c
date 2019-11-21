#include "charbuffer.h"

int main() {
	CharBuffer* buf = charbuffer_new(100);

	for(int i = 0; i < 1000; i++) {
		charbuffer_append(buf, 'a');
	}

	charbuffer_print(buf);

	charbuffer_free(buf);
}
