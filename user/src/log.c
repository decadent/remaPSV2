#include <vitasdk.h>
#include <taihen.h>
#include <stdio.h>
#include "log.h"
#include <psp2/io/fcntl.h> 

int ksceIoMkdir(const char *, int);

//#ifndef RELEASE
static unsigned int log_buf_ptr = 0;
static char log_buf[16 * 1024];
//#endif

void log_assert(const char *name, int flag){
	if (flag){
		log_write(name, strlen(name));
		log_flush();
	}
}

void log_reset(){
//#ifndef RELEASE
	SceUID fd = sceIoOpen(LOG_FILE,
		SCE_O_WRONLY | SCE_O_CREAT | SCE_O_TRUNC, 6);
	if (fd < 0)
		return;

	sceIoClose(fd);

	memset(log_buf, 0, sizeof(log_buf));
//#endif
}

void log_write(const char *buffer, size_t length){
//#ifndef DEBUG
	if ((log_buf_ptr + length) >= sizeof(log_buf))
		return;

	memcpy(log_buf + log_buf_ptr, buffer, length);

	log_buf_ptr = log_buf_ptr + length;
//#endif
}

void log_flush(){
//#ifndef RELEASE
	sceIoMkdir(LOG_PATH, 6);

	SceUID fd = sceIoOpen(LOG_FILE,
		SCE_O_WRONLY | SCE_O_CREAT | SCE_O_APPEND, 6);
	if (fd < 0)
		return;

	sceIoWrite(fd, log_buf, strlen(log_buf));
	sceIoClose(fd);
	memset(log_buf, 0, sizeof(log_buf));
	log_buf_ptr = 0;
//#endif
}