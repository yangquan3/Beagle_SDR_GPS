#ifndef _MISC_H_
#define _MISC_H_

#include "types.h"
#include "kiwi.h"
#include "printf.h"

#define MALLOC_DEBUG
#ifdef MALLOC_DEBUG
	void *kiwi_malloc(const char *from, size_t size);
	void kiwi_free(const char *from, void *ptr);
	char *kiwi_strdup(const char *from, const char *s);
	void kiwi_str_redup(char **ptr, const char *from, const char *s);
	int kiwi_malloc_stat();
#else
	#define kiwi_malloc(from, size) malloc(size)
	#define kiwi_free(from, ptr) free(ptr)
	#define kiwi_strdup(from, s) strdup(s)
	void kiwi_str_redup(char **ptr, const char *from, const char *s);
	#define kiwi_malloc_stat() 0
#endif

// strings
#define GET_CHARS(field, value) get_chars(field, value, sizeof(field));
void get_chars(char *field, char *value, size_t size);
#define SET_CHARS(field, value, fill) set_chars(field, value, fill, sizeof(field));
void set_chars(char *field, const char *value, const char fill, size_t size);
int split(char *cp, int *argc, char *argv[], int nargs);
int str2enum(const char *s, const char *strs[], int len);
const char *enum2str(int e, const char *strs[], int len);

#ifdef CLIENT_SIDE
 #define timer_ms() 0
#else
 u4_t timer_ms(void);
 u4_t timer_us(void);
#endif

u2_t ctrl_get();
void ctrl_clr_set(u2_t clr, u2_t set);
u2_t getmem(u2_t addr);
int non_blocking_popen(const char *cmd, char *reply, int reply_size);
void printmem(const char *str, u2_t addr);

#define SM_DEBUG	true
#define SM_NO_DEBUG	false
void send_msg(conn_t *c, bool debug, const char *msg, ...);
void send_msg_mc(struct mg_connection *mc, bool debug, const char *msg, ...);

// DEPRECATED: still in WSPR code
void send_meta(conn_t *c, u1_t cmd, u4_t p1, u4_t p2);
void send_meta_mc(struct mg_connection *mc, u1_t cmd, u4_t p1, u4_t p2);
void send_meta_bytes(conn_t *c, u1_t cmd, u1_t *bytes, int nbytes);

float ecpu_use();

#endif