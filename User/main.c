#include "rtdef.h"
#include "rtconfig.h"
#include <rtthread.h>


rt_uint8_t flag1;
rt_uint8_t flag2;

// 定义线程控制模块
struct rt_thread rt_flag1_thread;
struct rt_thread rt_flag2_thread;


ALIGN(RT_ALIGN_SIZE)
// 定义线程栈
rt_uint8_t rt_flag1_thread_stack[512];
rt_uint8_t rt_flag2_thread_stack[512];


int main(void) {
    
    /* 初始化线程 */
    rt_thread_init( &rt_flag1_thread,                /* 线程控制块 */
                    flag1_thread_entry,               /* 线程入口地址 */
                    RT_NULL,                      /* 线程形参 */
                    &rt_flag1_thread_stack[0],  /* 线程栈起始地址 */
                    sizeof(rt_flag1_thread_stack) );  /* 线程栈大小，单位为字节 */

    /* 初始化线程 */
	rt_thread_init( &rt_flag2_thread,                 /* 线程控制块 */
	                flag2_thread_entry,               /* 线程入口地址 */
	                RT_NULL,                          /* 线程形参 */
	                &rt_flag2_thread_stack[0],        /* 线程栈起始地址 */
	                sizeof(rt_flag2_thread_stack) );  /* 线程栈大小，单位为字节 */

}


// soft delay
void delay(rt_uint32_t count) {
    for(; count != 0; count--);
}

// thread 1
void flag1_thread_entry(void *p_arg) {
    for (;;) {
        flag1 = 1;
        delay(100);
        flag1 = 0;
        delay(100);

        // 线程切换，这里是手动切换
        rt_schedule();
    }
}

// thread 2
void flag2_thread_entry(void *p_arg) {
    for (;;) {
        flag2 = 1;
        delay(100);
        flag2 = 0;
        delay(100);

        // 线程切换，这里是手动切换
        rt_schedule();
    }
}