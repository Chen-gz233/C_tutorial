#ifndef _object_h
//#ifndef是“如果没有被定义”的意思，它会检查是否已经出现过#define _object_h，如果已出现，就跳过这段代码。
//之所以这样写，是因为我们可以将这个文件包含任意次，而无需担心多次定义里面的东西。
#define _object_h
//有了上面保护该文件的#ifndef，我们接着添加_object_h的定义，因此之后任何试图包含此文件的行为，都会由于上面的语句而跳过这段代码。


typedef enum {
    NORTH, SOUTH, EAST, WEST
} Direction;

typedef struct {
    char *description;
    int (*init)(void *self);
    void (*describe)(void *self);
    void (*destroy)(void *self);
    void *(*move)(void *self, Direction direction);
    int (*attack)(void *self, int damage);
} Object;

int Object_init(void *self);
void Object_destroy(void *self);
void Object_describe(void *self);
void *Object_move(void *self, Direction direction);
int Object_attack(void *self, int damage);
void *Object_new(size_t size, Object proto, char *description);

#define NEW(T, N) Object_new(sizeof(T), T##Proto, N)
//这条语句创建了一个宏，就像模板函数一样，无论你在哪里编写左边的代码，都会展开成右边的代码。
//这条语句仅仅是对我们通常调用的Object_new制作了一个快捷方式，并且避免了潜在的调用错误。
//在宏这种工作方式下，T、N还有New都被“注入”进了右边的代码中。
//T##Proto语法表示“将Proto连接到T的末尾”，所以如果你写下NEW(Room, "Hello.")，就会在这里变成RoomProto

#define _(N) proto.N
//这个宏是一种为对象系统设计的“语法糖”，将obj->proto.blah简写为obj->_(blah)。
//它不是必需的，但是它是一个接下来会用到的有趣的小技巧。
#endif