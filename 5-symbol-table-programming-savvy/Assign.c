#include <stdarg.h>
#include <malloc.h>
#include <assert.h>

#include "value.r"
#include "value.h"
#include "Var.r"


// static void * mkBin (va_list ap) {
//     struct Bin * node = malloc(sizeof(struct Bin));
// 
//     assert(node);
// 
//     node -> left  = va_arg(ap, void *);
//     node -> right = va_arg(ap, void *);
// 
//     return node;
// }
// 
// static double doAssign (const void * tree) {
//     return value(left(tree)) = exec(right(tree));
// }
// 
// static void freeBin (void * tree) {
//     delete(((struct Bin *) tree) -> left);
//     delete(((struct Bin *) tree) -> right);
//     free(tree);
// }
// 
// 
// static struct Type _Assign = {
//     "",
//     & mkBin,
//     & doAssign,
//     & freeBin
// };
// 
// const void * Assign = & _Assign;

