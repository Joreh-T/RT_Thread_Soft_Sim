#ifndef __RT_THREAD_H__
#define __RT_THREAD_H__

#include "rtdef.h"

// initialize
rt_inline void rt_list_init(rt_list_t *l) {
    l->next = l->prev =l;
}

/* 在双向链表头部插入一个节点*/
rt_inline void rt_list_insert_after(rt_list_t *l, rt_list_t *n) {
    l->next->prev = n;
    n->next = l->next;
    l->next = n;
    n->prev = l;
}

rt_inline void rt_list_insert_before(rt_list_t *l, rt_list_t *n) {
    l->prev->next = n;
    n->prev = l->prev;
    l->prev = n;
    n->next = l;
}

rt_inline void rt_list_remove(rt_list_t *n) {
    n->next->prev = n->prev;
    n->prev->next = n->next;
    n->next = n->prev = n;
}

#endif // __RT_THREAD_H__