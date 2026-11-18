#include "ringbuf.h"

/*
 * Ring buffer implementation.
 *
 * Design:
 *   - Storage is provided by the caller (no malloc).
 *   - size must be a power of two, so indices wrap with (i & (size - 1)).
 *   - head and tail count up freely and are only masked when indexing,
 *     so (head - tail) is always the number of stored bytes, even after
 *     the counters overflow.
 *   - Single producer / single consumer: push only writes head,
 *     pop only writes tail.
 *   - Full-buffer policy: TODO decide (reject new byte vs. overwrite oldest)
 *     and document it here.
 *
 * The (void) casts below silence unused-parameter warnings so the stubs
 * compile under -Wall -Wextra -Werror. Remove them as you implement.
 */

bool rb_init(ringbuf_t *rb, uint8_t *storage, size_t size)
{
    // TODO: return false if rb or storage is NULL
    if(rb==NULL || storage==NULL){
        return false;
    }
    // TODO: return false if size is 0 or not a power of two
    //       hint: (size & (size - 1)) == 0 for powers of two
    if(size == 0 || ((size&(size-1))!=0)){
        return false;
    }
    // TODO: set buf, size, head, tail
    rb->buf = storage;
    rb->size = size;
    rb->head = 0;
    rb->tail = 0;
    return true;
}

bool rb_push(ringbuf_t *rb, uint8_t byte)
{
    // TODO: if full, apply your full-buffer policy
    // full buffer policy: ignore on full buffer
    if(rb->head+1 == rb->size){
        return false;
    }
    // TODO: write byte at buf[head & (size - 1)]
    rb[head&(size-1)] = byte
    // TODO: increment head (only AFTER the byte is written)
    head+=1;
    return true;
}

bool rb_pop(ringbuf_t *rb, uint8_t *out)
{
    // TODO: return false if empty
    // TODO: read buf[tail & (size - 1)] into *out
    // TODO: increment tail (only AFTER the byte is read)
    (void)rb;
    (void)out;
    return false;
}

bool rb_peek(const ringbuf_t *rb, uint8_t *out)
{
    // TODO: like pop, but don't move tail
    (void)rb;
    (void)out;
    return false;
}

bool rb_is_empty(const ringbuf_t *rb)
{
    // TODO
    (void)rb;
    return true;
}

bool rb_is_full(const ringbuf_t *rb)
{
    // TODO
    (void)rb;
    return false;
}

size_t rb_count(const ringbuf_t *rb)
{
    // TODO
    (void)rb;
    return 0;
}

void rb_clear(ringbuf_t *rb)
{
    // TODO: reset indices
    // Note: only safe when neither producer nor consumer is running.
    (void)rb;
}