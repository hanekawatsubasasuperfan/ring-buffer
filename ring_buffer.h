#ifndef RINGBUF_H
#define RINGBUF_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct {
    uint8_t          *buf;   // caller-provided static array (no malloc)
    size_t            size;  // must be a power of two
    volatile size_t   head;  // written only by the producer
    volatile size_t   tail;  // written only by the consumer
} ringbuf_t;

bool   rb_init(ringbuf_t *rb, uint8_t *storage, size_t size);
bool   rb_push(ringbuf_t *rb, uint8_t byte);
bool   rb_pop(ringbuf_t *rb, uint8_t *out);
bool   rb_peek(const ringbuf_t *rb, uint8_t *out);
bool   rb_is_empty(const ringbuf_t *rb);
bool   rb_is_full(const ringbuf_t *rb);
size_t rb_count(const ringbuf_t *rb);
void   rb_clear(ringbuf_t *rb);

#endif // RINGBUF_H