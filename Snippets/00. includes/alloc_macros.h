#define heap_alloc_sized(type, size) ((type*)malloc(size*sizeof(type)))
#define heap_realloc(type, data, size) data = (type*)realloc(data, size*sizeof(type))