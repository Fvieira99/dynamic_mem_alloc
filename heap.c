#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct dynamic_mem_node {
    uint32_t size;
    bool used;
    struct dynamic_mem_node *next;
    struct dynamic_mem_node *prev;
} dynamic_mem_node_t;

#define NULL_POINTER ((void*) 0)
#define DYNAMIC_MEM_TOTAL_SIZE 4*1024 // 4 means the size of uint8_t
#define DYNAMIC_MEM_NODE_SIZE sizeof(dynamic_mem_node_t) // 16

static uint8_t dynamic_mem_area[DYNAMIC_MEM_TOTAL_SIZE]; // In C array is also a pointer to the first element of the list.
static dynamic_mem_node_t *dynamic_mem_start;

void init_dynamic_mem(){
    dynamic_mem_start = (dynamic_mem_node *) dynamic_mem_area; // This line means that the first element of the array is going to be a pointer of dynamic_mem_node and also will have the same size of it which is 16 bytes.

    dynamic_mem_start->size = DYNAMIC_MEM_TOTAL_SIZE - DYNAMIC_MEM_NODE_SIZE; // The size of the heap is going to be the entire mem size minus the first node size

    dynamic_mem_start->next = NULL_POINTER; //4 bytes not initialized yet
    dynamic_mem_start->prev = NULL_POINTER; //4 bytes not initialized yet 
}

int main(){
    printf("Size of dynamic_mem_node_t in bytes: %zu\n", sizeof(dynamic_mem_node_t));
    printf("Size of pointer in bytes: %zu\n", sizeof(void*));
    
    return 0;

}